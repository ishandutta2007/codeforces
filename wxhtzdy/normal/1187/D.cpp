#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      --b[i];
    }
    if (multiset<int>(a.begin(), a.end()) != multiset<int>(b.begin(), b.end())) {
      cout << "NO" << '\n';
      continue;
    }
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; i++) {
      pos[a[i]].push_back(i);
    }
    vector<int> p(n);
    for (int i = n - 1; i >= 0; i--) {
      int x = pos[b[i]].back();
      pos[b[i]].pop_back();
      p[x] = i;
    }
    vector<int> fenw(n + 1);
    function<void(int, int)> update = [&](int i, int v) {
      for (i += 1; i <= n; i += i & -i) {
        fenw[i] = max(fenw[i], v);
      }
    };
    auto query = [&](int i) {
      int res = 0;
      for (i += 1; i >= 1; i -= i & -i) {
        res = max(res, fenw[i]);
      }
      return res;
    };
    bool ok = true;
    for (int i = 0; i < n; i++) {
      ok &= (query(a[i]) <= p[i]);
      update(a[i], p[i]);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}