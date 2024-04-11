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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 200200;
int n, m;
vector<int> g[N], rg[N];
int q[N];
int topQ;
int dist[N];
int p[N];

void BFS(int v) {
	for (int i = 0; i <= n; i++)
		dist[i] = N;
	dist[v] = 0;
	topQ = 0;
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

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		rg[v].push_back(u);
		g[u].push_back(v);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &p[i]);
	BFS(p[m - 1]);

	int ans1 = 0, ans2 = 0;
	for (int i = 1; i < m - 1; i++) {
		if (dist[p[i]] >= dist[p[i - 1]]) {
			ans1++;
			ans2++;
		} else {
			bool ok = true;
			for (int v : rg[p[i - 1]])
				ok &= v == p[i] || dist[v] > dist[p[i]];
			if (!ok) ans2++;
		}
	}
	printf("%d %d\n", ans1, ans2);

	return 0;
}