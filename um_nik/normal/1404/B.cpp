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

const int N = 100100;
int n;
vector<int> g[N];
int dist[N];
int q[N];
int topQ;
int d[5][N];
bool good[N];

void BFS1(int v) {
	for (int i = 1; i <= n; i++)
		dist[i] = N;
	topQ = 0;
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

bool solve() {
	int a, b, da, db;
	scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
	for (int i = 1; i <= n; i++)
		g[i].clear();
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	if (db <= 2 * da) return true;
	BFS1(a);
	if (dist[b] <= da) return true;
	int V = q[topQ - 1];
	BFS1(V);
	return dist[q[topQ - 1]] <= 2 * da;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve())
			printf("Alice\n");
		else
			printf("Bob\n");
	}

	return 0;
}