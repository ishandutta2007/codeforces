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

const int N = 200200;
vector<int> g[N];
int n;
int a[N];
pii dp[N][2];

void dfs1(int v, int par) {
	dp[v][0] = mp(0, 0);
	dp[v][1] = mp(-1, (int)g[v].size());
	for (int u : g[v]) if (u != par) {
		dfs1(u, v);
		dp[v][1].first += dp[u][0].first;
		dp[v][1].second += dp[u][0].second;
		pii t = min(dp[u][0], dp[u][1]);
		dp[v][0].first += t.first;
		dp[v][0].second += t.second;
	}
}
void dfs2(int v, int par, int k) {
	if (k == 0) {
		a[v] = 1;
	} else {
		a[v] = (int)g[v].size();
	}
	for (int u : g[v]) if (u != par) {
		if (k == 1) {
			dfs2(u, v, 0);
		} else {
			if (dp[u][0] < dp[u][1])
				dfs2(u, v, 0);
			else
				dfs2(u, v, 1);
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	if (n == 2) {
		printf("2 2\n");
		printf("1 1\n");
		return 0;
	}
	dfs1(0, -1);
	if (dp[0][0] < dp[0][1]) {
		printf("%d %d\n", -dp[0][0].first, dp[0][0].second + dp[0][0].first + n);
		dfs2(0, -1, 0);
	} else {
		printf("%d %d\n", -dp[0][1].first, dp[0][1].second + dp[0][1].first + n);
		dfs2(0, -1, 1);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}