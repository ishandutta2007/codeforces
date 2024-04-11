#include<cstdio>
#include<cstring>

int n, m, k, d, v, c[256], memo[256][51];
char s[256];

int get(int t, int p)
{
  if(memo[t][p] >= -1)
    return memo[t][p];
  if(t >= v) return memo[t][p] = -1;
  int m = c[t], nm = c[t+1];
  if(s[t] == '0') {
    int x = t;
    for(int y=p-1; y<=p+1; ++y) {
      if(y<0 || y>=n) continue;
      if(m==y || nm==y) continue;
      int z = get(t+1, y);
      if(z == -1) return memo[t][p] = -1;
      if(x < z) x = z;
    }
    return memo[t][p] = x;
  } else {
    int x = t;
    for(int y=0; y<n; ++y) {
      if(nm==y) continue;
      int z = get(t+1, y);
      if(z == -1) return memo[t][p] = -1;
      if(x < z) x = z;
    }
    return memo[t][p] = x;
  }
}

int main()
{
  char t[32];
  scanf("%d%d%d%s", &n, &m, &k, t);
  scanf("%s%s", t, s);
  if(t[0]=='h') d = -1; else d = 1;
  m--; k--;
  c[0] = k;
  for(int i=1; i<=200; ++i) {
    if(c[i-1] == n-1) d = -1;
    if(c[i-1] == 0) d = 1;
    c[i] = c[i-1] + d;
  }
  v = strlen(s);
  for(int i=0; i<=200; ++i)
    for(int j=0; j<=n; ++j)
      memo[i][j] = -2;
  int x = get(0, m);
  if(x == -1) {
    puts("Stowaway");
  } else {
    printf("Controller %d\n", x+1);
  }
  return 0;
}