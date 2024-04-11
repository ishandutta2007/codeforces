#include<cstdio>

int main()
{
  int n, s[1024], p[] = {1, 10, 100, 1000, 10000};
  scanf("%d", &n);
  s[0] = 0;
  for(int i=1; i<=n; ++i) {
    int k;
    scanf("%d", &k);
    s[i] = -1;
    for(int j=0; j<4; ++j) {
      for(int d=0; d<=9; ++d) {
	int t = k-(k/p[j]*p[j]%p[j+1])+d*p[j];
	if(t >= s[i-1] && t >= 1000 && t <= 2011)
	  if(s[i] > t || s[i]==-1) s[i]=t;
      }
    }
  }
  for(int i=1; i<=n; ++i)
    if(s[i]==-1) { puts("No solution"); return 0; }
  for(int i=1; i<=n; ++i)
    printf("%d\n", s[i]);
  return 0;
}