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

const int N = 1010;
int n;
vector<int> g[N];
int t[N][2];
int T;
int L;
vector<int> q;
char str[222];

pii query() {
	sort(all(q));
	q.resize(unique(all(q)) - q.begin());
	assert(!q.empty());
	printf("? %d", (int)q.size());
	for (int v : q)
		printf(" %d", v);
	printf("\n");
	fflush(stdout);
	int x, y;
	scanf("%d%d", &x, &y);
	assert(x != -1);
	return mp(x, y);
}

void dfs1(int v) {
	t[v][0] = T++;
	for (int u : g[v]) {
		if (t[u][0] != -1) continue;
		dfs1(u);
	}
	t[v][1] = T;
}

void dfs2(int v, int d, int bad) {
	if (d == 0) {
		if (bad == -1 || t[v][1] <= t[bad][0] || t[bad][1] <= t[v][0])
			q.push_back(v);
		return;
	}
	for (int u : g[v]) {
		if (t[u][0] <= t[v][0]) continue;
		dfs2(u, d - 1, bad);
	}
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		t[i][0] = t[i][1] = -1;
	}
	T = 0;
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	q.clear();
	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}
	pii z = query();
	int root = z.first;
	dfs1(root);
	L = z.second;
	int V = root, U = root;
	int len = L;
	while(len > 0) {
		q.clear();
		int w = (len + 1) / 2;
		dfs2(V, w, -1);
		dfs2(U, w, V);
		z = query();
		assert(L == z.second);
		int v = z.first;
		if (t[V][0] <= t[v][0] && t[v][1] <= t[V][1]) {
			V = v;
		} else if (t[U][0] <= t[v][0] && t[v][1] <= t[U][1]) {
			U = v;
		} else assert(false);
		len -= w;
	}
	printf("! %d %d\n", V, U);
	fflush(stdout);
	scanf("%s", str);
	assert(str[0] == 'C');
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int tt;
	scanf("%d", &tt);
	while(tt--) solve();

	return 0;
}