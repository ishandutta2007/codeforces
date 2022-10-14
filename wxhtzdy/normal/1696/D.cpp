/**
 *    author:  wxhtzdy
 *    created: 26.06.2022 18:49:58
**/
#include <bits/stdc++.h>

using namespace std;

// usage:
//   auto fun = [&](int i, int j) { return min(i, j); };
//   SparseTable<int, decltype(fun)> st(a, fun);
// or:
//   SparseTable<int> st(a, [&](int i, int j) { return min(i, j); });
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    vector<int> b(n);
    iota(b.begin(), b.end(), 0);
    SparseTable<int> sa(b, [&](int i, int j) { return a[i] < a[j] ? i : j; });
    SparseTable<int> sb(b, [&](int i, int j) { return a[i] > a[j] ? i : j; });
    function<int(int, int)> Dfs = [&](int l, int r) {
      if (l == r) {
        return 0;
      }   
      int mn = sa.get(l, r);
      int mx = sb.get(l, r);
      if (l < mn && mn < r) {
        return 1 + Dfs(l, mn) + Dfs(mn, r);
      }    
      if (l < mx && mx < r) {
        return 1 + Dfs(l, mx) + Dfs(mx, r);
      }
      return 0;
    };
    cout << Dfs(0, n - 1) + 1 << '\n';
  }                                                                    
  return 0;
}