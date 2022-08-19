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

const int N = 500500;
vector<int> g[N];
int n;
int r[2 * N], l[2 * N];
int ans[N][2];

void insToLeftOf(int x, int y) {
	int z = l[y];
	l[x] = z;
	r[x] = y;
	l[y] = x;
	r[z] = x;
}

void dfs(int v, int par) {
	if (par != -1) {
		insToLeftOf(2 * v, 2 * par);
		insToLeftOf(2 * v + 1, r[2 * par]);
	}
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	l[0] = 2 * n;
	r[0] = 1;
	l[1] = 0;
	r[1] = 2 * n;
	l[2 * n] = 1;
	r[2 * n] = 0;
	dfs(0, -1);
	int v = 2 * n;
	for (int i = 1; i <= 2 * n; i++) {
		v = r[v];
		ans[v / 2][v & 1] = i;
	}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", ans[i][0], ans[i][1]);

	return 0;
}