#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> sp(1, vector<int>(a.begin(), a.end()));
  for (int i = 1; (1 << i) <= n; ++i) {
    sp.emplace_back(n);
    for (int j = 0; j + (1 << i) <= n; ++j) {
      sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
    }
  }

  auto Query = [&](int l, int r) {
    int p = 31 - __builtin_clz(r - l + 1);
    return max(sp[p][l], sp[p][r - (1 << p) + 1]);
  };

  vector<int> l(q + 1), r(q + 1);
  vector<vector<double>> p(q + 1);
  for (int i = 0; i < q; ++i) {
    double prob;
    cin >> l[i] >> r[i] >> prob;
    l[i]--, r[i]--;
    p[i].push_back(prob);
  }
  l[q] = 0;
  r[q] = n - 1;
  p[q] = {0};
  q++;
  vector<int> fa(q, -1);
  vector<bool> del(q);
  for (int i = 0; i < q; ++i) {
    if (del[i]) continue;
    for (int j = 0; j < q; ++j) {
      if (j == i) continue;
      if (del[j]) continue;
      if (l[j] == l[i] && r[j] == r[i]) {
        del[j] = true;
        p[i].insert(p[i].end(), p[j].begin(), p[j].end());
      } else if (l[j] <= l[i] && r[j] >= r[i]) {
        if (fa[i] == -1) fa[i] = j;
        else if (r[j] - l[j] < r[fa[i]] - l[fa[i]]) fa[i] = j;
      }
    }
  }
  vector<vector<int>> g(q);
  for (int i = 0; i < q; ++i) {
    if (del[i]) continue;
    if (fa[i] >= 0) g[fa[i]].push_back(i);
  }
  int root = 0;
  for (int i = 0; i < q; ++i) {
    if (del[i]) continue;
    if (fa[i] == -1) root = i;
  }

  vector<vector<double>> dp(q, vector<double>(q + 1));
  vector<int> vf(q);

  function<void(int)> Dfs = [&](int x) {
    vf[x] = Query(l[x], r[x]);
    int k = p[x].size();
    vector<double> ch(k + 1);
    ch[0] = 1.0;
    for (int i = 0; i < k; ++i) {
      vector<double> nxt(k + 1);
      for (int j = 0; j <= k; ++j) {
        nxt[j] += ch[j] * (1.0 - p[x][i]);
        if (j > 0) nxt[j] += ch[j - 1] * p[x][i];
      }
      ch = nxt;
    }
    vector<double> pd(q + 1, 1.0);
    for (int u : g[x]) {
      Dfs(u);
      vector<double> nxt(q + 1);
      for (int j = 0; j <= q; ++j) {
        int t = vf[x] - vf[u] + j;
        pd[j] *= (t < 0 ? 0.0 : dp[u][min(t, q)]);
      }
    }
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j <= q; ++j) {
        if (i + j <= q) dp[x][i + j] += pd[j] * ch[i];
      }
    }
  };

  Dfs(root);
  double ans = 0.0;
  for (int i = 0; i <= q; ++i) {
    double prob = dp[root][i];
    if (i > 0) prob -= dp[root][i - 1];
    ans += prob * (vf[root] + i);
  }
  cout << fixed << setprecision(20) << ans << "\n";
}