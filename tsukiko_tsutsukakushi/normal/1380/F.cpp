//from jupiro
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>
#include <numeric>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int inf = 1000000007;
//constexpr long long mod = 1000000007LL;
constexpr long long mod = 998244353LL;
const long double PI = acos((long double)(-1));

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

struct mint {
	long long x;
	mint(long long x = 0) :x((x% mod + mod) % mod) {}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const {
		mint res(*this);
		return res *= a;
	}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const {
		return pow(mod - 2);
	}
	mint& operator/=(const mint a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint a) const {
		mint res(*this);
		return res /= a;
	}
};


using mat = array<array<mint, 2>, 2>;
mat uni = { { { 1, 0 }, { 0, 1 } } };

mat f(mat &a, mat &b) {
	mat res = {};
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) res[i][j] += b[i][k] * a[k][j];
	return res;
}

template< typename Monoid >
struct SegmentTree {
	//using F = function< Monoid(Monoid, Monoid) >;

	int sz;
	vector< Monoid > seg;

	//const F f;
	const Monoid M1;

	SegmentTree(int n, /*const F f,*/ const Monoid& M1) : /*f(f),*/ M1(M1) {
		sz = 1;
		while (sz < n) sz <<= 1;
		seg.assign(2 * sz, M1);
	}

	void set(int k, const Monoid& x) {
		seg[k + sz] = x;
	}

	void build() {
		for (int k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	void update(int k, const Monoid& x) {
		k += sz;
		seg[k] = x;
		while (k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	Monoid query(int a, int b) {
		Monoid L = M1, R = M1;
		if (a >= b) return M1;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) L = f(L, seg[a++]);
			if (b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}
};

mint v[100];

mat generate(string& s, int i) {
	mat res; res[0][0] = v[s[i] - '0'], res[1][0] = 1, res[1][1] = 0;
	if (i == 0) res[0][1] = 0;
	else if (s[i - 1] != '0') res[0][1] = v[stoi(s.substr(i - 1, 2))];
	else res[0][1] = 0;
	return res;
}

int main()
{
    
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
	int n;
	string s;
	int kkt;
	cin >> n >> kkt >> s;
	SegmentTree<mat> seg(n, uni);
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) v[i + j] += 1;
	for (int i = 0; i < s.size(); i++) {
		seg.set(i, generate(s, i));
	}
	seg.build();
	while (kkt--) {
		int x;
		char d;
		cin >> x >> d;
		x--;
		s[x] = d;
		seg.update(x, generate(s, x));
		if(x + 1 < n) seg.update(x + 1, generate(s, x + 1));
		auto m = seg.seg[1];
		mint res = m[0][0] + m[0][1];
		printf("%d\n", (int)res.x);
	}
    return 0;
}