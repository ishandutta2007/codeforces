/**
 *    author:  tourist
 *    created: 14.02.2022 21:06:54       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

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
  int n, tt;
  cin >> n >> tt;
  vector<long long> color_value(n);
  map<int, int> mp;
  mp[0] = 0;
  mp[n] = 0;
  auto Cut = [&](int x) {
    if (mp.find(x) == mp.end()) {
      auto it = prev(mp.lower_bound(x));
      mp[x] = it->second;
    }
  };
  fenwick<long long> fenw(n + 1);
  while (tt--) {
    string op;
    cin >> op;
    if (op == "Color") {
      int l, r, c;
      cin >> l >> r >> c;
      --l; --c;
      // [l; r)
      Cut(l);
      Cut(r);
      auto it = mp.find(l);
      while (it->first < r) {
        int L = it->first;
        int R = next(it)->first;
        int old_color = it->second;
        // recolor [L; R) from old_color into c
        long long diff = color_value[old_color] - color_value[c];
        fenw.modify(L, diff);
        fenw.modify(R, -diff);
        it = mp.erase(it);
      }
      mp[l] = c;
    }
    if (op == "Add") {
      int c, x;
      cin >> c >> x;
      --c;
      color_value[c] += x;
    }
    if (op == "Query") {
      int i;
      cin >> i;
      --i;
      auto it = prev(mp.upper_bound(i));
      int color = it->second;
      long long value = fenw.get(i);
      cout << color_value[color] + value << '\n';
    }
  }
  return 0;
}