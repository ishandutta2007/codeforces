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

const int N = 505;
int n, m;
bool g[N][N];
int ord[N];
int ordSz;
int par[N];
bool used[N];
vector<int> cyc;

void dfs1(int v) {
	used[v] = 1;
	for (int u = 0; u < n; u++) {
		if (!g[v][u]) continue;
		if (used[u]) continue;
		par[u] = v;
		dfs1(u);
	}
	ord[ordSz++] = v;
}

bool solve() {
	ordSz = 0;
	for (int i = 0; i < n; i++)
		used[i] = 0;
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs1(i);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (g[ord[j]][ord[i]])
				return false;
	return true;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v][u] = 1;
	}
	for (int i = 0; cyc.empty() && i < n; i++) {
		if (used[i]) continue;
		dfs1(i);
	}
	for (int i = 0; cyc.empty() && i < n; i++)
		for (int j = 0; cyc.empty() && j < i; j++) {
			int v = ord[i], u = ord[j];
			if (!g[u][v]) continue;
			while(u != v) {
				cyc.push_back(u);
				u = par[u];
			}
			cyc.push_back(v);
			reverse(all(cyc));
		}
	if (cyc.empty()) {
		printf("YES\n");
		return 0;
	}
	cyc.push_back(cyc[0]);
	for (int i = 0; i < (int)cyc.size() - 1; i++) {
		int v = cyc[i], u = cyc[i + 1];
		g[v][u] = 0;
		if (solve()) {
			printf("YES\n");
			return 0;
		}
		g[v][u] = 1;
	}
	printf("NO\n");

	return 0;
}