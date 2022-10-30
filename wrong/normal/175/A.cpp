#include<cstdio>
#include<cstring>

int valid(char *p, int n)
{
  if(n <= 0) return -1;
  if(n == 1 && p[0] == '0')
    return 0;
  if(p[0] == '0') return -1;
  int res = 0;
  for(int i=0; i<n; ++i) {
    res = 10 * res + p[i] - '0';
    if(res > 1000000)
      return -1;
  }
  return res;
}

int main()
{
  char s[32];
  scanf("%s", s);
  int n = strlen(s), r = -1;
  for(int i=1; i<n; ++i) {
    for(int j=i+1; j<n; ++j) {
      int a = valid(s, i);
      int b = valid(s+i, j-i);
      int c = valid(s+j, n-j);
      if(a>=0 && b>=0 && c>=0 && r<a+b+c)
	r = a+b+c;
    }
  }
  printf("%d\n", r);
  return 0;
}