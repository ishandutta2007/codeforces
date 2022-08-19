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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 998244353;
const ll M2 = MOD * MOD;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x > 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = 1010;
const int S = 64;
const int LOG = 32;
ll A[LOG + 3][S + 1][S + 1];
int f[3][3];
ll w[2][S + 1];
ll dp[2][4];
int n;
int sz[N];
vector<pii> a[N];

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &sz[i]);
		a[i].push_back(mp(0, -1));
		a[i].push_back(mp(sz[i] + 1, -1));
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		x--;c--;
		a[x].push_back(mp(y, c));
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			scanf("%d", &f[i][j]);
		}
	for (int i = 0; i < n; i++)
		sort(a[i].begin(), a[i].end());
	for (int c = 0; c < 3; c++) {
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++) 
				for (int z = 0; z < 4; z++) {
					int v = 16 * x + 4 * y + z;
					int r = 0;
					while(true) {
						if (r == x && f[c][2] == 1) {
							r++; continue;
						}
						if (r == y && f[c][1] == 1) {
							r++; continue;
						}
						if (r == z && f[c][0] == 1) {
							r++; continue;
						}
						break;
					}
					r += 16 * y + 4 * z;
					A[LOG + c][v][r]++;
				}
		for (int i = 0; i < S; i++)
			for (int j = 0; j < S; j++)
				A[0][i][j] += A[LOG + c][i][j];
	}
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 0; i < S; i++)
			for (int j = 0; j < S; j++) {
				A[k + 1][i][j] = 0;
				for (int h = 0; h < S; h++) {
					A[k + 1][i][j] += A[k][i][h] * A[k][h][j];
					if (A[k + 1][i][j] >= M2) A[k + 1][i][j] -= M2;
				}
				A[k + 1][i][j] %= MOD;
			}
}

void apply(int id) {
	for (int i = 0; i < S; i++) {
		w[1][i] = 0;
		for (int j = 0; j < S; j++) {
			w[1][i] += w[0][j] * A[id][j][i];
			if (w[1][i] >= M2) w[1][i] -= M2;
		}
		w[1][i] %= MOD;
	}
	for (int i = 0; i < S; i++)
		w[0][i] = w[1][i];
}

void bin_pow(int p) {
	for (int k = 0; k < LOG; k++)
		if ((p >> k) & 1)
			apply(k);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	dp[0][0] = 1;
	for (int id = 0; id < n; id++) {
		for (int i = 0; i < S; i++)
			w[0][i] = 0;
		w[0][S - 1] = 1;
		for (int i = 0; i < (int)a[id].size() - 1; i++) {
			bin_pow(a[id][i + 1].first - a[id][i].first - 1);
			if (i != (int)a[id].size() - 2)
				apply(LOG + a[id][i + 1].second);
		}
		ll z[4];
		for (int i = 0; i < 4; i++)
			z[i] = 0;
		for (int i = 0; i < 4; i++)
			for (int j = i; j < S; j += 4)
				z[i] = add(z[i], w[0][j]);
		for (int i = 0; i < 4; i++)
			dp[1][i] = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				dp[1][i ^ j] = add(dp[1][i ^ j], mult(dp[0][i], z[j]));
		for (int i = 0; i < 4; i++)
			dp[0][i] = dp[1][i];
	}
	printf("%lld\n", dp[0][0]);

	return 0;
}