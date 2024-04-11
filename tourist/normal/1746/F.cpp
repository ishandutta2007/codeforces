/**
 *    author:  tourist
 *    created: 15.10.2022 19:12:25       
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
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 64; j++) {
        fenw[i][j] = 0;
      }
    }
  }

  void modify(int x, T v) {
    while (x < n) {
      for (int j = 0; j < 64; j++) {
        fenw[x][j] += v[j];
      }
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v;
    for (int j = 0; j < 64; j++) {
      v[j] = 0;
    }
    while (x >= 0) {
      for (int j = 0; j < 64; j++) {
        v[j] += fenw[x][j];
      }
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ql(q), qr(q), qx(q);
  for (int i = 0; i < q; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      cin >> ql[i] >> qx[i];
      --ql[i];
      qr[i] = -1;
    } else {
      cin >> ql[i] >> qr[i] >> qx[i];
      --ql[i]; --qr[i];
    }
  }
  vector<pair<int, int>> all;
  for (int i = 0; i < n; i++) {
    all.emplace_back(a[i], i);
  }
  for (int i = 0; i < q; i++) {
    if (qr[i] == -1) {
      all.emplace_back(qx[i], ~i);
    }
  }
  sort(all.begin(), all.end());
  int t = 0;
  for (int i = 0; i < (int) all.size(); i++) {
    if (i > 0 && all[i].first != all[i - 1].first) {
      t += 1;
    }
    int id = all[i].second;
    if (id >= 0) {
      a[id] = t;
    } else {
      qx[~id] = t;
    }
  }
  t += 1;
  mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  vector<array<int, 64>> num(t);
  for (int i = 0; i < t; i++) {
    auto mask = rng();
    for (int j = 0; j < 64; j++) {
      num[i][j] = ((mask >> j) & 1) ? 1 : 0;
    }
  }
  fenwick<array<int, 64>> fenw(n);
  for (int i = 0; i < n; i++) {
    fenw.fenw[i] = num[a[i]];
  }
  for (int i = 0; i < n; i++) {
    int x = i | (i + 1);
    if (x < n) {
      for (int j = 0; j < 64; j++) {
        fenw.fenw[x][j] += fenw.fenw[i][j];
      }
    }
  }
  for (int id = 0; id < q; id++) {
    if (qr[id] == -1) {
      array<int, 64> diff;
      for (int j = 0; j < 64; j++) {
        diff[j] = num[qx[id]][j] - num[a[ql[id]]][j];
      }
      fenw.modify(ql[id], diff);
      a[ql[id]] = qx[id];
    } else {
      auto qa = fenw.get(qr[id]);
      auto qb = fenw.get(ql[id] - 1);
      bool ok = true;
      for (int j = 0; j < 64; j++) {
        if ((qa[j] - qb[j]) % qx[id] != 0) {
          ok = false;
          break;
        }
      }
      cout << (ok ? "YES" : "NO") << '\n';
    }
  }
  return 0;
}