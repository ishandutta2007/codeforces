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
typedef pair<ll, ll> pll;

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
typedef vector<vector<mnum>> matrix;

matrix mult(const matrix& a, const matrix& b) {
  matrix c;
  for(int i = 0; i < sz(a); i++) {
    vector<mnum> temp(sz(b));
    for(int j = 0; j < sz(b[0]); j++) {
      for(int k = 0; k < sz(b); k++) {
        temp[j] += a[i][k] * b[k][j];
      }
    }
    c.push_back(temp);
  }
  return c;
}
matrix pow(const matrix& b, int e) {
  if(e == 1) return b;
  if(e%2==0) {
    matrix r = pow(b, e/2);
    return mult(r, r);
  }
  matrix r = pow(b, e-1);
  return mult(b, r);
}

int getNumMatch(int w, int topmask, int botmask) {
  if(w == 1) {
    // ugh
    if(topmask == 1 && botmask == 1) return 0;
    return 1;
  }
  assert(w > 1);
  vector<int> dp(2);
  // 1 means you chose previous
  // 0 means you didn't
  dp[1] = 1;
  for(int i = 1; i < w; i++) {
    vector<int> ndp(2);
    ndp[0] = dp[0] + dp[1];
    ndp[1] = dp[0];
    if((topmask&(1<<(i-1))) == 0 || (botmask&(1<<(i-1))) == 0) {
      ndp[1] += dp[1];
    }
    dp = ndp;
  }
  int ret = 0;
  if((topmask & (1<<(w-1))) == 0) ret = dp[0] + dp[1];
  else if((botmask & (1<<(w-1))) == 0) ret = dp[0] + dp[1];
  else ret = dp[0];
  return ret;
}

void solve() {
  vector<pii> tiles;
  for(int i = 1; i <= 7; i++) {
    int x;
    cin >> x;
    if(x) tiles.push_back({x, i});
  }
  // tiles is <num, width>
  matrix r;
  {
    int smallestw = tiles[0].second;
    for(int i = 0; i < (1<<smallestw); i++) {
      vector<mnum> temp(1);
      r.push_back(temp);
    }
    r[sz(r)-1][0] = 1;
  }
  mnum ret = 0;
  for(int i = 0; i < sz(tiles); i++) {
    matrix trans;
    int w = tiles[i].second;
    for(int a = 0; a < (1<<w); a++) {
      vector<mnum> temp(1<<w);
      for(int j = 0; j < (1<<w); j++) {
        temp[j] = getNumMatch(w, a, j);
      }
      trans.push_back(temp);
    }
    trans = pow(trans, tiles[i].first);
    r = mult(trans, r);
    if(i+1 == sz(tiles)) {
      ret = r[sz(r)-1][0];
    }
    else {
      matrix nr;
      int smallestw = tiles[i+1].second;
      for(int a = 0; a < (1<<smallestw); a++) {
        vector<mnum> temp(1);
        nr.push_back(temp);
      }
      for(int a = 0; a < sz(r); a++) {
        nr[sz(nr) - sz(r) + a][0] = r[a][0];
      }
      r = nr;
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}