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


const uint MOD = 3;
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
using Mint = mint<>;

const int N = 260;
const int M = 20200;
int id[N];
int val[N];
int G[N][N];
Mint g[M][N];
int myVar[N];
int n, m, k, d;

void solve() {
	scanf("%d%d", &n, &m);
	k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G[i][j] = -1;
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d%d", &v, &u, &val[i]);
		val[i]--;
		v--;u--;
		if (val[i] < 0) {
			id[i] = k++;
			val[i] = 0;
		} else {
			id[i] = -1;
		}
		G[v][u] = G[u][v] = i;
	}
	d = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j <= k; j++)
			g[i][j] = 0;
	for (int v = 0; v < n; v++)
		for (int u = v + 1; u < n; u++) if (G[v][u] != -1)
			for (int w = u + 1; w < n; w++) if (G[v][w] != -1 && G[u][w] != -1) {
				vector<int> cur = {G[v][u], G[v][w], G[u][w]};
				for (int p : cur) {
					if (id[p] == -1) {
						g[d][k] -= Mint(val[p]);
					} else {
						g[d][id[p]] += Mint(1);
					}
				}
				d++;
			}
	swap(m, d);
	n = k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= n; j++)
			eprintf("%d ", g[i][j].x);
		eprintf("\n");
	}
	for (int i = 0; i < n; i++)
		myVar[i] = -1;
	k = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = k; j < m; j++)
			if (g[j][i] != 0)
				v = j;
		if (v == -1) continue;
		myVar[i] = k;
		swap(g[v], g[k]);
		Mint x = g[k][i].inv();
		for (int j = i; j <= n; j++)
			g[k][j] *= x;
		for (int p = 0; p < m; p++) {
			if (p == k) continue;
			x = g[p][i];
			for (int j = i; j <= n; j++)
				g[p][j] -= g[k][j] * x;
		}
		k++;
	}
	for (int i = k; i < m; i++)
		if (g[i][n] != 0) {
			printf("-1\n");
			return;
		}
	swap(m, d);
	for (int i = 0; i < m; i++) {
		if (id[i] != -1 && myVar[id[i]] != -1) {
			val[i] = g[myVar[id[i]]][n].x;
		}
		printf("%d ", val[i] + 1);
	}
	printf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}