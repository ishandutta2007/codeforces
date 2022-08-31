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

const int N = 2020;
vector<int> g[N];
int sz[N];
int c[N];
int a[N];
pii b[N];
int m;
int n;

void printAll(int v) {
	b[m++] = mp(a[v], v);
	for (int u : g[v])
		printAll(u);
}

void dfs(int v) {
	sz[v] = 1;
	for (int u : g[v]) {
		dfs(u);
		sz[v] += sz[u];
	}
	if (sz[v] <= c[v]) {
		printf("NO\n");
		exit(0);
	}
	m = 0;
	for (int u : g[v])
		printAll(u);
	sort(b, b + m);
	int t = 1;
	for (int i = 0; i <= m; i++) {
		if (i == c[v]) {
			a[v] = t++;
		}
		if (i == m) break;
		a[b[i].second] = t++;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int root = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d%d", &v, &c[i]);
		if (v == 0) {
			root = i;
			continue;
		}
		g[v - 1].push_back(i);
	}
	dfs(root);
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}