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

void read(int& n, int& m, matrix& g) {
  if(m <= 15) {
    for(int i = 0; i < n; i++) {
      string s;
      cin >> s;
      g.push_back(s);
    }
  }
  else {
    for(int i = 0; i < m; i++) {
      string s;
      g.push_back(s);
    }
    for(int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for(int j = 0; j < m; j++) {
        g[j] += s[j];
      }
    }
    swap(n, m);
  }
}

mnum dp[2][1<<15][2][2]; // <mask covered from above, are we covered in the row already, did we already lose a thing>
void solve() {
  int n, m;
  cin >> n >> m;
  matrix g;
  read(n, m, g);
  assert(sz(g) == n);
  for(int i = 0; i < n; i++) assert(sz(g[i]) == m);
  dp[0][0][0][0] = 1;
  for(int qq = 0; qq < n*m; qq++) {
    int from = qq&1;
    int to = from^1;
    memset(dp[to], 0, sizeof(dp[to]));
    int rr = qq/m;
    int cc = qq%m;
    for(int mask = 0; mask < (1<<m); mask++) {
      for(int a = 0; a < 2; a++) {
        for(int b = 0; b < 2; b++) {
          if(g[rr][cc] == 'x') {
            dp[to][mask & ~(1 << cc)][0][b] += dp[from][mask][a][b];
          }
          else {
            int na;
            // cover it
            na = (cc == m-1) ? 0 : 1;
            dp[to][mask | (1 << cc)][na][b] += dp[from][mask][a][b];
            // do not cover it
            na = (cc == m-1) ? 0 : a;
            int nb = b;
            if(a == 0 && (mask&(1<<cc)) == 0) nb++;
            if(nb < 2) {
              dp[to][mask][na][nb] += dp[from][mask][a][b];
            }
          }
        }
      }
    }
  }
  mnum ret = 0;
  for(int i = 0; i < (1<<m); i++) {
    ret += dp[(m*n)%2][i][0][0];
    ret += dp[(m*n)%2][i][0][1];
    ret += dp[(m*n)%2][i][1][0];
    ret += dp[(m*n)%2][i][1][1];
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}