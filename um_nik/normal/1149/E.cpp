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

const int N = 200200;
vector<int> g[N];
int ord[N];
int ordSz;
bool used[N];
int n, m;
int a[N];
int b[N];
int c[N];
bool mex[N];

void dfs(int v) {
	used[v] = 1;
	for (int u : g[v]) {
		if (used[u]) continue;
		dfs(u);
	}
	ord[ordSz++] = v;
}

void printAns(int v) {
	a[v] ^= c[b[v]];
	c[b[v]] = 0;
	for (int u : g[v]) {
		a[u] ^= c[b[u]];
		c[b[u]] = 0;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		dfs(i);
	}
	for (int i = 0; i < n; i++) {
		int v = ord[i];
		for (int j = 0; j <= (int)g[v].size(); j++)
			mex[j] = 0;
		for (int u : g[v])
			mex[b[u]] = 1;
		b[v] = 0;
		while(mex[b[v]]) b[v]++;
	}
	for (int i = 0; i < n; i++)
		c[b[i]] ^= a[i];
	int mx = -1;
	for (int i = 0; i < n; i++) {
		if (c[i] != 0)
			mx = i;
	}
	if (mx == -1) {
		printf("LOSE\n");
		return 0;
	}
	printf("WIN\n");
	for (int v = 0; v < n; v++) {
		if (b[v] != mx) continue;
		if ((a[v] ^ c[mx]) > a[v]) continue;
		printAns(v);
		return 0;
	}
	throw;

	return 0;
}