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

const int N = 200200;
int n;
vector<pii> g[N];
pii res;

void dfs(int v, int par, int d) {
	res = max(res, mp(d, v));
	for (pii e : g[v]) {
		int u = e.first;
		if (u == par) continue;
		dfs(u, v, d + e.second);
	}
}

int diam() {
	res = mp(-1, -1);
	dfs(0, -1, 0);
	return res.first;
	int v = res.second;
	res = mp(-1, -1);
	dfs(v, -1, 0);
	return res.first;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		v--;u--;
		ans += w;
		g[v].push_back(mp(u, w));
		g[u].push_back(mp(v, w));
	}
	ans *= 2;
	ans -= diam();
	printf("%lld\n", ans);

	return 0;
}