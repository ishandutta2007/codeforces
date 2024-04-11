#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
const int L = 19;

template <class T>
struct sparse_table {

  function<T(T, T)> func = [](T a, T b) { return max(a, b); };
  T table[L][N];

  void build() {
    for (int i = 1; i < L; ++i) {
      int len = 1 << (i - 1);
      for (int j = 0; j + len < N; ++j) {
        table[i][j] = func(table[i - 1][j], table[i - 1][j + len]);
      }
    }
  }

  T query(int a, int b) {
    int log_l = 31 - __builtin_clz(b - a + 1);
    return func(table[log_l][a], table[log_l][b - (1 << log_l) + 1]);
  }

};

sparse_table<array<int, 2>> st_mx;
sparse_table<int> st_or;

int64_t solve(int l, int r) {
  if (l > r) {
    return 0;
  }
  auto [val, ndx] = st_mx.query(l, r);

  int lo1 = ndx;
  int hi1 = r;
  while (lo1 <= hi1) {
    int mid = (lo1 + hi1) / 2;
    if (st_or.query(ndx, mid) == val) {
      lo1 = mid + 1;
    } else {
      hi1 = mid - 1;
    }
  }

  int lo2 = l;
  int hi2 = ndx;
  while (lo2 <= hi2) {
    int mid = (lo2 + hi2) / 2;
    if (st_or.query(mid, ndx) == val) {
      hi2 = mid - 1;
    } else {
      lo2 = mid + 1;
    }
  }

  return solve(l, ndx - 1) + solve(ndx + 1, r) + 1LL * (lo1 - ndx) * (ndx - hi2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    st_or.table[0][i] = a;
    st_mx.table[0][i] = {a, i};
  }

  st_or.func = [](int a, int b) {
    return a | b;
  };
  st_mx.build();
  st_or.build();

  cout << 1LL * n * (n + 1) / 2 - solve(0, n - 1) << "\n";
}