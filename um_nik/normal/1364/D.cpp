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

const int N = 100100;
vector<int> g[N];
int n, m, k;
int h[N];
int par[N];

void printCyc(vector<int> cyc) {
	printf("2\n%d\n", (int)cyc.size());
	for (int v : cyc)
		printf("%d ", v);
	printf("\n");
}

void dfs(int v) {
	for (int u : g[v]) {
		if (u == par[v]) continue;
		if (h[u] == 0) {
			h[u] = h[v] + 1;
			par[u] = v;
			dfs(u);
		} else if (h[u] < h[v]) {
			vector<int> ans = {v};
			int w = v;
			while(w != u) {
				w = par[w];
				ans.push_back(w);
			}
			printCyc(ans);
			exit(0);
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		if (v > k || u > k) continue;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	for (int v = 1; v <= k; v++) {
		if (h[v]) continue;
		h[v] = 1;
		dfs(v);
	}

	vector<int> ans[2];
	for (int v = 1; v <= k; v++)
		ans[h[v] & 1].push_back(v);
	k = (k + 1) / 2;
	if ((int)ans[0].size() < k) swap(ans[0], ans[1]);
	printf("1\n");
	for (int i = 0; i < k; i++)
		printf("%d ", ans[0][i]);
	printf("\n");

	return 0;
}