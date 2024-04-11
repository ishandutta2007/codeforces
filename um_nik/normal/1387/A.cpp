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
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng(42);
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
int n, m;
vector<pii> g[N];
int a[N][2];
double ans[N];
bool used[N];
vector<int> comp;
bool fxd;
int S;

bool dfs(int v) {
	comp.push_back(v);
	used[v] = 1;
	for (pii e : g[v]) {
		int u = e.first;
		int x = -a[v][0], y = e.second - a[v][1];
		if (used[u]) {
			if (a[u][0] == x) {
				if (a[u][1] != y) return false;
			} else {
				int W = -(a[u][0] * a[u][1] + x * y);
				if (!fxd) {
					fxd = true;
					S = W;
				}
				if (S != W) return false;
			}
		} else {
			a[u][0] = x;
			a[u][1] = y;
			if (!dfs(u)) return false;
		}
	}
	return true;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u, x;
		scanf("%d%d%d", &v, &u, &x);
		v--;u--;
		g[v].push_back(mp(u, x));
		g[u].push_back(mp(v, x));
	}
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		comp.clear();
		fxd = false;
		a[i][0] = 1;
		a[i][1] = 0;
		if (!dfs(i)) {
			printf("NO\n");
			return 0;
		}
//		for (int v : comp)
//			eprintf("%d : %d %d\n", v, a[v][0], a[v][1]);
		if (!fxd) {
			vector<int> w;
			for (int v : comp)
				w.push_back(-a[v][0] * a[v][1]);
			sort(all(w));
			S = 2 * w[(int)w.size() / 2];
		}
		for (int v : comp) {
			int x = a[v][0] * S + a[v][1] * 2;
			ans[v] = (double)x / 2;
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%.1lf ", ans[i]);
	printf("\n");

	return 0;
}