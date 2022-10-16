#include <bits/stdc++.h>

using namespace std;

#define eprintf( ... ) fprintf(stderr, __VA_ARGS__)

const int maxn = 4005;

int n, m, u, tot = 0;
int siz[maxn], a[maxn], b[maxn];
int ch[maxn][2];
long long f[maxn][maxn];

inline int build(int l, int r, int sub){
  if(l > r)
    return 0;
  int u = ++tot;
  int ptr = -1;
  for(int i = l; i <= r; ++i)
    if(!~ptr || a[i] < a[ptr])
      ptr = i;
  siz[u] = 1;
  int p, q;
  p = ch[u][0] = build(l, ptr - 1, a[ptr]); siz[u] += siz[p];
  q = ch[u][1] = build(ptr + 1, r, a[ptr]); siz[u] += siz[q];
  a[ptr] -= sub, b[u] = a[ptr];

  for(int i = 0; i <= siz[u]; ++i){
    // choose i
    for(int j = max(0, i - 1 - siz[q]); j <= min(i - 1, siz[p]); ++j){
      int k = i - 1 - j;
      long long res = f[p][j] + f[q][k];
      f[u][i] = max(f[u][i], res);
    }
    // don't choose i
    for(int j = max(0, i - siz[q]); j <= min(i, siz[p]); ++j){
      int k = i - j;
      long long res = f[p][j] + f[q][k];
      f[u][i] = max(f[u][i], res);
    }
    if(u)
      f[u][i] += 1ll * i * (m - i) * a[ptr];
  }
  return u;
}

int main(){
  //freopen("D.in", "r", stdin);
  
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  int rt = build(0, n - 1, 0);
  printf("%lld\n", f[rt][m]);
  return 0;
}