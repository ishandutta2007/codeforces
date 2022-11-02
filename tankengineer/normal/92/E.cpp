#include<cstdio>
const int mod = 1000000009;

int n, m, fa[100005], u, v, ans;

int find(const int i) {return fa[i] == i ? i : fa[i] = find(fa[i]);}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  ans = 1;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    u = find(u); v = find(v);
    if (u == v) {ans <<= 1; if (ans >= mod) ans -= mod;} else fa[u] = v;
    printf("%d\n", ans - 1);
  }
  return 0;
}