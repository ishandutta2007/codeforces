/**
 *    author:  tourist
 *    created: 25.08.2019 17:46:19       
**/
#include <bits/stdc++.h>

using namespace std;

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
  int cnt, w;
  cin >> cnt >> w;
  vector<long long> res(w + 1);
  while (cnt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    SparseTable<int> st(a, [&](int i, int j) { return max(i, j); });
    for (int i = 0; i < w; i++) {
      int from = max(i - (w - n), 0);
      int to = min(i, n - 1);
      int cur = st.get(from, to);
      if (cur < 0 && (i >= n || i < w - n)) {
        cur = 0;
      }
      res[i] += cur;
      if (from == 0 && to == n - 1 && i >= n && w >= 2 * n + 1) {
        i = max(i, w - n - 1);
      }
      res[i + 1] -= cur;
    }
  }
  for (int i = 0; i < w; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << res[i];
    res[i + 1] += res[i];
  }
  cout << '\n';
  return 0;
}