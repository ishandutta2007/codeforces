#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
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
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<string> matrix;

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

typedef modnum<1000000007> mnum;

typedef pair<pii, int> nimber;
vector<nimber> nimbers;

inline int mex(int a, int b) {
  if(a != 0 && b != 0) return 0;
  if(a != 1 && b != 1) return 1;
  return 2;
}

inline nimber getnimberobj(int n) {
  nimber fake = nimber({n, -1e9}, -1e9);
  int idx = lower_bound(all(nimbers), fake) - nimbers.begin();
  assert(idx < sz(nimbers));
  return nimbers[idx];
}

inline int getnimber(int n) {
  int a = n/3;
  int b = n - n/3;
  nimber lhs = getnimberobj(a);
  nimber rhs = getnimberobj(b);
  return mex(lhs.second, rhs.second);
}

inline int getmax(int n) {
  // get the largest integer that stays with those numbers
  int a = n/3;
  int b = n - n/3;
  nimber lhs = getnimberobj(a);
  nimber rhs = getnimberobj(b);
  int ret = max(n, min(3 * lhs.first.first, (int)(1.5*rhs.first.first) - 1));
  while(ret/3 <= lhs.first.first && ret-ret/3 <= rhs.first.first) ret++;
  return ret-1;
}

mnum amt[3];
mnum dp[2][4];
void solve() {
  nimbers.push_back(nimber({2, 1}, 0));
  while(nimbers.back().first.first < 1e9) {
    int lhs = nimbers.back().first.first + 1  ;
    int cand = lhs;
    int currnimber = getnimber(cand);
    while(true) {
      int force = getmax(cand);
      int upper = force+1;
      if(upper - upper/3 >= lhs || force >= 1e9 || getnimber(force+1) != currnimber) {
        nimbers.push_back(nimber({force, lhs}, currnimber));
        break;
      }
      cand = force+1;
    }
  }
  int n, p;
  cin >> n >> p;
  for(auto out: nimbers) {
    ll lhs = out.first.second;
    ll rhs = out.first.first;
    if(lhs >= p) break;
    rhs = min(rhs, p-1LL);
    lhs = p-lhs;
    rhs = p-rhs;
    amt[out.second] += lhs*(lhs+1)/2 - rhs*(rhs-1)/2;
  }
  dp[0][0] = 1;
  for(int qq = 0; qq < n; qq++) {
    int from = qq&1;
    int to = 1 ^ from;
    memset(dp[to], 0, sizeof(dp[to]));
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 3; j++) {
        dp[to][i^j] += dp[from][i] * amt[j];
      }
    }
  }
  cout << dp[n%2][1] + dp[n%2][2] + dp[n%2][3] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}