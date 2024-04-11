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
  const int MAX = 1e6 + 5;
  vector<vector<int>> d(MAX);
  for (int i = 2; i < MAX; i++) {
    if (d[i].empty()) {
      for (int j = i; j < MAX; j += i) {
        d[j].push_back(i);
      }
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  vector<vector<int>> stk(MAX);
  vector<int> prv(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      prv[i] = i;
      for (int j : d[a[i]]) {
        int x = a[i];
        while (x % j == 0) {
          stk[j].push_back(i);
          x /= j;
        }
      }
    } else {
      prv[i] = i;
      for (int j : d[a[i]]) {
        int x = a[i];
        while (x % j == 0) {
          if (stk[j].empty()) {
            prv[i] = -1;
          } else {
            prv[i] = min(prv[i], stk[j].back());
            stk[j].pop_back();
          }
          x /= j;
        }
      }
    }
  }
  SparseTable<int> st(prv, [&](int i, int j) { return min(i, j); });
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int low = i, high = n - 1, pos = i - 1;
    while (low <= high) {
      int mid = low + high >> 1;
      if (st.get(i, mid) >= i) {
        pos = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    ans += (pos - i + 1);
  }
  cout << ans << '\n';
  return 0;
}