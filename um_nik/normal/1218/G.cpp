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
int n, m;
int ed[N][3];
vector<int> g[N];
char t[N];
int h[N];
int par[N];
int col[N];
bool used[N];

void printAns() {
	for (int i = 0; i < m; i++) {
		int x = ed[i][2];
		x %= 3;
		while(x <= 0) x += 3;
		printf("%d %d %d\n", ed[i][0], ed[i][1], x);
	}
	exit(0);
}

int getOther(int id, int v) {
	return ed[id][0] ^ ed[id][1] ^ v;
}

void dfsSolve(int v) {
	for (int id : g[v]) {
		int u = getOther(id, v);
		if (used[u]) continue;
		used[u] = true;
		dfsSolve(u);
		ed[id][2] = col[u];
		col[u] -= ed[id][2];
		col[v] -= ed[id][2];
		if (col[v] < 0) col[v] += 3;
	}
}

void solveOdd(int id) {
	int v = ed[id][0], u = ed[id][1];
	if (h[v] < h[u]) swap(v, u);
	vector<pii> cyc;
	while(v != u) {
		cyc.push_back(mp(v, par[v]));
		v = getOther(par[v], v);
	}
	cyc.push_back(mp(u, id));
	int sz = (int)cyc.size();

	for (int i = 0; i < sz; i++) {
		eprintf("%d %d\n", cyc[i].first, cyc[i].second);
	}

	for (int i = 0; i < n; i++)
		col[i] = (int)(t[i] - 'X');
	for (int i = 0; i < sz; i++)
		used[cyc[i].first] = true;
	for (int i = 0; i < sz; i++)
		dfsSolve(cyc[i].first);

	int sum = 0;
	for (int i = 0; i < sz; i++)
		sum += col[cyc[i].first];
	if (sum & 1) sum += 3;
	sum /= 2;
	for (int i = 2; i < sz; i += 2)
		sum -= col[cyc[i].first];
	sum %= 3;
	if (sum < 0) sum += 3;
	ed[cyc[0].second][2] = sum;
	for (int i = 1; i < sz; i++) {
		int x = col[cyc[i].first] - ed[cyc[i - 1].second][2];
		if (x < 0) x += 3;
		ed[cyc[i].second][2] = x;
	}
	printAns();
}

void solveEven(int id) {
	int v = ed[id][0], u = ed[id][1];
	if (h[v] < h[u]) swap(v, u);
	vector<pii> cyc;
	while(v != u) {
		cyc.push_back(mp(v, par[v]));
		v = getOther(par[v], v);
	}
	cyc.push_back(mp(u, id));
	int sz = (int)cyc.size();

	for (int i = 0; i < n; i++)
		col[i] = h[i] & 1;
	if (col[cyc[0].first] == 1) rotate(cyc.begin(), cyc.begin() + 1, cyc.end());
	for (int i = 0; i < sz; i++)
		used[cyc[i].first] = true;
	for (int i = 0; i < sz; i++)
		dfsSolve(cyc[i].first);

	int bal = 0;
	for (int i = 0; i < sz; i++) {
		int x = col[cyc[i].first];
		if (i % 2 == 0)
			bal += x;
		else
			bal -= x;
	}
	bal %= 3;
	if (bal < 0) bal += 3;
	if (bal == 1) {
		int v = cyc[0].first;
		col[v]--;
		if (col[v] < 0) col[v] += 3;
	} else if (bal == 2) {
		for (int i = 0; i < 3; i += 2) {
			int v = cyc[i].first;
			col[v]--;
			if (col[v] < 0) col[v] += 3;
		}
//		int v = cyc[0].first;
//		col[v]++;
//		if (col[v] >= 3) col[v] -= 3;
	}

	for (int i = 1; i < sz; i++) {
		int x = col[cyc[i].first] - ed[cyc[i - 1].second][2];
		if (x < 0) x += 3;
		ed[cyc[i].second][2] = x;
	}
	printAns();
}


void dfs1(int v) {
	for (int id : g[v]) {
		int u = getOther(id, v);
		if (h[u] == -1) {
			h[u] = h[v] + 1;
			par[u] = id;
			dfs1(u);
		} else if (h[v] % 2 == h[u] % 2) {
			solveOdd(id);
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	scanf("%s", t);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &ed[i][j]);
			g[ed[i][j]].push_back(i);
		}
	}
	for (int i = 0; i < n; i++)
		h[i] = -1;
	for (int i = 0; i < n; i++) {
		if ((int)g[i].size() == 1) {
			for (int j = 0; j < n; j++)
				col[j] = (int)(t[j] - 'X');
			dfsSolve(i);
			printAns();
		}
	}
	h[0] = 0;
	dfs1(0);
	for (int v = 0; v < n; v++) {
		for (int id : g[v]) {
			if (par[v] == id) continue;
			int u = getOther(id, v);
			if (h[u] < h[v])
				solveEven(id);
		}
	}
	throw;
	return 0;
}