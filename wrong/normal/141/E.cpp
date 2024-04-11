#include<cstdio>

int U[1024];
void init(int n) { for(int i=0; i<n; ++i) U[i] = i; }
int find(int x) {
  if(U[x] != x) U[x] = find(U[x]);
  return U[x];
}
void uni(int x, int y) { U[find(x)] = find(y); }

int sx[100000], sy[100000], si[100000], su[100000];
int mx[100000], my[100000], mi[100000], mu[100000];

int main()
{
  int n, m, S = 0, M = 0;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; ++i) {
    int x, y;
    char t[2];
    scanf("%d%d%s", &x, &y, t);
    x--; y--;
    if(t[0] == 'S' && x!=y) { sx[S]=x; sy[S]=y; si[S]=i+1; S++; }
    if(t[0] == 'M' && x!=y) { mx[M]=x; my[M]=y; mi[M]=i+1; M++; }
  }
  if(n % 2 == 0 || S+M < n-1 || S < (n-1)/2 || M < (n-1)/2) { puts("-1");  return 0;}
  init(n);
  for(int i=0; i<S; ++i) uni(sx[i], sy[i]);
  int used[1024], X=0;
  for(int i=0; X<(n-1)/2 && i<M; ++i) {
    if(find(mx[i]) != find(my[i])) {
      uni(mx[i], my[i]);
      used[X++] = mi[i];
      mu[i] = 1;
    }
  }
  init(n);
  for(int i=0; i<M; ++i)
    if(mu[i]) uni(mx[i], my[i]);
  for(int i=0; X<(n-1)/2 && i<M; ++i) {
    if(mu[i]) continue;
    if(find(mx[i]) != find(my[i])) {
      uni(mx[i], my[i]);
      used[X++] = mi[i];
      mu[i] = 1;
    }
  }
  if(X < (n-1)/2) {puts("-1"); return 0;}
  for(int i=0; i<S; ++i) {
    if(find(sx[i]) != find(sy[i])) {
      uni(sx[i], sy[i]);
      used[X++] = si[i];
      su[i] = 1;
    }
  }
  if(X < n-1) { puts("-1"); return 0; }
  printf("%d\n", n-1);
  for(int i=0; i<n-1; ++i) printf("%d%c", used[i], i==n-2?'\n':' ');
  return 0;
}