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
vector<int> g[N];
pii ord[2 * N];
int n, m;
int ans[N];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		g[i].clear();
	}
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		ord[i] = mp(u, v);
	}
	sort(ord, ord + m);
	for (int i = 0; i < n; i++)
		ans[i] = 0;
	for (int i = 0; i < m; i++) {
		int v = ord[i].second;
		int u = ord[i].first;
		if (ans[u] == 2) continue;
		if (ans[v] != 0) continue;
		ans[u] = 1;
		for (int w : g[u])
			ans[w] = 2;
	}
	for (int i = 0; i < m; i++) {
		int v = ord[i].second;
		int u = ord[i].first;
		assert(ans[v] == 2 || ans[u] == 2 || (ans[v] == 0 && ans[u] == 1));
	}
	vector<int> res;
	for (int v = 0; v < n; v++)
		if (ans[v] == 2) res.push_back(v + 1);
	assert((int)res.size() * 7 <= n * 4);
	printf("%d\n", (int)res.size());
	for (int v : res)
		printf("%d ", v);
	printf("\n");
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