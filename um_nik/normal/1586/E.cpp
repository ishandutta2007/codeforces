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

const int N = 300300;
int n, m, q;
vector<int> g[N];
int par[N];
int h[N];
int ans[2][N], ansSz[2];
int a[N];
int b[N][2];

void dfs(int v) {
	for (int u : g[v]) {
		if (par[u] != 0) continue;
		par[u] = v;
		h[u] = h[v] + 1;
		dfs(u);
	}
}
void printPath(int v, int u) {
	ansSz[0] = ansSz[1] = 0;
	while(v != u) {
		if (h[v] > h[u]) {
			ans[0][ansSz[0]++] = v;
			v = par[v];
		} else {
			ans[1][ansSz[1]++] = u;
			u = par[u];
		}
	}
	ans[0][ansSz[0]++] = v;
	while(ansSz[1] > 0) {
		ansSz[1]--;
		ans[0][ansSz[0]++] = ans[1][ansSz[1]];
	}
	printf("%d\n", ansSz[0]);
	for (int i = 0; i < ansSz[0]; i++)
		printf("%d ", ans[0][i]);
	printf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	par[1] = -1;
	dfs(1);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &b[i][j]);
			a[b[i][j]] ^= 1;
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i];
	if (sum == 0) {
		printf("YES\n");
		for (int i = 0; i < q; i++)
			printPath(b[i][0], b[i][1]);
	} else {
		printf("NO\n%d\n", sum / 2);
	}

	return 0;
}