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

const int MAGIC = 200;
const int N = (int)1e6 + 7;
int n;
vector<int> g[N];
int sz[N];
ll a[N];
ll ANS;
bitset<N> dp, ndp;

void dfsSz(int v, int par) {
	sz[v] = 1;
	for (int u : g[v]) if (u != par) {
		dfsSz(u, v);
		sz[v] += sz[u];
	}
}

void dfsPath(int v, int par) {
	a[v] = sz[v];
	for (int u : g[v]) if (u != par) {
		dfsPath(u, v);
		a[v] += a[u];
	}
}

void makeTrans(int w, int k) {
	ndp.reset();
	k = (k + 1) * w;
	for (int r = 0; r < w; r++) {
		int sum = 0;
		for (int x = r; x < n; x += w) {
			sum += dp[x];
			if (x >= k) sum -= dp[x - k];
			ndp[x] = sum > 0;
		}
	}
	dp = ndp;
}
int knapsack(vector<int> b) {
	sort(all(b));
	dp[0] = 1;
	int l = 0;
	while(l < (int)b.size()) {
		if (b[l] > MAGIC) {
			dp |= dp << b[l];
			l++;
		} else {
			int r = l;
			while(r < (int)b.size() && b[l] == b[r]) r++;
			makeTrans(b[l], r - l);
			l = r;
		}
	}
	int x = (n - 1) / 2;
	while(!dp[x]) x--;
	return x;
}

void dfsAns(int v, int par, ll w) {
	eprintf("%d %lld\n", v, w);
	if (par != -1)
		ANS = max(ANS, w + a[v] + (ll)(sz[v] - 1) * (n - sz[v]));
	w += n + sz[v];
	for (int u : g[v]) if (u != par)
		w += a[u];	
	for (int u : g[v]) if (u != par)
		dfsAns(u, v, w - 2 * sz[u] - a[u]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d", &x);
		x--;
		g[x].push_back(i);
		g[i].push_back(x);
	}
	dfsSz(0, -1);
	int v = 0;
	while(true) {
		int w = v;
		for (int u : g[v]) {
			if (sz[u] < sz[v] && 2 * sz[u] >= n)
				w = u;
		}
		if (w == v) break;
		v = w;
	}
	dfsSz(v, -1);
	dfsPath(v, -1);
	vector<int> vals;
	for (int u : g[v])
		vals.push_back(sz[u]);
	ll X = knapsack(vals);
	ANS = max(ANS, a[v] + X * (n - 1 - X));
	eprintf("%lld\n", ANS);
	dfsAns(v, -1, 0);
	printf("%lld\n", ANS);

	return 0;
}