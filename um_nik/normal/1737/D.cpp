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

const ll INF = (ll)1e18;
const int N = 505;
int g[N][N];
int ed[N * N][3];
int n, m;

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = N;
	for (int i = 0; i < n; i++)
		g[i][i] = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ed[i][0], &ed[i][1], &ed[i][2]);
		ed[i][0]--;
		ed[i][1]--;
		g[ed[i][0]][ed[i][1]] = min(1, g[ed[i][0]][ed[i][1]]);
		g[ed[i][1]][ed[i][0]] = min(1, g[ed[i][1]][ed[i][0]]);
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	ll ans = INF;
	for (int i = 0; i < m; i++) {
		int v = ed[i][0], u = ed[i][1];
		ans = min(ans, (ll)ed[i][2] * (1 + g[v][0] + g[u][n - 1]));
		ans = min(ans, (ll)ed[i][2] * (1 + g[v][n - 1] + g[u][0]));
		for (int w = 0; w < n; w++)
			ans = min(ans, (ll)ed[i][2] * (g[w][0] + g[w][n - 1] + min(g[w][v], g[w][u]) + 2));
	}
	printf("%lld\n", ans);
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