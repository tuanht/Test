#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AUTHOR "Tuan Ha"

/* sss */

void swap_char (char *chr1, char *chr2)
{
  char tmp = *chr1;
  *chr1 = *chr2;
  *chr2 = tmp;
}

void reverse_string (char *str, int from, int to)
{
  while (from < to) swap_char (&(str[from++]), &(str[to--]));
}

char * reverse_word (const char *str)
{
  int from, to;
  int length = strlen (str);
  
  char *buffer = (char*) calloc (length + 1, sizeof (char));
  strcpy (buffer, str);
  
  // Reverse entire the string
  reverse_string (buffer, 0, length - 1);
  
  // Then, reverse again for each words
  for (from = 0, to = 0; to <= length; to++)
  {
    if (buffer[to] == ' ' || buffer[to] == '\0')
    {
      // Don't reverse if word has only one-character
      if (from != to - 1) reverse_string (buffer, from, to - 1);
      from = to + 1;
    }
  }
  
  return buffer;
}

int main (int argc, char **argv)
{
  printf ("%s\n", reverse_word ("student am I"));
  
  return 0;
}
