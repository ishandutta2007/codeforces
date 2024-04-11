#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


const uint MOD = 998244353;
template<uint mod = MOD> struct mint { // 1000000007  1000000009
	uint x;

	mint() : x(0) {}
	mint(ll _x) {
		_x %= mod;
		if (_x < 0) _x += mod;
		x = _x;
	}

	mint& operator += (const mint &a) {
		x += a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator -= (const mint &a) {
		x += mod - a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator *= (const mint &a) {
		x = (ull)x * a.x % mod;
		return *this;
	}
	mint pow(ll pw) const {
		mint res = 1;
		mint cur = *this;
		while(pw) {
			if (pw & 1) res *= cur;
			cur *= cur;
			pw >>= 1;
		}
		return res;
	}
	mint inv() const {
		assert(x != 0);
		uint t = x;
		uint res = 1;
		while(t != 1) {
			uint z = mod / t;
			res = (ull)res * (mod - z) % mod;
			t = mod - t * z;
		}
		return res;
	}
	mint& operator /= (const mint &a) {
		return *this *= a.inv();
	}
	mint operator + (const mint &a) const {
		return mint(*this) += a;
	}
	mint operator - (const mint &a) const {
		return mint(*this) -= a;
	}
	mint operator * (const mint &a) const {
		return mint(*this) *= a;
	}
	mint operator / (const mint &a) const {
		return mint(*this) /= a;
	}

	bool sqrt(mint &res) const {
		if (mod == 2 || x == 0) {
			res = *this;
			return true;
		}
		if (pow((mod - 1) / 2) != 1) return false;
		if (mod % 4 == 3) {
			res = pow((mod + 1) / 4);
			return true;
		}
		int pw = (mod - 1) / 2;
		int K = 30;
		while((1 << K) > pw) K--;
		while(true) {
			mint t = myRand(mod);
			mint a = 0, b = 0, c = 1;
			for (int k = K; k >= 0; k--) {
				a = b * b;
				b = b * c * 2;
				c = c * c + a * *this;
				if (((pw >> k) & 1) == 0) continue;
				a = b;
				b = b * t + c;
				c = c * t + a * *this;
			}
			if (b == 0) continue;
			c -= 1;
			c *= mint() - b.inv();
			if (c * c == *this) {
				res = c;
				return true;
			}
		}
		assert(false);
	}

	bool operator == (const mint &a) const {
		return x == a.x;
	}
	bool operator != (const mint &a) const {
		return x != a.x;
	}
	bool operator < (const mint &a) const {
		return x < a.x;
	}
};
template<uint mod = MOD> struct Factorials {
	using Mint = mint<mod>;
	vector<Mint> f, fi;

	Factorials() : f(), fi() {}
	Factorials(int n) {
		n += 10;
		f = vector<Mint>(n);
		fi = vector<Mint>(n);
		f[0] = 1;
		for (int i = 1; i < n; i++)
			f[i] = f[i - 1] * i;
		fi[n - 1] = f[n - 1].inv();
		for (int i = n - 1; i > 0; i--)
			fi[i - 1] = fi[i] * i;
	}

	Mint C(int n, int k) {
		if (k < 0 || k > n) return 0;
		return f[n] * fi[k] * fi[n - k];
	}
};
template<uint mod = MOD> struct Powers {
	using Mint = mint<mod>;
	vector<Mint> p, pi;

	Powers() : p(), pi() {}
	Powers(int n, Mint x) {
		n += 10;
		if (x == 0) {
			p = vector<Mint>(n);
			p[0] = 1;
		} else {
			p = vector<Mint>(n);
			pi = vector<Mint>(n);
			p[0] = pi[0] = 1;
			Mint xi = x.inv();
			for (int i = 1; i < n; i++) {
				p[i] = p[i - 1] * x;
				pi[i] = pi[i - 1] * xi;
			}
		}
	}

	Mint pow(int n) {
		if (n >= 0)
			return p[n];
		else
			return pi[-n];
	}
};
template<uint mod = MOD> struct Inverses {
	using Mint = mint<mod>;
	vector<Mint> ii;

	Inverses() : ii() {}
	Inverses(int n) {
		n += 10;
		ii = vector<Mint>(n);
		ii[1] = 1;
		for (int x = 2; x < n; x++)
			ii[x] = Mint() - ii[mod % x] * (mod / x);
	}

	Mint inv(Mint x) {
		assert(x != 0);
		uint t = x.x;
		uint res = 1;
		while(t >= (int)ii.size()) {
			uint z = mod / t;
			res = (ull)res * (mod - z) % mod;
			t = mod - t * z;
		}
		return ii[t] * res;
	}
};
using Mint = mint<>;

const int K = 23;
const int M = (1 << 18) + 5;
const int N = 300300;
int d, n, m;
int aa[N];
int b[K];
Mint A[M];
Mint B[K][K][K];
Mint ANS[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &d, &n, &m);

	A[0] = 1;
	for (int mask = 1; mask < (1 << m); mask++) {
		A[mask] = A[mask >> 1];
		if (mask & 1) A[mask] *= -1;
	}

	d++;
	for (int i = 0; i < n; i++)
		scanf("%d", &aa[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	sort(b, b + m);
	for (int i = m; i > 0; i--)
		b[i] = b[i - 1];
	b[0] = -d;
	b[m + 1] = 2 * N + d;
	for (int k = 1; k <= m + 1; k++) {
		for (int i = 0; i < k; i++)
			for (int j = k; j <= m + 1; j++) {
				B[k][i][j] = 1;
			}
		for (int it = 0; it < n; it++) {
			if (aa[it] > b[k] || aa[it] < b[k - 1]) continue;
			for (int i = 0; i < k; i++)
				for (int j = k; j <= m + 1; j++) {
					int z = d;
					z = min(z, aa[it] - b[i]);
					z = min(z, b[j] - aa[it]);
					B[k][i][j] *= z;
				}
		}
		for (int mask = 0; mask < (1 << m); mask++) {
			int p = 0, q = m + 1;
			for (int i = 0; i < m; i++) if ((mask >> i) & 1) {
				if (i + 1 < k)
					p = max(p, i + 1);
				else
					q = min(q, i + 1);
			}
			A[mask] *= B[k][p][q];
		}
	}
	for (int k = 1; k <= m + 1; k++) {
		for (int i = 0; i < k; i++)
			for (int j = k; j <= m + 1; j++) {
				B[k][i][j] = 0;
			}
		for (int mask = 0; mask < (1 << m); mask++) {
			int p = 0, q = m + 1;
			for (int i = 0; i < m; i++) if ((mask >> i) & 1) {
				if (i + 1 < k)
					p = max(p, i + 1);
				else
					q = min(q, i + 1);
			}
			B[k][p][q] += A[mask];
		}
		for (int x = max(0, b[k - 1]); x <= min(d, b[k]); x++) {
			ANS[x] = 0;
			for (int i = 0; i < k; i++)
				for (int j = k; j <= m + 1; j++) {
					int z = d;
					z = min(z, x - b[i]);
					z = min(z, b[j] - x);
					ANS[x] += B[k][i][j] * z;
				}
		}
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int x;
		scanf("%d", &x);
		printf("%u\n", ANS[x].x);
	}


	return 0;
}