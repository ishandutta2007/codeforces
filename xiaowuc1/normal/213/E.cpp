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

const int STRING_SZ = 200000;
typedef modnum<1000000009> mnum1;
typedef modnum<1000000007> mnum2;
typedef pair<mnum1, mnum2> shash;
const mnum1 HASH1 = 295111;
const mnum2 HASH2 = 210533;
mnum1 hash1pows[STRING_SZ+1];
mnum2 hash2pows[STRING_SZ+1];
void init() {
  hash1pows[0] = 1;
  for(int i = 1; i <= STRING_SZ; i++) hash1pows[i] = hash1pows[i-1] * HASH1;
  hash2pows[0] = 1;
  for(int i = 1; i <= STRING_SZ; i++) hash2pows[i] = hash2pows[i-1] * HASH2;
}

struct state {
  shash actualhash;
  int numchars;
  state(shash s = shash(0, 0), int n = 0) {
    actualhash = s;
    numchars = n;
  }
};

const int RAGETREE_SZ = 1 << 18;
state ragetree[2 * RAGETREE_SZ];

inline state merge(const state& a, const state& b) {
  state ret;
  ret.actualhash = shash(
    a.actualhash.first * hash1pows[b.numchars] + b.actualhash.first,
    a.actualhash.second * hash2pows[b.numchars] + b.actualhash.second
  );
  ret.numchars = a.numchars + b.numchars;
  return ret;
}

void upd(int idx, int pos, int sz, int i, int val) {
  int rpos = pos + sz - 1;
  if(i < pos || i > rpos) return;
  if(pos == rpos) {
    ragetree[idx] = state(shash(val, val), 1);
    return;
  }
  upd(2*idx, pos, sz/2, i, val);
  upd(2*idx+1, pos + sz/2, sz/2, i, val);
  ragetree[idx] = merge(ragetree[2*idx], ragetree[2*idx+1]);
}
void upd(int idx, int val) {
  upd(1, 0, RAGETREE_SZ, idx, val);
}
void del(int idx, int pos, int sz, int i) {
  int rpos = pos + sz - 1;
  if(i < pos || i > rpos) return;
  if(pos == rpos) {
    assert(ragetree[idx].numchars == 1);
    ragetree[idx] = state(shash(0, 0), 0);
    return;
  }
  del(2*idx, pos, sz/2, i);
  del(2*idx+1, pos + sz/2, sz/2, i);
  ragetree[idx] = merge(ragetree[2*idx], ragetree[2*idx+1]);
}
void del(int idx) {
  del(1, 0, RAGETREE_SZ, idx);
}

vector<int> read(int n) {
  vector<int> ret(n);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ret[--x] = i;
  }
  return ret;
}

void solve() {
  init();
  int n, m;
  cin >> n >> m;
  shash want = shash(0, 0);
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    x--;
    want.first *= HASH1;
    want.first += x;
    want.second *= HASH2;
    want.second += x;
  }
  vector<int> bperm = read(m);
  int ret = 0;
  for(int i = 0; i < m; i++) {
    if(i >= n) {
      del(bperm[i-n]);
    }
    upd(bperm[i], i);
    if(i >= n-1) {
      assert(ragetree[1].numchars == n);
      if(ragetree[1].actualhash == want) ret++;
      want.first += (hash1pows[n]-1) / mnum1(HASH1 - 1);
      want.second += (hash2pows[n]-1) / mnum2(HASH2 - 1);
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}