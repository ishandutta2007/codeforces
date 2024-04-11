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

const int INF = 100100;
const int N = 15;
const int M = (1 << 14) + 7;
bool g[N][N];
int n, m;
int edgesToMask[N][M];
vector<int> pathInMask[M][N][N];
int dp[M];
int par[M][3];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v][u] = g[u][v] = 1;
	}
	for (int v = 0; v < n; v++)
		for (int mask = 0; mask < (1 << n); mask++)
			for (int u = 0; u < n; u++) {
				if (((mask >> u) & 1) == 0) continue;
				if (g[v][u])
					edgesToMask[v][mask]++;
			}
	for (int v = 0; v < n; v++)
		pathInMask[1 << v][v][v].push_back(v);
	for (int mask = 0; mask < (1 << n); mask++) {
		//cerr << mask << endl;
		for (int v = 0; v < n; v++)
			for (int u = 0; u < n; u++) {
				if (pathInMask[mask][v][u].empty()) continue;
				for (int w = 0; w < n; w++) {
					if ((mask >> w) & 1) continue;
					if (!g[u][w]) continue;
					int nmask = mask | (1 << w);
					if (!pathInMask[nmask][v][w].empty()) continue;
					pathInMask[nmask][v][w] = pathInMask[mask][v][u];
					pathInMask[nmask][v][w].push_back(w);
				}
			}
	}

	for (int mask = 0; mask < (1 << n); mask++)
		dp[mask] = INF;
	dp[1] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		//cerr << mask << endl;
		if (dp[mask] == INF) continue;
		for (int v = 0; v < n; v++) {
			if ((mask >> v) & 1) continue;
			if (edgesToMask[v][mask] >= 2) {
				int nmask = mask | (1 << v);
				if (dp[nmask] > dp[mask] + 2) {
					dp[nmask] = dp[mask] + 2;
					par[nmask][0] = mask;
					par[nmask][1] = par[nmask][2] = v;
				}
			}
			if (edgesToMask[v][mask] == 0) continue;
			for (int u = v + 1; u < n; u++) {
				if ((mask >> u) & 1) continue;
				if (edgesToMask[u][mask] == 0) continue;
				int all = ((1 << n) - 1) ^ mask ^ (1 << v) ^ (1 << u);
				for (int smask = all;; smask = (smask - 1) & all) {
					int nmask = smask | (1 << v) | (1 << u);
					if (!pathInMask[nmask][v][u].empty()) {
						int w = dp[mask] + (int)pathInMask[nmask][v][u].size() + 1;
						if (w < dp[mask | nmask]) {
							dp[mask | nmask] = w;
							par[mask | nmask][0] = mask;
							par[mask | nmask][1] = v;
							par[mask | nmask][2] = u;
						}
					}
					if (smask == 0) break;
				}
			}
		}
	}

	printf("%d\n", dp[(1 << n) - 1]);
//	fflush(stdout);
	int mask = (1 << n) - 1;
	while(mask > 1) {
		//cerr << mask << endl;
		//return 0;
		int nmask = par[mask][0];
		int v = par[mask][1];
		int u = par[mask][2];
		if (v == u) {
			int cnt = 0;
			for (int z = 0; cnt < 2 && z < n; z++) {
				if (((nmask >> z) & 1) == 0) continue;
				if (!g[v][z]) continue;
				cnt++;
				printf("%d %d\n", v + 1, z + 1);
			}
			if (cnt != 2) throw;
		} else {
			for (int z = 0; z < n; z++) {
				if (((nmask >> z) & 1) == 0) continue;
				if (!g[v][z]) continue;
				printf("%d %d\n", v + 1, z + 1);
				break;
			}
			for (int z = 0; z < n; z++) {
				if (((nmask >> z) & 1) == 0) continue;
				if (!g[u][z]) continue;
				printf("%d %d\n", u + 1, z + 1);
				break;
			}
			vector<int> z = pathInMask[mask ^ nmask][v][u];
			for (int i = 0; i < (int)z.size() - 1; i++) {
				printf("%d %d\n", z[i] + 1, z[i + 1] + 1);
			}
		}
		mask = nmask;
	}

	return 0;
}