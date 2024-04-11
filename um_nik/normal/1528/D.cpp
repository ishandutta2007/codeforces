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

const int INF = (int)2e9;
const int N = 606;
int n;
vector<pii> g[N];
int dist[N];
bool used[N];

void dijkstra(int v) {
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
		used[i] = false;
	}
	for (pii e : g[v])
		dist[e.first] = min(dist[e.first], e.second);
	for (int it = 0; it < n; it++) {
		for (int i = 1; i < n; i++)
			dist[i] = min(dist[i], dist[i - 1] + 1);
		dist[0] = min(dist[0], dist[n - 1] + 1);
		for (int i = 1; i < n; i++)
			dist[i] = min(dist[i], dist[i - 1] + 1);
		v = -1;
		for (int i = 0; i < n; i++) {
			if (used[i]) continue;
			if (v == -1 || dist[i] < dist[v])
				v = i;
		}
		used[v] = 1;
		for (pii e : g[v]) {
			int u = (e.first + dist[v]) % n;
			dist[u] = min(dist[u], dist[v] + e.second);
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		g[v].push_back(mp(u, w));
	}
	for (int i = 0; i < n; i++) {
		dijkstra(i);
		dist[i] = 0;
		for (int j = 0; j < n; j++)
			printf("%d ", dist[j]);
		printf("\n");
	}

	return 0;
}