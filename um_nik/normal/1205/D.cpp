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

const int N = 1010;
int n;
vector<int> g[N];
int sz[N];
int w[N];
int cnt;
int toAdd;

void dfs(int v, int par) {
	sz[v] = 1;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}
}
void dfs2(int v, int par) {
	w[v] = cnt;
	cnt += toAdd;
	for (int u : g[v]) {
		if (u == par) {
			printf("%d %d %d\n", u + 1, v + 1, w[v] - w[u]);
			continue;
		}
		dfs2(u, v);
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
	dfs(0, -1);
	int v = 0;
	while(true) {
		int z = v;
		for (int u : g[v]) {
			if (sz[u] > sz[v]) continue;
			if (2 * sz[u] >= n) z = u;
		}
		if (z == v) break;
		v = z;
	}
	dfs(v, -1);
	vector<pii> a;
	for (int u : g[v])
		a.push_back(mp(sz[u], u));
	a.push_back(mp(1, v));
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	vector<int> b, c;
	int sumB = 0, sumC = 0;
	for (pii t : a) {
		if (sumB <= sumC) {
			sumB += t.first;
			b.push_back(t.second);
		} else {
			sumC += t.first;
			c.push_back(t.second);
		}
	}
	bool fnd = false;
	for (int u : b)
		if (u == v) fnd = true;
	if (!fnd) {
		swap(b, c);
		swap(sumB, sumC);
	}
	cnt = 1;
	toAdd = 1;
	for (int u : b) {
		if (u == v) continue;
		dfs2(u, v);
	}
	cnt = sumB;
	toAdd = sumB;
	for (int u : c) {
		if (u == v) throw;
		dfs2(u, v);
	}

	return 0;
}