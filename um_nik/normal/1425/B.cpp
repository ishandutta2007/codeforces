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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
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


const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}


const int N = 2020;
const int M = 4040;
vector<int> g[N];
bool used[N];
vector<int> a;
int n, m;
int dpPref[N][2 * M];
int dpSuf[N][2 * M];
int p[2 * M];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int x : g[0]) {
		if (used[x]) continue;
		int v = x;
		int u = 0;
		int len = 1;
		while(v != 0) {
			used[v] = 1;
			u ^= g[v][0] ^ g[v][1];
			swap(v, u);
			len++;
		}
		a.push_back(len);
	}

	for (int x : a)
		eprintf("%d ", x);
	eprintf("\n");

	n = (int)a.size();
	dpPref[0][M] = 1;
	for (int i = 0; i < n; i++) {
		for (int x = M - m; x <= M + m; x++) {
			if (dpPref[i][x] == 0) continue;
			for (int j = -1; j <= 1; j++)
				dpPref[i + 1][x + j * a[i]] = add(dpPref[i + 1][x + j * a[i]], dpPref[i][x]);
		}
	}
	dpSuf[n][M] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int x = M - m; x <= M + m; x++) {
			if (dpSuf[i + 1][x] == 0) continue;
			for (int j = -1; j <= 1; j++)
				dpSuf[i][x + j * a[i]] = add(dpSuf[i][x + j * a[i]], dpSuf[i + 1][x]);
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int w = a[i] - 2;
		for (int j = 0; j < 2 * M; j++)
			p[j] = 0;
		for (int j = 0; j < 2 * M - 1; j++)
			p[j + 1] = add(p[j], dpSuf[i + 1][j]);
		for (int x = M - m; x <= M + m; x++) {
			if (dpPref[i][x] == 0) continue;
			int l = -w - x + 2 * M, r = w - x + 2 * M;
			ans = add(ans, mult(mult(2, dpPref[i][x]), sub(p[r + 1], p[l])));
//			eprintf("after %d %d : %d\n", i, x - M, ans);
		}
	}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 2 * M; j++)
			dpPref[i][j] = dpSuf[i][j] = 0;

	dpPref[0][M] = 1;
	for (int i = 0; i < n; i++) {
		for (int x = M - m; x <= M + m; x++) {
			if (dpPref[i][x] == 0) continue;
			for (int j = -1; j <= 1; j += 2)
				dpPref[i + 1][x + j * a[i]] = add(dpPref[i + 1][x + j * a[i]], dpPref[i][x]);
		}
	}
	dpSuf[n][M] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int x = M - m; x <= M + m; x++) {
			if (dpSuf[i + 1][x] == 0) continue;
			for (int j = -1; j <= 1; j += 2)
				dpSuf[i][x + j * a[i]] = add(dpSuf[i][x + j * a[i]], dpSuf[i + 1][x]);
		}
	}

	ans = add(ans, dpPref[n][M]);
	for (int i = 0; i < n; i++) {
		int w = a[i] - 1;
		for (int x = M - m; x <= M + m; x++) {
			if (dpPref[i][x] == 0) continue;
			int y = 2 * M - x;
			ans = add(ans, mult(2, mult(dpPref[i][x], dpSuf[i + 1][y - w])));
			ans = add(ans, mult(2, mult(dpPref[i][x], dpSuf[i + 1][y + w])));
		}
	}

	printf("%d\n", ans);

	return 0;
}