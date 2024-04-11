#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> p(n), nxt(n, -1);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < n; ++i) nxt[p[i]] = p[(i + 1) % n];
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    a[i]--;
  }
  vector<int> last(n, -1);
  vector<vector<int>> fa(m);
  vector<int> dep(m);
  vector<int> to(m, m + 1);
  for (int i = m - 1; i >= 0; --i) {
    if (last[nxt[a[i]]] == -1) {
      dep[i] = 0;
      fa[i].push_back(-1);
    } else {
      fa[i].push_back(last[nxt[a[i]]]);
      dep[i] = dep[last[nxt[a[i]]]] + 1;
      for (int j = 1; (1 << j) <= dep[i]; ++j) {
        fa[i].push_back(fa[fa[i][j - 1]][j - 1]);
      }
    }
    last[a[i]] = i;
    if (dep[i] < n - 1) continue;
    int t = i;
    for (int j = 0; j < fa[t].size(); ++j) {
      if ((n - 1) >> j & 1) t = fa[t][j];
    }
    to[i] = t;
  }
  vector<vector<int>> sp(1, vector<int>(m));
  for (int i = 0; i < m; ++i) sp[0][i] = to[i];
  for (int i = 1; (1 << i) <= m; ++i) {
    sp.emplace_back(m);
    for (int j = 0; j + (1 << i) <= m; ++j) {
      sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
    }
  }
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int p = 31 - __builtin_clz(r - l + 1);
    int res = min(sp[p][l], sp[p][r - (1 << p) + 1]);
    if (res <= r) cout << "1";
    else cout << "0";
  }
  cout << "\n";
}