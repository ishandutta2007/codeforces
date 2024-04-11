#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

typedef modnum<998244353> mnum;

struct component {
  // i means l[i], r[i]
  vector<pii> intervals;

  // a, b in the intervals list are connected
  vector<int> edges;

  // dp[mask][k] means that assuming mask is enabled, how many ways are there to have k things on
  vector<vector<int>> dp;
};

int solve(component& c, int mask, int amt) {
  if(c.dp[mask][amt] >= 0) return c.dp[mask][amt];
  if(amt == 0) return 1;
  if(__builtin_popcount(mask) < amt) return 0;
  c.dp[mask][amt] = 0;
  int idx = __builtin_ctz(mask);
  assert(mask&(1<<idx));
  // don't pick it
  c.dp[mask][amt] = solve(c, mask^(1<<idx), amt);
  // do pick it
  int nmask = mask ^ (1 << idx);
  nmask &= ~(c.edges[idx]);
  c.dp[mask][amt] += solve(c, nmask, amt-1);
  return c.dp[mask][amt];
}

int lhsp[300000];
int rhsp[300000];
int lhse[20];
int rhse[20];
int numedges, numv;
void make_component(component& c, vector<int>& v) {
  sort(all(v));
  for(int out: v) {
    c.intervals.emplace_back(lhsp[out], rhsp[out]);
    c.edges.push_back(0);
  }
  for(int i = 0; i < numedges; i++) {
    if(binary_search(all(v), lhse[i])) {
      int idxl = lower_bound(all(v), lhse[i]) - v.begin();
      int idxr = lower_bound(all(v), rhse[i]) - v.begin();
      c.edges[idxl] |= (1 << idxr);
      c.edges[idxr] |= (1 << idxl);
    }
  }
  c.dp.reserve(1 << sz(c.intervals));
  for(int i = 0; i < (1 << sz(c.intervals)); i++) {
    vector<int> t(sz(c.intervals)+1, -1);
    c.dp.push_back(t);
  }
}
bool seen[300000];

int freecnt[300005];
mnum dp[21];
mnum ndp[21];
mnum facs[300001];

mnum choose(int n, int k) {
  if(k < 0 || k > n) return 0;
  return facs[n] / facs[k] / facs[n-k];
}

void solve() {
  cin >> numv >> numedges;
  facs[0] = 1;
  for(int i = 1; i <= numv; i++) facs[i] = facs[i-1] * i;
  for(int i = 0; i < numv; i++) cin >> lhsp[i] >> rhsp[i];
  for(int i = 0; i < numedges; i++) {
    cin >> lhse[i] >> rhse[i];
    lhse[i]--; rhse[i]--;
  }
  vector<component> components;
  {
    // make all the components
    for(int i = 0; i < numedges; i++) {
      if(seen[lhse[i]]) continue;
      vector<int> cv;
      cv.push_back(lhse[i]);
      seen[lhse[i]] = true;
      for(int a = 0; a < sz(cv); a++) {
        for(int q = 0; q < numedges; q++) {
          if(lhse[q] == cv[a] && !seen[rhse[q]]) {
            seen[rhse[q]] = true;
            cv.push_back(rhse[q]);
          }
          if(rhse[q] == cv[a] && !seen[lhse[q]]) {
            seen[lhse[q]] = true;
            cv.push_back(lhse[q]);
          }
        }
      }
      component x;
      components.push_back(x);
      make_component(components.back(), cv);
    }
  }
  for(int i = 0; i < numv; i++) {
    if(seen[i]) continue;
    freecnt[lhsp[i]]++;
    freecnt[rhsp[i]+1]--;
  }
  mnum ret = 0;
  for(int amt = 1; amt <= numv; amt++) {
    freecnt[amt] += freecnt[amt-1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int maxv = 0;
    for(component& c: components) {
      int availmask = 0;
      for(int i = 0; i < sz(c.intervals); i++) {
        if(c.intervals[i].f <= amt && amt <= c.intervals[i].s) {
          availmask |= 1 << i;
        }
      }
      int nmaxv = maxv;
      memset(ndp, 0, sizeof(ndp));
      for(int cand = 0; cand <= maxv; cand++) {
        if(dp[cand] == 0) continue;
        for(int i = 0; i <= sz(c.intervals); i++) {
          int inc = solve(c, availmask, i);
          if(inc == 0) break;
          ndp[cand+i] += dp[cand] * inc;
          nmaxv = max(nmaxv, cand+i);
        }
      }
      memcpy(dp, ndp, sizeof(dp));
      maxv = nmaxv;
    }
    for(int i = 0; i <= maxv && i <= amt; i++) {
      ret += dp[i] * choose(freecnt[amt], amt-i);
    }
  }
  cout << ret << "\n";
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}