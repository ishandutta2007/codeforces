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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100100;
int n;
int par[N];
vector<int> g[N];
int h[N];
int ord[N];
int ordSz;
int ans[N];
int ansSz;
bool bad[N];

void dfs(int v) {
	ord[ordSz++] = v;
	int lst = -1;
	for (int u : g[v]) {
		if (bad[u]) {
			lst = u;
			continue;
		}
		dfs(u);
	}
	if (lst != -1) dfs(lst);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v;
		scanf("%d", &v);
		h[i] = h[v] + 1;
		g[v].push_back(i);
		par[i] = v;
	}
	int w = 0;
	for (int i = 1; i < n; i++)
		if (h[i] > h[w])
			w = i;
	while(w > 0) {
		bad[w] = 1;
		w = par[w];
	}
	dfs(0);
	for (int i = 1; i < n; i++) {
		int z = h[ord[i - 1]];
		while(z >= h[ord[i]]) {
			z--;
			ans[ansSz++] = ord[i];
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ord[i]);
	printf("\n");
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}