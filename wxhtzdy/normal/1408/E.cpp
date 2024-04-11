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

const int N = 200050;
int n, m;
int a[N];
int b[N];
vector<int> g[N];
int par[N];

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}
	bool operator < (Edge e) {
		return w > e.w;
	}
};

int root(int x) {
	return par[x] == x ? x : par[x] = root(par[x]);
}

bool unite(int x, int y) {
	x = root(x);
	y = root(y);
	if (x == y)
		return false;
	par[x] = y;
	return true;
}

int main() 
{
	startTime = clock();

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	vector<Edge> edges;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int s;
		scanf("%d", &s);
		while(s--) {
			int x;
			scanf("%d", &x);
			--x;
			edges.push_back(Edge(x, i + m, a[i] + b[x]));
			ans += a[i] + b[x];
		}
	}
	sort(all(edges));
	for (int i = 0; i < n + m; i++) par[i] = i;
	for (int i = 0; i < edges.size(); i++)
		if (unite(edges[i].u, edges[i].v))
			ans -= edges[i].w;
	printf("%lld", ans);
	return 0;
}