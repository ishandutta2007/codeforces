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

//const int N = 100;
const int N = (int)1e6 + 7;
int n, m;
vector<vector<int>> a;
vector<int> g[N], rg[N];
vector<int> G[N];
int ord[N];
int col[N];
bool used[N];
int ans[N];
int C;
int ordSz;

void addEdge(int v, int u) {
	g[v].push_back(u);
	rg[u].push_back(v);
}

void dfsOrd(int v) {
	used[v] = 1;
	for (int u : g[v]) {
		if (!used[u])
			dfsOrd(u);
	}
	ord[ordSz++] = v;
}
void dfsCol(int v) {
	col[v] = C;
	for (int u : rg[v]) {
		if (col[u] == -1)
			dfsCol(u);
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	a = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++) {
		vector<pii> c;
		for (int j = 0; j < m; j++)
			c.push_back(mp(a[i][j], i * m + j));
		sort(all(c));
		for (int j = 0; j < m - 1; j++) {
			addEdge(c[j].second, c[j + 1].second);
			if (c[j].first == c[j + 1].first)
				addEdge(c[j + 1].second, c[j].second);
		}
	}
	eprintf("here\n");
	for (int i = 0; i < m; i++) {
		vector<pii> c;
		for (int j = 0; j < n; j++)
			c.push_back(mp(a[j][i], j * m + i));
		sort(all(c));
		for (int j = 0; j < n - 1; j++) {
			addEdge(c[j].second, c[j + 1].second);
			if (c[j].first == c[j + 1].first)
				addEdge(c[j + 1].second, c[j].second);
		}
	}

	eprintf("here\n");
	for (int v = 0; v < n * m; v++) {
		if (!used[v])
			dfsOrd(v);
	}
	reverse(ord, ord + ordSz);
	for (int v = 0; v < n * m; v++)
		col[v] = -1;
	for (int i = 0; i < ordSz; i++) {
		int v = ord[i];
		if (col[v] != -1) continue;
		dfsCol(v);
		C++;
	}
	for (int v = 0; v < n * m; v++)
		for (int u : g[v]) {
			int cv = col[v], cu = col[u];
			if (cv != cu) {
				assert(cv < cu);
				G[cv].push_back(cu);
			}
		}
	for (int i = 0; i < C; i++) {
		for (int x : G[i])
			ans[x] = max(ans[x], ans[i] + 1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v = i * m + j;
			v = col[v];
			printf("%d ", ans[v] + 1);
		}
		printf("\n");
	}

	return 0;
}