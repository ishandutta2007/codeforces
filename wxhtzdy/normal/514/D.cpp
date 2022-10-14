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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int L = -1, R = -1;
  auto Check = [&](int x) {
    vector<long long> need(n);
    for (int i = 0; i < m; i++) {
      vector<int> v;
      for (int j = 0; j < n; j++) {
        v.push_back(a[j][i]);
      }
      SparseTable<int> st(v, [&](int i, int j) {
        return max(i, j);
      });
      for (int j = 0; j + x <= n; j++) {
        need[j] += st.get(j, j + x - 1);
      }
    }
    for (int i = 0; i + x <= n; i++) {
      if (need[i] <= k) {
        L = i;
        R = i + x - 1;
        return true;
      }
    }
    return false;
  };
  int low = 1, high = 1e9, ans = 0;
  while (low <= high) {
    int mid = low + high >> 1;
    if (Check(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (ans == 0) {
    for (int i = 0; i < m; i++) {
      cout << 0 << " ";
    }
    cout << '\n';
  } else {
    Check(ans);
    for (int i = 0; i < m; i++) {
      int mx = 0;
      for (int j = L; j <= R; j++) {
        mx = max(mx, a[j][i]);
      }
      cout << mx << " ";
    }
    cout << '\n';
  }
  return 0;
}