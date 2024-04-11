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

const int N = 500500;
int n, m;
vector<pii> g[N];
int q[N];
int topQ;
int dist[N];
int ban[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, u, t;
		scanf("%d%d%d", &v, &u, &t);
		v--;u--;
		g[u].push_back(mp(v, t));
	}
	for (int v = 0; v < n; v++) {
		dist[v] = N;
		ban[v] = -1;
	}
	dist[n - 1] = 0;
	q[topQ++] = n - 1;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		//eprintf("%d\n", v);
		for (pii e : g[v]) {
			int u = e.first;
			int t = e.second;
			if (dist[u] <= dist[v] + 1) continue;
			if (ban[u] == -1) ban[u] = t;
			if (ban[u] != t) {
				//eprintf("%d %d %d\n", u, t, dist[v] + 1);
				dist[u] = dist[v] + 1;
				q[topQ++] = u;
			}
		}
	}
	if (dist[0] == N) dist[0] = -1;
	printf("%d\n", dist[0]);
	for (int i = 0; i < n; i++) {
		if (ban[i] == -1)
			ban[i] = 0;
		printf("%d", ban[i] ^ 1);
	}
	printf("\n");

	return 0;
}