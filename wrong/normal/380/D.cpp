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

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

const int MOD = 1000000007;
Int pow2[100050], fact[100050], fact_inv[100050];

struct pos_info {
  int idx, pos;
  pos_info(int i, int p) : idx(i), pos(p) { }
};

Int comb(int n, int r) {
  return fact[n] * fact_inv[r] % MOD * fact_inv[n - r] % MOD;
}

Int solve(int n, const vector<int>& idx, const vector<int>& pos, int sl, int sr, int l, int r) {
  vector<pos_info> info;
  const int m = idx.size();

  for (int i = 0; i < m; ++i) {
    if (l <= pos[i] && pos[i] <= r) {
      continue;
    }
    info.push_back(pos_info(idx[i], pos[i]));
  }
  sort(info.begin(), info.end(),
    [] (const pos_info& a, const pos_info& b) {
      return a.idx < b.idx;
    });

  Int res = 1;
  for (const pos_info& p : info) {
    if (l <= p.pos && p.pos <= r) {
      return 0;
    }

    int ll, rr, zero_p;
    if (p.pos > r) {
      zero_p = p.pos - r - 1;
      rr = p.pos;
      ll = rr - p.idx;
    } else {
      zero_p = l - p.pos - 1;
      ll = p.pos;
      rr = ll + p.idx;
    }

    if (!(ll <= l && r <= rr) || ll < 0 || rr >= n) {
      return 0;
    }

    (res *= comb((rr - r) + (l - ll) - 1, zero_p)) %= MOD;
    l = ll;
    r = rr;
    // cerr <<l<<' '<<r<<' '<<res<<endl;
  }

  (res *= comb((n - 1 - r) + l, l)) %= MOD;
  return res;
}

Int powmod(Int x, Int e) {
  Int v = 1;
  for (; e; e >>= 1, x = (x*x) % MOD) {
    if (e & 1) {
      v = (v*x) % MOD;
    }
  }
  return v;
}

int main()
{
  int n;
  scanf("%d", &n);

  int have_zero = -1;
  vector<int> idx, pos;
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%d", &k);
    if (k != 0) {
      if (k - 1 == 0) {
        have_zero = idx.size();
      }
      idx.push_back(k - 1);
      pos.push_back(i);
    }
  }

  pow2[0] = 1;
  for (int i = 1; i <= 100000; ++i) {
    pow2[i] = (pow2[i - 1] * 2) % MOD;
  }

  fact[0] = 1;
  fact_inv[0] = 1;
  for (int i = 1; i <= 100000; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
    fact_inv[i] = powmod(fact[i], MOD - 2);
  }

  int m = idx.size();
  if (m == 0) {
    cout << pow2[n - 1] << endl;
    return 0;
  }

  if (have_zero >= 0) {
    cout << solve(n, idx, pos, have_zero, have_zero, pos[have_zero], pos[have_zero]) << endl;
    return 0;
  }

  vector<int> incr(m, 0), decr(m, 0);
  incr[m - 1] = 1;
  for (int i = m - 2; i >= 0; --i) {
    incr[i] = incr[i + 1] && idx[i] < idx[i + 1];
  }
  decr[0] = 1;
  for (int i = 1; i < m; ++i) {
    decr[i] = decr[i - 1] && idx[i] < idx[i - 1];
  }

  Int res = 0;
  if (incr[0] && pos[0] >= idx[0]) {
    (res += solve(n, idx, pos, 0, 0, pos[0] - idx[0], pos[0]) * pow2[idx[0] - 1] % MOD) %= MOD;
    // cerr << "1: " << res << endl;
  }
  if (decr[m - 1] && n - 1 - pos[m - 1] >= idx[m - 1]) {
    (res += solve(n, idx, pos, m - 1, m - 1, pos[m - 1], pos[m - 1] + idx[m - 1]) * pow2[idx[m - 1] - 1] % MOD) %= MOD;
    // cerr << "2: " << res << endl;
  }
  for (int i = 0; i + 1 < m; ++i) {
    if (decr[i] && incr[i + 1] && min(idx[i], idx[i + 1]) <= pos[i + 1] - pos[i] - 1) {
      if (idx[i] < idx[i + 1]) {
        (res += solve(n, idx, pos, i, i + 1, pos[i], pos[i] + idx[i]) * pow2[idx[i] - 1] % MOD) %= MOD;        
      } else {
        (res += solve(n, idx, pos, i, i + 1, pos[i + 1] - idx[i + 1], pos[i + 1]) * pow2[idx[i + 1] - 1] % MOD) %= MOD;
      }
      // cerr << i << ' ' << res << endl;
    }
  }

  cout << res << endl;

  return 0;
}