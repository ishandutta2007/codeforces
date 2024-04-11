#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, M, f[2004][2004];
vector<int> tr[2004];
int s[2004], pr[2004], sf[2004], ad[2004];
int ans[2004], C[2004][2004];
void dfs(int u, int fa) {
  for (auto v : tr[u])
    if (v != fa) dfs(v, u);
  vector<int> vec;
  for (auto v : tr[u])
    if (v != fa) vec.push_back(v);
  int m = vec.size();
  memset(s, 0, sizeof(s));
  memset(ad, 0, sizeof(ad));
  if (u > 1) {
    for (int t = 0; t <= n; t++) {
      int mul = 1, pre = 1, suf = 1;
      for (int i = 0; i < m; i++) (s[i] += f[vec[i]][t]) %= M;
      for (int i = 0; i < m; i++) pre = (ll)pre * s[i] % M, pr[i] = pre;
      for (int i = m - 1; ~i; i--) suf = (ll)suf * s[i] % M, sf[i] = suf;
      (f[u][t] += pre) %= M;
      for (int i = 0; i < m; i++) {
        (f[u][t] += (ll)f[vec[i]][t] * ad[i] % M) %= M;
        int bf = i < 1 ? 1 : pr[i - 1], af = i < m - 1 ? sf[i + 1] : 1;
        (ad[i] += (ll)bf * af % M) %= M;
      }
    }
  } else {
    for (int t = 0; t <= n; t++) {
      int mul = 1;
      for (int i = 0; i < m; i++) {
        (s[i] += f[vec[i]][t]) %= M;
        mul = (ll)mul * s[i] % M;
      }
      ans[t] = mul;
    }
  }
}
int main() {
  scanf("%d%d", &n, &M);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    tr[u].push_back(v), tr[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 0; i <= n; C[i][0] = 1, i++)
    for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
  for (int i = 1; i < n; i++) {
    int res = 0;
    for (int j = 0; j < i; j++) {
      if (j & 1)
        (res += M - (ll)ans[i - j - 1] * C[i][j] % M) %= M;
      else
        (res += (ll)ans[i - j - 1] * C[i][j] % M) %= M;
    }
    printf("%d ", res);
  }
}