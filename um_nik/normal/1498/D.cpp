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

const ll C = (ll)1e5;
const int N = 100100;
int ans[N];
int n, m;
ll q[N][3];
vector<int> g[N];
int deg[N];
int par[N];
int a[N];
int st[N];
int sz;
int k;

void dfs(int v) {
	if (ans[v] != -1) {
		a[v]++;
		if (sz >= k) a[st[sz - k]]--;
	}
	st[sz++] = v;
	for (int u : g[v])
		dfs(u);
	sz--;
	if (sz > 0) a[st[sz - 1]] += a[v];
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		scanf("%lld%lld%lld", &q[i][0], &q[i][1], &q[i][2]);
	for (int i = 0; i <= n; i++)
		ans[i] = -1;
	ans[0] = 0;
	for (int t = 1; t <= m; t++) {
		for (int x = 0; x <= n; x++) {
			ll z = x;
			if (q[t][0] == 1) {
				z = (z * C + q[t][1] + C - 1) / C;
			} else {
				z = (z * q[t][1] + C - 1) / C;
			}
			z = min(z, (ll)n + 1);
			par[x] = z;
		}
		for (int v = 0; v <= n + 1; v++)
			deg[v] = 0;
		for (int v = 0; v <= n; v++)
			deg[par[v]]++;
		for (int v = 0; v <= n + 1; v++) {
			g[v].clear();
			g[v].reserve(deg[v]);
		}
		for (int v = 0; v <= n; v++)
			g[par[v]].push_back(v);
		sz = 0;
		k = q[t][2] + 1;
		for (int v = 0; v <= n + 1; v++)
			a[v] = 0;
		dfs(n + 1);
		for (int v = 0; v <= n; v++)
			if (ans[v] == -1 && a[v] > 0)
				ans[v] = t;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}