#include<cstdio>

int main()
{
  int n;
  scanf("%d", &n);
  if(n == 1) puts("a\na\nb\nb");
  else if(n%2 == 0) {
    for(int i=0; i<n/2; ++i)
      printf("%c%c", 'a'+(i%13), 'a'+(i%13));
    printf("\n%c", 'a'+13);
    for(int i=0; i<n/2-1; ++i)
      printf("%c%c", 'a'+15+(i%11), 'a'+15+(i%11));
    printf("%c", 'a'+14);
    printf("\n%c", 'a'+13);
    for(int i=0; i<n/2-1; ++i)
      printf("%c%c", 'a'+(i%13), 'a'+(i%13));
    printf("%c\n", 'a'+14);
    for(int i=0; i<n/2; ++i)
      printf("%c%c", 'a'+15+(i%11), 'a'+15+(i%11));
  } else {
    for(int i=0; i<n/2; ++i)
      printf("%c%c", 'a'+(i%13), 'a'+(i%13));
    printf("%c\n", 'a'+13);
    for(int i=0; i<n/2; ++i)
      printf("%c%c", 'a'+15+(i%11), 'a'+15+(i%11));
    printf("%c\n", 'a'+13);
    printf("%c", 'a'+14);
    for(int i=0; i<n/2; ++i)
      printf("%c%c", 'a'+(i%13), 'a'+(i%13));
    printf("\n%c", 'a'+14);
    for(int i=0; i<n/2; ++i)
      printf("%c%c", 'a'+15+(i%11), 'a'+15+(i%11));
    puts("");
  }
  return 0;
}