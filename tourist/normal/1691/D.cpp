/**
 *    author:  tourist
 *    created: 31.05.2022 18:35:43       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    vector<int> b(n);
    iota(b.begin(), b.end(), 0);
    SparseTable<int> sa(b, [&](int i, int j) { return a[i] > a[j] ? i : j; });
    SparseTable<long long> smin(pref, [&](long long i, long long j) { return min(i, j); });
    SparseTable<long long> smax(pref, [&](long long i, long long j) { return max(i, j); });
    bool ok = true;
    function<void(int, int)> Dfs = [&](int l, int r) {
      if (l > r) {
        return;
      }
      int x = sa.get(l, r);
      long long mn = smin.get(l, x);
      long long mx = smax.get(x + 1, r + 1);
      if (a[x] < mx - mn) {
        ok = false;
      }
      Dfs(l, x - 1);
      Dfs(x + 1, r);
    };
    Dfs(0, n - 1);
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}