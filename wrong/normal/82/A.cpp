#include<cstdio>

char *S[] = {"Sheldon","Leonard","Penny","Rajesh","Howard"};
int main()
{
  int n;
  scanf("%d", &n);
  long long t = 1;
  while(n > 5*t) {
    n -= 5*t;
    t <<= 1;
  }
  puts(S[(n-1)/t]);
  return 0;
}