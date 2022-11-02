#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

// #define LOCAL

int n;
int ko, sy;

int correct[111], cur[111];

pair<int, int> calc() {
  int k = 0, s = 0;
  for (int i = 0; i < n; ++i) {
    k += cur[i] * (cur[i] - 1) * (cur[i] - 2) / 6;
  }
  for (int i = 0; i < n - 2; ++i) {
    s += cur[i] * cur[i + 1] * cur[i + 2];
  }
  return make_pair(k, s);
}

pair<int, int> ins(int k) {
#ifdef LOCAL
  ++cur[k];
  pair<int, int> r2 = calc();
  pair<int, int> res(r2.first - ko, r2.second - sy);
  ko = r2.first;
  sy = r2.second;
  return res;
#else
  printf("+ %d\n", k + 1);
  fflush(stdout);
  int ko2 = in();
  int sy2 = in();
  pair<int, int> res(ko2 - ko, sy2 - sy);
  ko = ko2;
  sy = sy2;
  return res;
#endif
}

int f_ko(int dif) {
  for (int t = 1; ; ++t) {
    const int k1 = t * (t - 1) * (t - 2) / 6;
    const int k2 = (t + 1) * t * (t - 1) / 6;
    if (k2 - k1 == dif) {
      return t + 1;
    }
  }
}

pair<int, int> qrs[111];
int as[111];

int val(int k, int kk) {
  if (k % 2 == kk % 2) {
    return as[kk] + (k > kk ? 1 : 0);
  } else {
    return as[kk] + (k % 2 == 1 ? 1 : 0);
  }
}

int qvalue(int k) {
  int res = 0;
  if (k - 2 >= 0) res += val(k, k - 2) * val(k, k - 1);
  if (k - 1 >= 0 && k + 1 < n) res += val(k, k - 1) * val(k, k + 1);
  if (k + 2 < n) res += val(k, k + 1) * val(k, k + 2);
  return res;
}

bool so_rec(int fr, int to) {
  if (to - fr <= 8) {
    vector<int> zos;
    for (int i = fr; i < to; ++i) {
      if (qrs[i].first != 0) {
        as[i] = f_ko(qrs[i].first) - 1;
      } else {
        zos.push_back(i);
      }
    }

    bool found = false;
    int ans = 0;
    const int m = zos.size();
    for (int z = 0; z < (1<<m); ++z) {
      for (int i = 0; i < m; ++i) {
        if (z & (1 << i)) {
          as[zos[i]] = 1;
        } else {
          as[zos[i]] = 0;
        }
      }
      bool ok = true;
      for (int i = fr - 2; i < to + 2; ++i) {
        if (0 <= i && i < n) {
          ok &= qvalue(i) == qrs[i].second;
        }
      }
      if (ok) {
        if (found) {
          return false;
        } else {
          found = true;
          ans = z;
        }
      }
    }

    if (found) {
      for (int i = 0; i < m; ++i) {
        if (ans & (1 << i)) {
          as[zos[i]] = 1;
        } else {
          as[zos[i]] = 0;
        }
      }
      return true;
    } else {
      return false;
    }
  }

  int k = to + (fr - to) / 2 - 2;
  vector<int> zos;
  for (int i = k; i < k + 4; ++i) {
    if (qrs[i].first != 0) {
      as[i] = f_ko(qrs[i].first) - 1;
    } else {
      zos.push_back(i);
    }
  }

  bool found = false;
  vector<int> ans_o(to - fr);
  const int m = zos.size();
  for (int z = 0; z < (1<<m); ++z) {
    for (int i = 0; i < m; ++i) {
      if (z & (1 << i)) {
        as[zos[i]] = 1;
      } else {
        as[zos[i]] = 0;
      }
    }
    if (so_rec(fr, k) && so_rec(k + 4, to)) {
      if (found) {
        return false;
      } else {
        found = true;
        for (int i = fr; i < to; ++i) {
          ans_o[i - fr] = as[i];
        }
      }
    }
  }

  if (found) {
    for (int i = fr; i < to; ++i) {
      as[i] = ans_o[i - fr];
    }
    return true;
  } else {
    return false;
  }
}

vector<int> solve_odd() {
  for (int i = 0, t = 0; i < n; ++i) {
    qrs[t] = ins(t);
    t += 2;
    if (t >= n) {
      t = 1;
    }
  }

  assert(so_rec(0, n));

  vector<int> res;
  for (int i = 0; i < n; ++i) {
    res.push_back(as[i]);
  }
  return res;
}

vector<int> solve_4() {
  vector<pair<int, int>> qr;
  for (int i = 0; i < n; ++i) {
    qr.push_back(ins(i % 3));
  }

  vector<int> res(4, -1);
  res[0] = f_ko(qr[3].first) - 2;
  if (qr[1].first != 0) {
    res[1] = f_ko(qr[1].first) - 1;
  }
  if (qr[2].first != 0) {
    res[2] = f_ko(qr[2].first) - 1;
  }
  if (res[1] >= 0 || res[2] >= 0) {
    if (res[1] < 0) res[1] = qr[3].second / (res[2] + 1) - 1;
    if (res[2] < 0) res[2] = qr[3].second / (res[1] + 1) - 1;
  } else {
    if (qr[3].second == 1) {
      res[1] = res[2] = 0;
    } else if (qr[3].second == 4) {
      res[1] = res[2] = 1;
    } else {
      if (qr[1].second == 0) {
        res[1] = 1; res[2] = 0;
      } else {
        res[1] = 0; res[2] = 1;
      }
    }
  }
  res[3] = qr[2].second / (res[1] + 1) - (res[0] + 1);

  return res;
}

int main() {
  n = in();
#ifdef LOCAL
  for (int i = 0; i < n; ++i) {
    cur[i] = correct[i] = in();
  }
  auto t = calc();
  ko = t.first;
  sy = t.second;
#else
  ko = in();
  sy = in();
#endif

  vector<int> res = n == 4 ? solve_4() : solve_odd();

  printf("!");
  for (const int a : res) {
    printf(" %d", a);
  }
  puts("");
  fflush(stdout);

#ifdef LOCAL
  for (int i = 0; i < n; ++i) {
    if (res[i] != correct[i]) {
      puts("WA");
      return 0;
    }
  }
  puts("AC");
#endif

  return 0;
}