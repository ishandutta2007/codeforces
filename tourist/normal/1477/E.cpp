/**
 *    author:  tourist
 *    created: 28.01.2021 18:25:17       
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
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  const int M = (int) 1e6 + 10;
  fenwick<long long> fasum(M);
  fenwick<long long> fbsum(M);
  fenwick<long long> facnt(M);
  fenwick<long long> fbcnt(M);
  multiset<int> sa;
  multiset<int> sb;
  for (int i = 0; i < n; i++) {
    fasum.modify(a[i], a[i]);
    facnt.modify(a[i], 1);
    sa.insert(a[i]);
  }
  for (int i = 0; i < m; i++) {
    fbsum.modify(b[i], b[i]);
    fbcnt.modify(b[i], 1);
    sb.insert(b[i]);
  }
  auto GetOverA = [&](int bound) -> long long {
    if (bound >= M) {
      return 0LL;
    }
    long long sum = fasum.get(M - 1) - fasum.get(max(bound, -1));
    long long cnt = facnt.get(M - 1) - facnt.get(max(bound, -1));
    return sum - bound * cnt;
  };
  auto GetOverB = [&](int bound) -> long long {
    if (bound >= M) {
      return 0LL;
    }
    long long sum = fbsum.get(M - 1) - fbsum.get(max(bound, -1));
    long long cnt = fbcnt.get(M - 1) - fbcnt.get(max(bound, -1));
    return sum - bound * cnt;
  };
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int pos, x;
      cin >> pos >> x;
      --pos;
      sa.erase(sa.find(a[pos]));
      fasum.modify(a[pos], -a[pos]);
      facnt.modify(a[pos], -1);
      a[pos] = x;
      sa.insert(a[pos]);
      fasum.modify(a[pos], a[pos]);
      facnt.modify(a[pos], 1);
    }
    if (op == 2) {
      int pos, x;
      cin >> pos >> x;
      --pos;
      sb.erase(sb.find(b[pos]));
      fbsum.modify(b[pos], -b[pos]);
      fbcnt.modify(b[pos], -1);
      b[pos] = x;
      sb.insert(b[pos]);
      fbsum.modify(b[pos], b[pos]);
      fbcnt.modify(b[pos], 1);
    }
    if (op == 3) {
      int k;
      cin >> k;
      long long ans = -(long long) 1e18;
      int global = min(*sa.begin(), *sb.begin());
      { // opp
        int init = *sb.rbegin() - k;
        long long their = GetOverB(init);
        long long mine = GetOverA(min(init, global));
        ans = max(ans, mine - their);
      }
      { // very min
        int init = min(*sa.begin(), *sb.begin()) - k;
        long long their = GetOverB(init);
        long long mine = GetOverA(min(init, global));
        ans = max(ans, mine - their);
      }
      { // lower-upper
        auto Test = [&](int start) {
          int init = start - k;
          long long their = GetOverB(init);
          long long mine = GetOverA(min(init, global)) - (start - min(init, global)) + k;
          ans = max(ans, mine - their);
        };
        int about = *sb.rbegin() + k;
        auto it = sa.lower_bound(about);
        if (it != sa.end()) {
          Test(*it);
        }
        if (it != sa.begin()) {
          Test(*prev(it));
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}