#include<cstdio>

int main()
{
  int n, s=0, p[3333] = {0};
  scanf("%d", &n);
  for(int i=2; i<=n; ++i) {
    p[i] = 1;
    for(int j=2; j*j<=i; ++j)
      if(i%j == 0) p[i] = 0;
  }
  for(int i=1; i<=n; ++i) {
    int d = 0;
    for(int j=1; j<=n; ++j)
      if(p[j] && i%j==0) d++;
    if(d==2) s++;
  }
  printf("%d\n", s);
  return 0;
}