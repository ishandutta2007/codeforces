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

const ll INF = (ll)2e9 + 88;
const int N = 1010;
int n;
ll a[N][2];
ll dist[N][N];
ll xs[N], ys[N];
int xsSz, ysSz;
bool used[N];
vector<vector<int>> comps;
bool bad[N][N];
int forX[N][N], forY[N][N];

void dfs(int v, ll t) {
	used[v] = 1;
	comps.back().push_back(v);
	for (int u = 0; u < n; u++)
		if (dist[v][u] <= t && !used[u])
			dfs(u, t);
}

void solveComp(vector<int> C, ll t) {
	for (int i = 0; i <= xsSz; i++)
		for (int j = 0; j <= ysSz; j++) {
			forX[i][j] = 0;
			forY[j][i] = 0;
		}
	for (int v : C) {
		int x = a[v][0], y = a[v][1];
		int p, l, r;

		p = lower_bound(xs, xs + xsSz, x) - xs;
		assert(xs[p] == x);
		l = lower_bound(ys, ys + ysSz, y - t) - ys;
		r = upper_bound(ys, ys + ysSz, y + t) - ys;
		forX[p][l]++;
		forX[p][r]--;

		p = lower_bound(ys, ys + ysSz, y) - ys;
		assert(ys[p] == y);
		l = lower_bound(xs, xs + xsSz, x - t) - xs;
		r = upper_bound(xs, xs + xsSz, x + t) - xs;
		forY[p][l]++;
		forY[p][r]--;
	}
	for (int i = 0; i < xsSz; i++)
		for (int j = 0; j < ysSz; j++)
			forX[i][j + 1] += forX[i][j];
	for (int j = 0; j < ysSz; j++)
		for (int i = 0; i < xsSz; i++)
			forY[j][i + 1] += forY[j][i];
	for (int i = 0; i < xsSz; i++)
		for (int j = 0; j < ysSz; j++)
			bad[i][j] |= forX[i][j] == 0 && forY[j][i] == 0;
}

bool solve(ll t) {
	comps.clear();
	for (int i = 0; i < n; i++)
		used[i] = false;
	for (int v = 0; v < n; v++) {
		if (used[v]) continue;
		comps.push_back(vector<int>());
		dfs(v, t);
	}
	int m = (int)comps.size();
	if (m > 4) return false;
	if (m == 1) return true;
	if (m == 2) {
		for (int v : comps[0])
			for (int u : comps[1]) {
				if (dist[v][u] < INF && dist[v][u] <= 2 * t) return true;
				if (abs(a[v][0] - a[u][0]) <= t && abs(a[v][1] - a[u][1]) <= t) return true;
			}
		return false;
	}
	for (int i = 0; i < xsSz; i++)
		for (int j = 0; j < ysSz; j++)
			bad[i][j] = false;
	for (int i = 0; i < m; i++)
		solveComp(comps[i], t);
	for (int i = 0; i < xsSz; i++)
		for (int j = 0; j < ysSz; j++)
			if (!bad[i][j])
				return true;
	return false;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++)
			scanf("%lld", &a[i][j]);
		xs[xsSz++] = a[i][0];
		ys[ysSz++] = a[i][1];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (a[i][0] == a[j][0]) {
				dist[i][j] = abs(a[i][1] - a[j][1]);
			} else if (a[i][1] == a[j][1]) {
				dist[i][j] = abs(a[i][0] - a[j][0]);
			} else {
				dist[i][j] = INF;
			}
		}
	sort(xs, xs + xsSz);
	xsSz = unique(xs, xs + xsSz) - xs;
	sort(ys, ys + ysSz);
	ysSz = unique(ys, ys + ysSz) - ys;

	ll l = -1, r = INF;
	while(r - l > 1) {
		ll t = (l + r) / 2;
		if (solve(t))
			r = t;
		else
			l = t;
	}
	if (r == INF)
		printf("-1\n");
	else
		printf("%lld\n", r);

	return 0;
}