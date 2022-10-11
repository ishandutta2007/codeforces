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

mnum solve(vector<ll>& vals, vector<ll>& added) {
  mnum ret = 0;
  for(int bit = 0; bit < 60; bit++) {
    ll have = 0;
    ll havenot = 0;
    bool canSwap = false;
    for(ll out: added) {
      canSwap |= (out & (1LL << bit));
    }
    for(ll out: vals) {
      (((out & (1LL << bit))) ? have : havenot)++;
    }
    mnum scale = mnum(1LL << sz(added));
    if(canSwap) {
      mnum amt = sz(vals);
      amt *= sz(vals)-1;
      amt /= 2;
      amt *= (1LL << bit);
      amt *= scale;
      amt /= 2;
      ret += amt;
    }
    else {
      mnum amt = have;
      amt *= havenot;
      amt *= (1LL << bit);
      amt *= scale;
      ret += amt;
    }
  }
  return ret;
}

void basis(vector<ll>& cycles) {
  int row = 0;
  for(int j = 0; row < sz(cycles) && j < 60; j++) {
    for(int i = row; i < sz(cycles); i++) {
      if(cycles[i] & (1LL << j)) {
        if(i == row) break;
        else {
          swap(cycles[i], cycles[row]);
          break;
        }
      }
    }
    if(cycles[row] & (1LL << j)) {
      for(int i = row+1; i < sz(cycles); i++) {
        if(cycles[i] & (1LL << j)) cycles[i] ^= cycles[row];
      }
      row++;
    }
  }
  cycles.resize(row);
}

vector<pll> edges[100005];
ll orig[100005];
bool seen[100005];

void dfs(int curr, int par, vector<ll>& init, vector<ll>& cycles) {
  for(pll out: edges[curr]) {
    if(out.first == par) continue;
    if(!seen[out.first]) { // never seen
      seen[out.first] = true;
      orig[out.first] = orig[curr] ^ out.second;
      init.push_back(orig[out.first]);
      dfs(out.first, curr, init, cycles);
    }
    else { // have seen
      cycles.push_back(orig[curr] ^ orig[out.first] ^ out.second);
    }
  }
}
mnum gen(int src) {
  vector<ll> init;
  init.push_back(0);
  vector<ll> cycles;
  seen[src] = true;
  dfs(src, -1, init, cycles);
  basis(cycles);
  return solve(init, cycles);
}

void solve() {
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    edges[a].push_back({b, w});
    edges[b].push_back({a, w});
  }
  mnum ret = 0;
  for(int i = 1; i <= n; i++) {
    if(seen[i]) continue;
    ret += gen(i);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}