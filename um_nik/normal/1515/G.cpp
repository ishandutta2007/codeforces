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

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

const int N = 200200;
int n, m;
vector<pii> g[N];
vector<int> rg[N];
bool used[N];
int ord[N];
int ordSz;
int col[N];
vector<int> forCol[N];
int C;
ll a[N];
ll ans[N];

void dfsOrd(int v) {
	eprintf("dfsOrd %d\n", v);
	used[v] = 1;
	for (pii e : g[v]) {
		int u = e.first;
		if (used[u]) continue;
		dfsOrd(u);
	}
	ord[ordSz++] = v;
}
void dfsCol(int v) {
	forCol[C].push_back(v);
	col[v] = C;
	eprintf("dfsCol %d %d\n", v, col[v]);
	for (int u : rg[v]) {
		if (col[u] == -1)
			dfsCol(u);
	}
}
void dfsA(int v) {
	for (pii e : g[v]) {
		int u = e.first;
		if (col[u] != col[v]) continue;
		if (a[u] != -1) continue;
		a[u] = a[v] + e.second;
		dfsA(u);
	}
}

void solve() {
	for (int v = 0; v < n; v++) {
		if (used[v]) continue;
		dfsOrd(v);
	}
	reverse(ord, ord + ordSz);
	for (int i = 0; i < n; i++)
		col[i] = -1;
	C = 0;
	for (int i = 0; i < n; i++) {
		int v = ord[i];
		if (col[v] != -1) continue;
		dfsCol(v);
		C++;
	}
	for (int c = 0; c < C; c++) {
		if ((int)forCol[c].size() == 1) {
			ans[c] = 0;
			continue;
		}
		ans[c] = 0;
		for (int v : forCol[c])
			a[v] = -1;
		int v = forCol[c][0];
		a[v] = 0;
		dfsA(v);
		for (int v : forCol[c])
			for (pii e : g[v]) {
				int u = e.first;
				if (col[u] != c) continue;
				ll w = abs(a[u] - a[v] - e.second);
				ans[c] = gcd(ans[c], w);
			}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		v--;u--;
		g[v].push_back(mp(u, w));
		rg[u].push_back(v);
	}
	solve();
	int q;
	scanf("%d", &q);
	while(q--) {
		int v;
		ll x, y;
		scanf("%d%lld%lld", &v, &x, &y);
		v--;
		v = col[v];
		y = gcd(y, ans[v]);
		if (x % y == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}