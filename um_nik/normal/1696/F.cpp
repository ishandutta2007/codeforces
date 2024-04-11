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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const int N = 103;
char a[N][N][N];
int n;
int b[N][N];
int par[N];
int q[N];
int topQ;
vector<int> g[N];
int dist[N];
int d[N][N];

void BFS(int v) {
	topQ = 0;
	for (int i = 0; i < n; i++)
		dist[i] = N;
	dist[v] = 0;
	q[topQ++] = v;
	for (int i = 0; i < topQ; i++) {
		v = q[i];
		for (int u : g[v]) {
			if (dist[u] <= dist[v] + 1) continue;
			dist[u] = dist[v] + 1;
			q[topQ++] = u;
		}
	}
}
bool trySolve(int V, int U) {
	topQ = 0;
	for (int i = 0; i < n; i++)
		par[i] = -1;
	par[V] = U;
	par[U] = V;
	q[topQ++] = V;
	q[topQ++] = U;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		for (int j = 0; j < n; j++) {
			if (j == par[v]) continue;
			if (b[v][j] != b[v][par[v]]) continue;
			if (par[j] != -1) return false;
			par[j] = v;
			q[topQ++] = j;
		}
	}
	if (topQ != n) return false;
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 0; i < n; i++) if (i != V) {
		g[i].push_back(par[i]);
		g[par[i]].push_back(i);
	}
	for (int v = 0; v < n; v++) {
		BFS(v);
		for (int i = 0; i < n; i++)
			d[v][i] = dist[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if ((b[i][j] == b[i][k]) ^ (d[i][j] == d[i][k])) {
					return false;
				}
	printf("Yes\n");
	for (int v = 0; v < n; v++)
		for (int u : g[v])
			if (v < u)
				printf("%d %d\n", v + 1, u + 1);
	return true;
}
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			scanf("%s", a[i][j]);
	for (int v = 0; v < n; v++) {
		for (int i = 0; i < n; i++)
			b[v][i] = -1;
		int m = 0;
		for (int u = 0; u < n; u++) {
			if (b[v][u] != -1) continue;
			b[v][u] = m;
			for (int i = u + 1; i < n; i++)
				if (a[u][i][v] == '1')
					b[v][i] = m;
			m++;
		}
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if ((a[i][j][v] == '1') ^ (b[v][i] == b[v][j])) {
					printf("No\n");
					return;
				}
			}
	}
	for (int i = 1; i < n; i++) {
		if (trySolve(0, i)) {
			return;
		}
	}
	printf("No\n");
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