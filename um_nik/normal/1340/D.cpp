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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 100500;
const int M = 800800;
vector<int> g[N];
pii ans[M];
int ansSz;
int k;
int n;

void dfs(int v, int par, int cPar) {
	//eprintf("dfs %d %d %d\n", v, par, cPar);
	int curC = cPar;
	int sz = (int)g[v].size();
	if (par) sz--;
	for (int u : g[v]) {
		if (u == par) continue;
		if (curC == k) {
			curC = cPar - sz - 1;
			assert(curC >= 0);
			ans[ansSz++] = mp(v, curC);
		}
		sz--;
		curC++;
		ans[ansSz++] = mp(u, curC);
		dfs(u, v, curC);
	}
	if (par == 0) return;
	if (curC != cPar - 1) {
		ans[ansSz++] = mp(v, cPar - 1);
	}
	ans[ansSz++] = mp(par, cPar);
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	ans[ansSz++] = mp(1, 0);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int v = 1; v <= n; v++)
		k = max(k, (int)g[v].size());
	dfs(1, 0, 0);
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);

	return 0;
}