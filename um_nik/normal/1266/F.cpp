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
int n;
vector<int> g[N];
int ans[N];
vector<pii> a[N];
int d[N];
int toUp[N];

void dfs1(int v, int par) {
	d[v] = 0;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs1(u, v);
		d[v] = max(d[v], d[u] + 1);
	}
//	eprintf("d[%d] = %d\n", v, d[v]);
}

void dfs2(int v, int tu) {
	toUp[v] = tu;
	pii b[2];
	b[0] = b[1] = mp(-1, -1);
	b[0].first = max(tu, 0) + 1;
	for (int u : g[v]) {
		if (d[u] > d[v]) continue;
		pii w = mp(d[u] + 2, u);
		for (int i = 0; i < 2; i++) {
			if (w > b[i])
				swap(w, b[i]);
		}
	}
	for (int u : g[v]) {
		if (d[u] > d[v]) continue;
		int t = 0;
		while(b[t].second == u) t++;
		dfs2(u, b[t].first);
	}
}

inline void updAns(int p, int x) {
	ans[p] = max(ans[p], x);
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
	dfs1(0, -1);
	dfs2(0, -1);
	
	vector<int> cur;
	for (int v = 0; v < n; v++) {
		cur.clear();
		if (toUp[v] != -1) cur.push_back(toUp[v]);
		for (int u : g[v])
			if (d[u] < d[v])
				cur.push_back(d[u] + 1);
		sort(cur.begin(), cur.end());
		for (int x : cur) {
			if (a[v].empty() || a[v].back().first != x) {
				a[v].push_back(mp(x, 1));
			} else {
				a[v].back().second++;
			}
		}
//		for (pii t : a[v])
//			printf("(%d %d) ", t.first, t.second);
//		printf("\n");
	}
	for (int i = 1; i <= n; i++)
		ans[i] = 1;
	int diam = 0;
	for (int v = 0; v < n; v++)
		diam = max(diam, a[v].back().first);
	for (int i = 1; i <= diam; i++)
		ans[i] = 2;
	for (int v = 0; v < n; v++)
		ans[1] = max(ans[1], 1 + (int)g[v].size());
	for (int v = 0; v < n; v++) {
		int sum = (int)g[v].size();
		for (int i = 0; i < (int)a[v].size(); i++) {
			int c = sum;
			updAns(2 * (int)a[v][i].first - 1, sum);
			if (i > 0) updAns(2 * (int)a[v][i - 1].first + 1, sum + 1);
			updAns(2 * (int)a[v][i].first, sum);
			sum -= a[v][i].second;
		}
	}
	for (int v = 0; v < n; v++)
		for (int u : g[v]) {
			if (u < v) continue;
			int sum = (int)g[v].size() + (int)g[u].size() - 2;
			int p1 = 0, p2 = 0;
			while(p1 < (int)a[v].size() && p2 < (int)a[u].size()) {
				int x = min(a[v][p1].first, a[u][p2].first);
				updAns(2 * x, sum);
				if (a[v][p1].first == x) {
					sum -= a[v][p1].second;
					p1++;
				}
				if (a[u][p2].first == x) {
					sum -= a[u][p2].second;
					p2++;
				}
			}
		}

	for (int i = n - 2; i > 1; i--)
		ans[i] = max(ans[i], ans[i + 2]);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}