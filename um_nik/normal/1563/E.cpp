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

const int INF = (int)1e9 + 7;
int add(int x, int y) {
	return min(INF, x + y);
}
const int N = 2020;
bool good[N];
bool close[N];
int par[N];
int curPow[N];
int n, m;
vector<int> g[N];
int a[N], b[N];
int ppp;

void addChain(int v) {
	while(v >= 0) {
		if (!good[v]) {
			good[v] = 1;
			ppp = add(ppp, b[v]);
		}
		v = par[v];
	}
}

bool dfs(int v) {
	for (int u : g[v]) {
		if (good[u]) continue;
		if (u == par[v]) continue;
		if (a[u] >= curPow[v]) continue;
		if (par[u] != -1 || close[u]) {
			addChain(v);
			addChain(u);
			return true;
		}
		par[u] = v;
		curPow[u] = add(curPow[v], b[u]);
		if (dfs(u)) return true;
	}
	return false;
}

bool solve(int pw) {
	eprintf("solve %d\n", pw);
	for (int i = 0; i < n; i++)
		good[i] = 0;
	good[0] = 1;
	while(true) {
		for (int i = 0; i < n; i++)
			eprintf("%d", (int)good[i]);
		eprintf("\n");
		eprintf("pw = %d\n", pw);
		int cntGood = 0;
		for (int i = 0; i < n; i++)
			cntGood += (int)good[i];
		if (cntGood == n) return true;
		bool fnd = false;
		for (int v = 0; v < n; v++) {
			close[v] = 0;
			if (good[v]) continue;
			int ccc = 0;
			for (int u : g[v]) {
				if (!good[u]) continue;
				close[v] = 1;
				ccc++;
			}
			if (a[v] < pw && ccc >= 2) {
				pw = add(pw, b[v]);
				good[v] = true;
				fnd = true;
				break;
			}
		}
		if (fnd) continue;
		ppp = pw;
		for (int i = 0; i < n; i++)
			par[i] = curPow[i] = -1;
		for (int v = 0; !fnd && v < n; v++) {
			if (!close[v]) continue;
			if (a[v] >= pw) continue;
			par[v] = -2;
			curPow[v] = add(pw, b[v]);
			fnd |= dfs(v);
		}
		if (!fnd) return false;
		pw = ppp;
		//eprintf("pw = %d\n", pw);
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		g[i].clear();
	a[0] = b[0] = 0;
	for (int i = 1; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	int l = -1, r = INF;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	printf("%d\n", r);
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