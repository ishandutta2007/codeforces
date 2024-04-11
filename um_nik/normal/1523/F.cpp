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

const int INF = (int)1e9 + 5;
const int N = 120;
const int M = (1 << 14) + 5;
int n, m;
int dp1[M][N];
int dp2[M][N];
int a[N][3];
int d[N][N];
int dMask[M][N];
pair<int, pii> ord[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i <= m; i++)
			dp1[mask][i] = INF;
		for (int i = 0; i < m; i++) {
			dp2[mask][i] = (mask == 0 ? 1 : -1);
		}
	}
	for (int i = 0; i < n; i++)
		dp1[1 << i][0] = 0;
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[m + i][0], &a[m + i][1]);
	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &ord[i].second.first, &ord[i].second.second, &ord[i].first);
	sort(ord, ord + m);
	for (int i = 0; i < m; i++) {
		a[i][0] = ord[i].second.first;
		a[i][1] = ord[i].second.second;
		a[i][2] = ord[i].first;
	}
	for (int i = 0; i < m + n; i++)
		for (int j = 0; j < m + n; j++)
			d[i][j] = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);

	for (int i = 0; i < m + n; i++) {
		for (int j = 0; j < m + n; j++)
			eprintf("%d ", d[i][j]);
		eprintf("\n");
	}

	for (int i = 0; i < m + n; i++)
		dMask[0][i] = INF;
	for (int mask = 1; mask < (1 << n); mask++) {
		int k = 0;
		while(((mask >> k) & 1) == 0) k++;
		for (int i = 0; i < n + m; i++)
			dMask[mask][i] = min(dMask[mask ^ (1 << k)][i], d[m + k][i]);
	}
	for (int mask = 0; mask < (1 << n); mask++) {
		eprintf("mask = %d\n", mask);
		for (int k = 0; k <= m; k++) {
			if (dp1[mask][k] == INF) continue;
			for (int i = 0; i < n; i++) {
				if ((mask >> i) & 1) continue;
				int t = dp1[mask][k] + dMask[mask][m + i];
				dp1[mask ^ (1 << i)][k] = min(dp1[mask ^ (1 << i)][k], t);
			}
			for (int i = 0; i < m; i++) {
				int t = dp1[mask][k] + dMask[mask][i];
				if (t <= a[i][2])
					dp2[mask][i] = max(dp2[mask][i], k + 1);
			}
		}
		for (int i = 0; i < m; i++) {
			if (dp2[mask][i] == -1) continue;
			for (int j = 0; j < n; j++) {
				if ((mask >> j) & 1) continue;
				int t = min(dMask[mask][m + j], d[i][m + j]);
				t += a[i][2];
				dp1[mask ^ (1 << j)][dp2[mask][i]] = min(dp1[mask ^ (1 << j)][dp2[mask][i]], t);
			}
			for (int j = i + 1; j < m; j++) {
				int t = min(dMask[mask][j], d[i][j]);
				t += a[i][2];
				if (t <= a[j][2])
					dp2[mask][j] = max(dp2[mask][j], dp2[mask][i] + 1);
			}
		}
	}
	int ans = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < m; i++)
			ans = max(ans, dp2[mask][i]);
	}
	printf("%d\n", ans);

	return 0;
}