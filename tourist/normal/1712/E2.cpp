/**
 *    author:  tourist
 *    created: 13.08.2022 17:52:00       
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
  int tt;
  cin >> tt;
  vector<int> L(tt), R(tt);
  int mx = -1;
  for (int i = 0; i < tt; i++) {
    int l, r;
    cin >> l >> r;
    L[i] = l;
    R[i] = r;
    mx = max(mx, r);
  }
  vector<long long> res(tt);
  vector<vector<int>> divs(mx + 1);
  for (int i = 1; i <= mx; i++) {
    for (int j = i + i; j <= mx; j += i) {
      divs[j].push_back(i);
    }
  }
  vector<vector<int>> qs(mx + 1);
  for (int i = 0; i < tt; i++) {
    qs[R[i]].push_back(i);
  }
  fenwick<long long> fenw(mx + 1);
  for (int i = 1; i <= mx; i++) {
    for (int j = 0; j < (int) divs[i].size() - 1; j++) {
      int at = divs[i][j];
      int cc = (int) divs[i].size() - j - 1;
      fenw.modify(at, cc);
    }
    for (int id : qs[i]) {
      res[id] = fenw.get(i) - fenw.get(L[id] - 1);
    }
  }
  for (int i = 0; i < tt; i++) {
    int l = L[i];
    int r = R[i];
    long long len = r - l + 1;
    long long ans = len * (len - 1) * (len - 2) / 6;
    ans -= res[i];
    // 12 * k >= 4 * l
    // 12 * k <= 2 * r
    // 3 * k >= l
    // 6 * k <= r
    {
      int low = (l + 2) / 3;
      int high = r / 6;
      if (low <= high) {
        ans -= high - low + 1;
      }
    }
    // 30 * k >= 5 * l
    // 30 * k <= 2 * r
    // 6 * k >= l
    // 15 * k <= r
    {
      int low = (l + 5) / 6;
      int high = r / 15;
      if (low <= high) {
        ans -= high - low + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}