#include<cstdio>
#include<algorithm>

int U[1<<20];
void init(int n) { for(int i=0; i<n; ++i) U[i]=i; }
int find(int x) { if(U[x]!=x) U[x]=find(U[x]); return U[x]; }
void uni(int x, int y) { U[find(x)] = find(y); }

int M[1<<22];
int go(int n, int m, int y, int d)
{
  m = (m-1)%(2*n-2);
  if(d == 1) {
    return M[y+m];
  } else {
    return M[2*n-2-y+m];
  }
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  if(n>m) std::swap(n, m);
  init(n);
  M[0] = 0;
  int d = 1;
  for(int i=1; i<1<<22; ++i) {
    M[i] = M[i-1] + d;
    if(M[i] >= n) { d=-d; M[i]+=2*d; }
    if(M[i] <  0) { d=-d; M[i]+=2*d; }
  }
  for(int i=0; i<n; ++i) {
    int up = go(n, m, i, 1), dw = go(n, m, i, -1);
    uni(i, go(n, m, up, 1)); uni(i, go(n, m, up, -1));
    uni(i, go(n, m, dw, 1)); uni(i, go(n, m, dw, -1));
  }
  int s = 0;
  for(int i=0; i<n; ++i)
    if(U[i]==i) s++;
  printf("%d\n", s);
  return 0;
}