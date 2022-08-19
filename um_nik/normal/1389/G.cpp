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

const int N = 300300;
int n, m, k;
vector<int> g[N];
vector<pii> G[N];
int cntSpec[N];
ll sumVal[N];
int h[N];
int minH[N];
int root;
int ed[N][3];
bool isBridge[N];
int myComp[N];
ll val[N];
map<pii, ll> dp;
int deg[N];
ll ans[N];
int q[2 * N];
int topQ;

int getOther(int id, int v) {
	return ed[id][0] ^ ed[id][1] ^ v;
}

void dfs1(int v) {
//	eprintf("dfs1 %d %d\n", v, h[v]);
	minH[v] = h[v];
	for (int id : g[v]) {
		int u = getOther(id, v);
		if (h[u] != -1) {
			if (h[u] != h[v] - 1)
				minH[v] = min(minH[v], h[u]);
			continue;
		}
		h[u] = h[v] + 1;
		dfs1(u);
		cntSpec[v] += cntSpec[u];
//		sumVal[v] += sumVal[u];
		minH[v] = min(minH[v], minH[u]);
		if (minH[u] > h[v] && cntSpec[u] > 0) {
			isBridge[id] = 1;
		}
	}
}
void dfsComp(int v) {
	myComp[v] = k;
	val[k] += sumVal[v];
	for (int id : g[v]) {
		if (isBridge[id]) continue;
		int u = getOther(id, v);
		if (myComp[u] == -1)
			dfsComp(u);
	}
}

void solve(int v) {
	if (deg[v] == 1) {
		pii u = mp(-1, -1);
		ll sum = val[v];
		for (pii e : G[v]) {
			int w = e.first;
			if (dp.count(mp(v, w))) {
				sum += dp[mp(v, w)];
			} else {
				u = e;
			}
		}
		if (u.first != -1) {
			int w = u.first;
			sum = max(0LL, sum - u.second);
			dp[mp(w, v)] = sum;
			deg[w]--;
			if (deg[w] <= 1) q[topQ++] = w;
		}
	} else if (deg[v] == 0) {
		ll sum = val[v];
		for (pii e : G[v]) {
			int w = e.first;
			sum += dp[mp(v, w)];
		}
		for (pii e : G[v]) {
			int w = e.first;
			if (dp.count(mp(w, v))) continue;
			dp[mp(w, v)] = max(0LL, sum - dp[mp(v, w)] - e.second);
			deg[w]--;
			if (deg[w] <= 1) q[topQ++] = w;
		}
	} else throw;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		x--;
		root = x;
		cntSpec[x]++;
	}
	for (int i = 0; i < n; i++)
		scanf("%lld", &sumVal[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &ed[i][2]);
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		ed[i][0] = v;
		ed[i][1] = u;
		g[v].push_back(i);
		g[u].push_back(i);
	}
	k = 0;
	for (int i = 0; i < n; i++)
		h[i] = -1;
	h[root] = 0;
	dfs1(root);
	/*
	for (int i = 0; i < m; i++)
		eprintf("%d", (int)isBridge[i]);
	eprintf("\n");
	*/
	for (int v = 0; v < n; v++)
		myComp[v] = -1;
	for (int v = 0; v < n; v++) {
		if (myComp[v] != -1) continue;
		dfsComp(v);
		k++;
	}
	for (int i = 0; i < m; i++) {
		if (!isBridge[i]) continue;
		int v = myComp[ed[i][0]], u = myComp[ed[i][1]];
		assert(v != u);
		G[v].push_back(mp(u, ed[i][2]));
		G[u].push_back(mp(v, ed[i][2]));
	}

	if (k == 1) {
		for (int i = 0; i < n; i++)
			printf("%lld ", val[0]);
		printf("\n");
		return 0;
	}

	for (int v = 0; v < k; v++) {
		deg[v] = (int)G[v].size();
		if (deg[v] <= 1) q[topQ++] = v;
	}
	for (int i = 0; i < topQ; i++) {
		solve(q[i]);
	}

	for (int v = 0; v < k; v++) {
		ans[v] = val[v];
		for (pii e : G[v]) {
			int u = e.first;
			ans[v] += dp[mp(v, u)];
		}
	}
	for (int i = 0; i < n; i++)
		printf("%lld ", ans[myComp[i]]);
	printf("\n");

	return 0;
}