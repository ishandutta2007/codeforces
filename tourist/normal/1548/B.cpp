/**
 *    author:  tourist
 *    created: 01.08.2021 17:38:51       
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }
    vector<long long> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
      b[i] = abs(a[i] - a[i + 1]);
    }
    SparseTable<long long> st(b, [&](long long i, long long j) { return __gcd(i, j); });
    int j = -1;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      while (j + 1 < n - 1 && st.get(i, j + 1) > 1) {
        ++j;
      }
      if (i <= j) {
        ans = max(ans, j - i + 1);
      }
      j = max(j, i);
    }
    cout << ans + 1 << '\n';
  }
  return 0;
}