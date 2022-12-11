#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <utility>

struct data {
  int l, r;
  long long val;
  data(int _l = 0, int _r = 0, long long _val = 0) { l = _l; r = _r; val = _val; }
  inline friend bool operator < (const data &x, const data &y) { return x.l < y.l; }
  inline friend bool operator == (const data &x, const data &y) { return x.l == y.l && x.r == y.r && x.val == y.val; }
};

int N, M, Seed, Vmax;
std::set<data> S;
std::priority_queue< std::pair<long long, int> > Pq;

inline int rnd() {
  int ret = Seed;
  Seed = (1LL * Seed * 7 + 13) % 1000000007;
  return ret;
}

inline int fastPow(int low, int high, int mod) {
  int res = 1;
  while (high) {
    if (high & 1) res = 1LL * res * low % mod;
    high >>= 1;
    low = 1LL * low * low % mod;
  }
  return res;
}

int main() {
  scanf("%d %d %d %d", &N, &M, &Seed, &Vmax);
  for (int i = 1; i <= N; ++i) S.insert(data(i, i, rnd() % Vmax + 1));
  for (int i = 1; i <= M; ++i) {
    int opt = rnd() % 4 + 1, l = rnd() % N + 1, r = rnd() % N + 1;
//    printf("q = (%d, %d, %d)\n", opt, l, r);
    if (l > r) std::swap(l, r);
    if (opt == 1) {
      int x = rnd() % Vmax + 1;
      auto fir = S.upper_bound(data(l, l)), lst = S.upper_bound(data(r, r)), ltt = lst;
      fir--; ltt--;
      data fr = *fir, lt = *ltt;
      std::vector<data> v;
      v.clear();
      for (auto it = fir; it != lst; ++it) {
        data d = *it;
        if (d.l < l) d.l = l;
        if (d.r > r) d.r = r;
        d.val += x;
        v.push_back(d);
      }
      S.erase(fir, lst);
      for (auto d : v) S.insert(d);
      if (fr.l < l) S.insert(data(fr.l, l - 1, fr.val));
      if (r < lt.r) S.insert(data(r + 1, lt.r, lt.val));
    } else if (opt == 2) {
      int x = rnd() % Vmax + 1;
      auto fir = S.upper_bound(data(l, l)), lst = S.upper_bound(data(r, r)), ltt = lst;
      fir--; ltt--;
      data fr = *fir, lt = *ltt;
      S.erase(fir, lst);
      S.insert(data(l, r, x));
      if (fr.l < l) S.insert(data(fr.l, l - 1, fr.val));
      if (r < lt.r) S.insert(data(r + 1, lt.r, lt.val));
    } else if (opt == 3) {
      int x = rnd() % (r - l + 1) + 1;
      while (!Pq.empty()) Pq.pop();
      auto it = S.upper_bound(data(l, l));
      it--;
      while (l <= r) {
        int len = std::min(r, it->r) - l + 1;
        Pq.push(std::make_pair(-it->val, len));
        l = it->r + 1;
        it++;
      }
      for (;;) {
        x -= Pq.top().second;
        if (x <= 0) {
          printf("%lld\n", -Pq.top().first);
          break;
        }
        Pq.pop();
      }
    } else {
      int x = rnd() % Vmax + 1, y = rnd() % Vmax + 1;
      int res = 0;
      auto it = S.upper_bound(data(l, l));
      it--;
      while (l <= r) {
        int len = std::min(r, it->r) - l + 1;
        res = (res + 1LL * len * fastPow(it->val % y, x, y) % y) % y;
        l = it->r + 1;
        it++;
      }
      printf("%d\n", res);
    }
//    for (auto v = S.lower_bound(data(1, 1)); v != S.upper_bound(data(N, N)); ++v) printf("(%d, %d, %lld)\n", v->l, v->r, v->val);
  }
  return 0;
}