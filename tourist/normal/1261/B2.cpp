/**
 *    author:  tourist
 *    created: 24.11.2019 11:09:27       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> k(m), pos(m);
  vector<vector<int>> at(n);
  for (int i = 0; i < m; i++) {
    cin >> k[i] >> pos[i];
    --k[i]; --pos[i];
    at[k[i]].push_back(i);
  }
  vector<int> order(n);
  for (int i = 0; i < n; i++) {
    order[i] = i;
  }
  sort(order.begin(), order.end(), [&](int i, int j) {
    if (a[i] != a[j]) {
      return a[i] > a[j];
    }
    return i < j;
  });
  vector<int> res(m);
  fenwick<int> fenw(n);
  for (int i = 0; i < n; i++) {
    fenw.modify(order[i], 1);
    for (int j : at[i]) {
      int low = 0, high = n - 1;
      while (low < high) {
        int mid = (low + high) >> 1;
        if (fenw.get(mid) >= pos[j] + 1) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }
      res[j] = a[low];
    }
  }
  for (int i = 0; i < m; i++) {
    cout << res[i] << '\n';
  }
  return 0;
}