#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), p(n), ord(n);
  vector<vector<int>> pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
    ord[i] = i;
    pos[a[i]].push_back(i);
  }
  sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
  for (int i = 0; i < n; ++i) cin >> p[i];
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    b[i]--;
  }

  constexpr int64_t kInf = 1'000'000'000'000'000'000;
  vector<int64_t> dp(n, kInf);
  vector<int64_t> tree(n * 4, kInf), tag(n * 4, 0);
  vector<int64_t> fw(n + 1, 0);

  auto Modify = [&](int ql, int qr, int64_t v) {
    auto ModifyImpl = [&](auto self, int l, int r, int o = 0) {
      if (l >= qr || ql >= r) return;
      if (l >= ql && r <= qr) {
        tree[o] += v;
        tag[o] += v;
        return;
      }
      for (int k = 1; k <= 2; ++k) {
        tree[o * 2 + k] += tag[o];
        tag[o * 2 + k] += tag[o];
      }
      tag[o] = 0;
      int m = (l + r) >> 1;
      self(self, l, m, o * 2 + 1);
      self(self, m, r, o * 2 + 2);
      tree[o] = min(tree[o * 2 + 1], tree[o * 2 + 2]);
    };
    ModifyImpl(ModifyImpl, 0, n);
  };

  auto Query = [&](int ql, int qr) {
    auto QueryImpl = [&](auto self, int l, int r, int o = 0) {
      if (l >= qr || ql >= r) return kInf;
      if (l >= ql && r <= qr) return tree[o];
      for (int k = 1; k <= 2; ++k) {
        tree[o * 2 + k] += tag[o];
        tag[o * 2 + k] += tag[o];
      }
      tag[o] = 0;
      int m = (l + r) >> 1;
      return min(self(self, l, m, o * 2 + 1),
                 self(self, m, r, o * 2 + 2));
    };
    return QueryImpl(QueryImpl, 0, n);
  };

  auto ModifyFenw = [&](int p, int v) {
    for (int i = p + 1; i <= n; i += i & -i) {
      fw[i] += v;
    }
  };

  auto QueryFenw = [&](int p) {
    int64_t res = 0;
    for (int i = p + 1; i > 0; i -= i & -i) {
      res += fw[i];
    }
    return res;
  };

  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[0]) dp[i] = sum;
    sum += p[i];
  }

  if (pos[b[0]].empty()) {
    cout << "NO\n";
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    Modify(0, i, p[i]);
    ModifyFenw(i, p[i]);
  }

  int j = 0;
  for (int i = 1; i < m; ++i) {
    while (j < n && a[ord[j]] <= b[i - 1]) {
      // cerr << "Erase " << ord[j] << endl;
      if (p[ord[j]] > 0) {
        Modify(0, ord[j], -p[ord[j]]);
        ModifyFenw(ord[j], -p[ord[j]]);
      }
      j++;
    }
    if (pos[b[i]].empty()) {
      cout << "NO\n";
      return 0;
    }
    for (int u : pos[b[i - 1]]) {
      Modify(u, u + 1, dp[u] - kInf);
    }
    for (int u : pos[b[i]]) {
      int64_t s = QueryFenw(n - 1) - QueryFenw(u - 1);
      int64_t v = Query(0, u) - s;
      // cout << "prv = ";
      // for (int p : pos[b[i - 1]]) cout << Query(p, p + 1) << " ";
      // cout << endl;
      // cout << "s = " << s << " v = " << v + s << endl;
      dp[u] = v;
    }
    for (int u : pos[b[i - 1]]) {
      Modify(u, u + 1, kInf - dp[u]);
    }
  }
  fill(fw.begin(), fw.end(), 0);
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[m - 1] || p[i] < 0) {
      ModifyFenw(i, p[i]);
    }
  }
  int64_t res = kInf;
  for (int u : pos[b[m - 1]]) {
    res = min(res, dp[u] + QueryFenw(n - 1) - QueryFenw(u));
  }
  if (res >= kInf / 2) cout << "NO\n";
  else cout << "YES\n" << res << "\n";
  return 0;
}