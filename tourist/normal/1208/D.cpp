/**
 *    author:  tourist
 *    created: 25.08.2019 17:41:40       
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
  vector<long long> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  fenwick<long long> fenw(n);
  for (int i = 0; i < n; i++) {
    fenw.modify(i, i + 1);
  }
  vector<int> a(n);
  for (int i = n - 1; i >= 0; i--) {
    int low = 0, high = n - 1;
    while (low < high) {
      int mid = (low + high) >> 1;
      if (fenw.get(mid) > s[i]) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    a[i] = low + 1;
    fenw.modify(low, -low - 1);
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << '\n';
  return 0;
}