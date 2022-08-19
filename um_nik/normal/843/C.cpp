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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 200200;
int n;
vector<int> g[N];
int deg[N];
int sz[N];
int ans[2 * N][3];
int ansSz;
bool bad[N];
int a[N];
int m;
set<pii> setik;

void addAns(int v, int u, int w)
{
	ans[ansSz][0] = v + 1;
	ans[ansSz][1] = u + 1;
	ans[ansSz][2] = w + 1;
	ansSz++;
}

void dfs(int v)
{
	sz[v] = 1;
	for (int u : g[v]) {
		if (sz[u]) continue;
		dfs(u);
		sz[v] += sz[u];
	}
}

vector<int> findCentr(int v)
{
	vector<int> res;
	while(true) {
		int w = -1;
		for (int u : g[v]) {
			if (sz[u] > sz[v]) continue;
			if (2 * sz[u] >= n) {
				w = u;
				break;
			}
		}
		if (w == -1) {
			res.push_back(v);
			return res;
		}
		if (2 * sz[w] == n) {
			res.push_back(v);
			res.push_back(w);
			return res;
		}
		v = w;
	}
}

void dfs2(int v)
{
	for (int u : g[v]) {
		if (bad[u]) continue;
		if (deg[u]) continue;
		deg[v]++;
		deg[u]++;
		dfs2(u);
	}
	setik.insert(mp(deg[v], v));
}

void solve(int V, int lst)
{
	setik.clear();
	dfs2(V);
	m = 0;
	a[m++] = lst;
	while((int)setik.size() > 1) {
		int v = setik.begin()->second;
		setik.erase(setik.begin());
		if (deg[v] != 1) throw;
		a[m++] = v;
		bad[v] = 1;
		addAns(lst, V, v);
		for (int u : g[v]) {
			if (bad[u]) continue;
			setik.erase(mp(deg[u], u));
			deg[u]--;
			setik.insert(mp(deg[u], u));
			V = u;
		}
		lst = v;
	}
	m--;
	lst = a[m];
	for (int i = m - 1; i >= 0; i--)
		addAns(a[i], a[i + 1], lst);
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
	dfs(0);
	vector<int> V = findCentr(0);
	for (int v : V)
		bad[v] = 1;

	for (int v : V) {
		for (int u : g[v]) {
			if (bad[u]) continue;
			solve(u, v);
		}
	}

	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);

	return 0;
}