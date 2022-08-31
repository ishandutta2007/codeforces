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
bool leaf[N], bud[N];
int pp[N];

void dfs(int v, int par) {
	pp[v] = par;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
	}
	if (par == -1) return;
	leaf[v] = 1;
	for (int u : g[v]) {
		if (u == par || bud[u]) continue;
		leaf[v] = 0;
	}
	if (leaf[v]) return;
	bud[v] = 1;
	for (int u : g[v]) {
		if (u == par || bud[u] || leaf[u]) continue;
		bud[v] = 0;
	}
}

void solve() {
	scanf("%d", &n);
	for (int v = 0; v < n; v++) {
		g[v].clear();
		leaf[v] = bud[v] = 0;
	}
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (leaf[i]) ans++;
		if (bud[i]) ans--;
	}
	bool ok = true;
	for (int i = 1; i < n; i++) {
		if (!leaf[i]) continue;
		if (!bud[pp[i]]) ok = false;
	}
	if (ok) ans++;
	printf("%d\n", ans);
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