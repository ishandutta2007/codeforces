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

const int LOG = 17;
const int N = 100100;
int n;
vector<int> g[N];
int par[N][LOG];
int h[N];
int L;
pii maxD[N][3];
int fromUp[N];
int thirdLen[N];
pii deepest[N];

void dfsPar(int v, int p) {
	for (int i = 0; i < 3; i++)
		maxD[v][i] = mp(0, v);
	deepest[v] = mp(h[v], v);
	for (int u : g[v]) {
		if (u == p) continue;
		par[u][0] = v;
		for (int k = 0; k < LOG - 1; k++)
			par[u][k + 1] = par[par[u][k]][k];
		h[u] = h[v] + 1;
		dfsPar(u, v);
		pii t = mp(maxD[u][0].first + 1, u);
		for (int i = 0; i < 3; i++)
			if (t > maxD[v][i])
				swap(t, maxD[v][i]);
		deepest[v] = max(deepest[v], deepest[u]);
	}
}

void dfsThird(int v, int p) {
	thirdLen[v] = min(maxD[v][1].first, max(maxD[v][2].first, fromUp[v]));
	for (int u : g[v]) {
		if (u == p) continue;
		int t = 0;
		while(maxD[v][t].second == u) t++;
		fromUp[u] = max(fromUp[v], maxD[v][t].first) + 1;
		dfsThird(u, v);
	}
}

int up(int v, int dh) {
	for (int k = 0; k < LOG; k++)
		if ((dh >> k) & 1)
			v = par[v][k];
	return v;
}
int LCA(int v, int u) {
	if (h[v] > h[u]) swap(v, u);
	u = up(u, h[u] - h[v]);
	if (v == u) return v;
	for (int k = LOG - 1; k >= 0; k--) {
		if (par[v][k] != par[u][k]) {
			v = par[v][k];
			u = par[u][k];
		}
	}
	return par[v][0];
}

void precalc(int V) {
	for (int i = 0; i <= n; i++) {
		h[i] = -1;
		for (int k = 0; k < LOG; k++)
			par[i][k] = 0;
	}
	h[V] = 0;
	dfsPar(V, 0);
	fromUp[V] = 0;
	dfsThird(V, 0);
}

int dist(int v, int u) {
	return h[v] + h[u] - 2 * h[LCA(v, u)];
}

bool trySolve(int A, int B, int CA) {
	precalc(A);
	while(true) {
		int oldH = h[B];
		A = up(B, L);
		int nB = up(B, L - 1);
		int d = fromUp[A];
		int t = 0;
		while(maxD[A][t].second == nB) t++;
		d = max(d, maxD[A][t].first);
		if (h[B] - d <= h[CA]) return true;
		B = up(B, d);
		B = deepest[B].second;
		if (h[B] >= h[CA] + L) return true;
		if (h[B] == oldH) return false;
	}
}

void solve() {
	int A, B;
	scanf("%d%d%d", &n, &A, &B);
	for (int i = 0; i <= n; i++)
		g[i].clear();
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	precalc(1);
	L = dist(A, B);
	int CA = B, CB = A;
	for (int v = 1; v <= n; v++) {
		if (thirdLen[v] < L) continue;
		int w = LCA(A, B);
		int x = LCA(A, v);
		int y = LCA(B, v);
		if (h[x] > h[w]) w = x;
		if (h[y] > h[w]) w = y;
		if (w == A || w == B) {
			printf("YES\n");
			return;
		}
		if (dist(A, w) < dist(A, CA)) CA = w;
		if (dist(B, w) < dist(B, CB)) CB = w;
	}
	if (CA != B && trySolve(A, B, CA)) {
		printf("YES\n");
		return;
	}
	if (CB != A && trySolve(B, A, CB)) {
		printf("YES\n");
		return;
	}
	printf("NO\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}