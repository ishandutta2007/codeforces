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
#include <iomanip>
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

const int MOD = 1e9 + 7;

int add(int x, int y) {
	x += y;
	return x > MOD ? x - MOD : x;
}

int sub(int x, int y) {
	x -= y;
	return x < 0 ? x + MOD : x;
}

const int N = 201000;
int n;
int k;
int vis[N];
int sz;
ll pw[N];
vector<int> g[N];

void dfs(int u) {
	vis[u] = 1;
	sz += 1;
	for (int v : g[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int main()
{
	startTime = clock();

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		pw[i] = i;
		for (int j = 1; j < k; j++) {
			pw[i] = (pw[i] * i) % MOD;
		}
	}
	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if (w == 0) {
			g[u].pb(v);
			g[v].pb(u);
		}
	}
	int ans = pw[n];
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			sz = 0;
			dfs(i);
			ans = sub(ans, pw[sz]);
		}
	}
	printf("%d", ans);
	return 0;
}