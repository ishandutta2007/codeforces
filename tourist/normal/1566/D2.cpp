/**
 *    author:  tourist
 *    created: 12.09.2021 17:45:14       
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
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w;
    cin >> h >> w;
    vector<int> a(h * w);
    for (int i = 0; i < h * w; i++) {
      cin >> a[i];
    }
    vector<pair<int, int>> b(h * w);
    for (int i = 0; i < h * w; i++) {
      b[i] = make_pair(a[i], i);
    }
    sort(b.begin(), b.end());
    vector<pair<int, int>> go(h * w);
    vector<pair<int, int>> seats;
    int beg = 0;
    while (beg < h * w) {
      int end = beg;
      while (end + 1 < h * w && b[end + 1].first == b[end].first) {
        ++end;
      }
      seats.clear();
      for (int i = beg; i <= end; i++) {
        seats.emplace_back(i / w, -(i % w));
      }
      sort(seats.begin(), seats.end());
      for (int i = beg; i <= end; i++) {
        go[b[i].second] = seats[i - beg];
      }
      beg = end + 1;
    }
    vector<fenwick<int>> fenw(h, fenwick<int>(w));
    long long ans = 0;
    for (int i = 0; i < h * w; i++) {
      int x = go[i].first;
      int y = -go[i].second;
      ans += fenw[x].get(y);
      fenw[x].modify(y, +1);
    }
    cout << ans << '\n';
  }
  return 0;
}