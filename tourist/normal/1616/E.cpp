/**
 *    author:  tourist
 *    created: 29.12.2021 18:40:24       
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    const int A = 26;
    vector<vector<int>> pos(A);
    for (int i = 0; i < n; i++) {
      int c = (int) (s[i] - 'a');
      pos[c].push_back(i);
    }
    fenwick<int> fenw(n);
    for (int i = 0; i < n; i++) {
      fenw.modify(i, 1);
    }
    vector<int> ptr(A, 0);
    const long long inf = (long long) 1e18;
    long long ans = inf;
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      int c = (int) (t[i] - 'a');
      for (int d = 0; d < c; d++) {
        if (ptr[d] < (int) pos[d].size()) {
          int x = pos[d][ptr[d]];
          ans = min(ans, cur + fenw.get(x - 1));
        }
      }
      if (ptr[c] == (int) pos[c].size()) {
        break;
      }
      int x = pos[c][ptr[c]];
      cur += fenw.get(x - 1);
      fenw.modify(x, -1);
      ptr[c] += 1;
    }
    cout << (ans == inf ? -1LL : ans) << '\n';
  }
  return 0;
}