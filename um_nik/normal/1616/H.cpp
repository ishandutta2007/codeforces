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

struct TAns {
	Mint a[2];

	TAns() : a() {}
	TAns(Mint x, Mint y) {
		a[0] = x;
		a[1] = y;
	}

	TAns operator + (const TAns &T) const {
		TAns R = TAns();
		for (int i = 0; i < 2; i++)
			R.a[i] = a[i] + T.a[i];
		return R;
	}
	TAns operator * (const TAns &T) const {
		TAns R = TAns();
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				R.a[i | j] += a[i] * T.a[j];
		return R;
	}
};

Powers<> P = Powers(150000, Mint(2));
int m;
const int N = (int)5e6 + 3;
int g[N][2];
int cnt[N];


map<int, vector<int>> mapchik;
int X;

TAns dfs(int k, int Y, int v, int u) {
	if (v == 0 || u == 0) return TAns();
	k--;
	if (k < 0) {
		return TAns(0, (P.pow(cnt[v]) - 1) * (P.pow(cnt[u]) - 1));
	}
	if ((Y >> k) & 1) {
		TAns L = dfs(k, Y, g[v][0], g[u][1]), R = dfs(k, Y, g[v][1], g[u][0]);
		TAns ans = L * R;
		for (int c = 0; c < 2; c++) {
			int vv = g[v][c], uu = g[u][c];
			if (vv == 0 || uu == 0) continue;
			ans.a[0] += (P.pow(cnt[vv]) - 1) * (P.pow(cnt[uu]) - 1);
		}
		ans = ans + L + R;
		if (g[v][1] != 0) ans = ans + L * TAns(P.pow(cnt[g[v][1]]) - 1, 0);
		if (g[u][0] != 0) ans = ans + L * TAns(P.pow(cnt[g[u][0]]) - 1, 0);
		if (g[v][0] != 0) ans = ans + R * TAns(P.pow(cnt[g[v][0]]) - 1, 0);
		if (g[u][1] != 0) ans = ans + R * TAns(P.pow(cnt[g[u][1]]) - 1, 0);
		return ans;
	} else {
		return dfs(k, Y, g[v][0], g[u][0]) + dfs(k, Y, g[v][1], g[u][1]);
	}
}
Mint solve(int k, vector<int> A, vector<int> B) {
	if (X == (1 << k)) {
		return (P.pow((int)A.size()) - 1) * (P.pow((int)B.size()) - 1);
	}
	while(m > 0) {
		m--;
		g[m][0] = g[m][1] = cnt[m] = 0;
	}
	m++;
	int r1 = m++;
	for (int x : A) {
		int v = r1;
		cnt[v]++;
		for (int i = k - 1; i >= 0; i--) {
			int c = (x >> i) & 1;
			if (g[v][c] == 0) g[v][c] = m++;
			v = g[v][c];
			cnt[v]++;
		}
	}
	int r2 = m++;
	for (int x : B) {
		int v = r2;
		cnt[v]++;
		for (int i = k - 1; i >= 0; i--) {
			int c = (x >> i) & 1;
			if (g[v][c] == 0) g[v][c] = m++;
			v = g[v][c];
			cnt[v]++;
		}
	}
	Mint ans = 0;
	for (int i = 0; i < k; i++) if ((X >> i) & 1) {
		int y = X >> i;
		y--;
		TAns cur = dfs(k - i, y, r1, r2);
		ans += cur.a[1];
	}
	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d%d", &n, &X);
	int k = 0;
	while((1 << (k + 1)) <= X) k++;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		mapchik[x >> k].push_back(x - ((x >> k) << k));
	}
	Mint ans = 0;
	for (auto t : mapchik)
		ans += P.pow(t.second.size()) - 1;
	if (X == 0) {
		printf("%u\n", ans.x);
		return 0;
	}
	X ^= 1 << k;
	X++;
	for (auto t : mapchik) {
		int x = t.first;
		if (x & 1) continue;
		if (mapchik.count(x ^ 1) == 0) continue;
		ans += solve(k, mapchik[x], mapchik[x + 1]);
	}
	printf("%u\n", ans.x);

	return 0;
}