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


const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}


const int N = 200200;
const int LOG = 20;
vector<int> Q[N + 1];
int dist[N];
vector<int> g[2][N];
int n;
pii d2[N][2];

void read() {
	/*
	n = 27;
	for (int i = 0; i < n / 2; i++) {
		g[1][2 * i].push_back(2 * i + 1);
		g[0][2 * i + 1].push_back(2 * i);
		g[1][2 * i + 2].push_back(2 * i + 1);
		g[0][2 * i + 1].push_back(2 * i + 2);
		
	}
	*/
	
	int m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[0][v].push_back(u);
		g[1][u].push_back(v);
	}
	
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	
	for (int v = 0; v < n; v++)
		dist[v] = N;
	dist[0] = 0;

	int ans = (int)1e8;
	for (int t = 0; t < LOG; t++) {
		//eprintf("t = %d\n", t);
		for (int i = 0; i <= N; i++)
			Q[i].clear();
		for (int v = 0; v < n; v++) {
			if (dist[v] < N)
				Q[dist[v]].push_back(v);
		}
		for (int d = 0; d < N; d++) {
			while(!Q[d].empty()) {
				int v = Q[d].back();
				//eprintf("v = %d\n", v);
				Q[d].pop_back();
				if (dist[v] < d) continue;
				for (int u : g[t & 1][v]) {
					if (dist[u] <= d + 1) continue;
					dist[u] = d + 1;
					Q[d + 1].push_back(u);
				}
			}
		}
		if (dist[n - 1] < N)
			ans = min(ans, dist[n - 1] + (1 << t) - 1);
	}
	if (ans < (int)1e8) {
		printf("%d\n", ans);
		return 0;
	}
	for (int v = 0; v < n; v++) {
		if (dist[v] < N) {
			for (int j = 0; j < 2; j++)
				d2[v][(LOG - 1 + j) & 1] = mp(LOG - 1 + j, dist[v]);
		}
		else {
			for (int j = 0; j < 2; j++)
				d2[v][j] = mp(N, N);
		}
	}
	set<pair<pii, pii>> setik;
	for (int v = 0; v < n; v++) {
		for (int j = 0; j < 2; j++)
			setik.insert(mp(d2[v][j], mp(v, j)));
	}
	while(!setik.empty()) {
		int v = setik.begin()->second.first;
		int t = setik.begin()->second.second;
		setik.erase(setik.begin());
		int p = d2[v][t].first, s = d2[v][t].second;
		for (int u : g[t][v]) {
			pii w = mp(p, s + 1);
			if (d2[u][t] <= w) continue;
			setik.erase(mp(d2[u][t], mp(u, t)));
			d2[u][t] = w;
			setik.insert(mp(d2[u][t], mp(u, t)));
		}
		pii w = mp(p + 1, s);
		if (d2[v][t ^ 1] <= w) continue;
		setik.erase(mp(d2[v][t ^ 1], mp(v, t ^ 1)));
		d2[v][t ^ 1] = w;
		setik.insert(mp(d2[v][t ^ 1], mp(v, t ^ 1)));
	}
	pii res = min(d2[n - 1][0], d2[n - 1][1]);
	eprintf("%d %d\n", res.first, res.second);
	ans = bin_pow(2, res.first) - 1;
	ans = add(ans, res.second);
	printf("%d\n", ans);

	return 0;
}