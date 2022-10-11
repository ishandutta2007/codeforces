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

typedef long long ll;
typedef pair<int, int> pii;

const int STRING_SZ = 200000;
typedef modnum<998244353> mnum1;
typedef modnum<1000000007> mnum2;
typedef pair<mnum1, mnum2> shash;
const mnum1 HASH1 = 3137;
const mnum2 HASH2 = 1009;
mnum1 hash1pows[STRING_SZ+1];
mnum2 hash2pows[STRING_SZ+1];
shash hashes[STRING_SZ+1][26];
string s;
void init() {
  hash1pows[0] = 1;
  for(int i = 1; i <= STRING_SZ; i++) hash1pows[i] = hash1pows[i-1] * HASH1;
  hash2pows[0] = 1;
  for(int i = 1; i <= STRING_SZ; i++) hash2pows[i] = hash2pows[i-1] * HASH2;
}
inline shash getHash(int lhs, int rhs, int idx) {
  // [lhs, rhs)
  mnum1 a = hashes[rhs][idx].first - hashes[lhs][idx].first * hash1pows[rhs-lhs];
  mnum2 b = hashes[rhs][idx].second - hashes[lhs][idx].second * hash2pows[rhs-lhs];
  return {a, b};
}
void genHash() {
  for(int ch = 'a'; ch <= 'z'; ch++) {
    for(int i = 0; i < sz(s); i++) {
      hashes[i+1][ch-'a'].first = hashes[i][ch-'a'].first * HASH1;
      hashes[i+1][ch-'a'].second = hashes[i][ch-'a'].second * HASH2;
      if(s[i] == ch) {
        hashes[i+1][ch-'a'].first++;
        hashes[i+1][ch-'a'].second++;
      }
    }
  }
}
vector<pii> gen(int x, int l) {
  vector<pii> ret;
  for(int i = 0; i < 26; i++) {
    shash curr = getHash(x, x+l, i);
    ret.push_back({(int)curr.first, (int)curr.second});
  }
  sort(ret.begin(), ret.end());
  return ret;
}

void solve() {
  init();
  int n, q;
  cin >> n >> q >> s;
  genHash();
  while(q--) {
    int x, y, l;
    cin >> x >> y >> l;
    if(gen(--x, l) == gen(--y, l)) cout << "YES\n";
    else cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}