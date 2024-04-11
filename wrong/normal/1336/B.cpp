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

Int solve2(const vector<Int>& a, const vector<Int>& b, const vector<Int>& c) {
  int bi = 0;
  const int alen = a.size();
  const int blen = b.size();
  const int clen = c.size();
  const auto v = [] (const Int x, const Int y, const Int z) {
    return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
  };

  Int res = INFLL * 3;
  for (int ai = 0; ai < alen; ++ai) {
    while (bi + 1 < blen && b[bi + 1] <= a[ai]) {
      ++bi;
    }
    int ci = lower_bound(c.begin(), c.end(), (a[ai] + b[bi]) / 2) - c.begin();
    for (int d = -3; d <= 3; ++d) {
      int cci = ci + d;
      if (0 <= cci && cci < clen) {
        chmin(res, v(a[ai], b[bi], c[cci]));
      }
    }
  }

  return res;
}

void solve() {
  int r = in();
  int g = in();
  int b = in();
  vector<Int> rs(r), gs(g), bs(b);
  
  for (int i = 0; i < r; ++i) {
    rs[i] = lin();
  }
  for (int i = 0; i < g; ++i) {
    gs[i] = lin();
  }
  for (int i = 0; i < b; ++i) {
    bs[i] = lin();
  }
  sort(rs.begin(), rs.end());
  sort(gs.begin(), gs.end());
  sort(bs.begin(), bs.end());

  Int res = INFLL * 3;
  chmin(res, solve2(rs, gs, bs));
  chmin(res, solve2(rs, bs, gs));
  chmin(res, solve2(gs, rs, bs));
  chmin(res, solve2(gs, bs, rs));
  chmin(res, solve2(bs, rs, gs));
  chmin(res, solve2(bs, gs, rs));

  cout << res << endl;
}

int main() {
  int t = in();

  while (t--) {
    solve();
  }

  return 0;
}