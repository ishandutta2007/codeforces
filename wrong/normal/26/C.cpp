#include<cstdio>

int main()
{
  char S[111][111];
  int n, m, a, b, c;
  scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
  if(n%2 && m%2) { puts("IMPOSSIBLE"); return 0; }
  for(int y=0; y+1<n; y+=2) {
    for(int x=0; x+1<m; x+=2) {
      if(c > 0) { S[y][x]=S[y][x+1]=S[y+1][x]=S[y+1][x+1]='a'+(x+y)/2%2; c--; }
      else if(b > 1 && (a<2 || n%2==1 || n%2+m%2==0)) { S[y][x]=S[y+1][x]='c'+(x+y)/2%2; S[y][x+1]=S[y+1][x+1]='e'+(x+y)/2%2; b-=2; }
      else if(a > 1 && (b<2 || m%2==1 || n%2+m%2==0)) { S[y][x]=S[y][x+1]='g'+(x+y)/2%2; S[y+1][x]=S[y+1][x+1]='i'+(x+y)/2%2; a-=2; }
      else { puts("IMPOSSIBLE"); return 0; }
    }
  }
  if(n%2) {
    if(m/2>a) { puts("IMPOSSIBLE"); return 0; }
    for(int x=0; x+1<m; x+=2) S[n-1][x]=S[n-1][x+1]='x'+x/2%2;
  }
  if(m%2) {
    if(n/2>b) { puts("IMPOSSIBLE"); return 0; }
    for(int y=0; y+1<n; y+=2) S[y][m-1]=S[y+1][m-1]='x'+y/2%2;
  }
  for(int y=0; y<n; ++y) {
    S[y][m] = 0;
    puts(S[y]);
  }
  return 0;
}