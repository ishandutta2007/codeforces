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

const int N = 100100;
int n, m, k;
vector<int> g[N];
int h[N];
int par[N];
vector<int> a[N];

void dfs(int v) {
	for (int u : g[v]) {
		if (h[u] == -1) {
			h[u] = h[v] + 1;
			par[u] = v;
			dfs(u);
		} else if (h[u] < h[v] - 1 && h[v] - h[u] >= k - 1) {
			printf("2\n%d\n", h[v] - h[u] + 1);
			int w = v;
			while(w != u) {
				printf("%d ", w);
				w = par[w];
			}
			printf("%d\n", u);
			exit(0);
		}
	}
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	k = 1;
	while(k * k < n) k++;
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	h[1] = 0;
	dfs(1);

	for (int v = 1; v <= n; v++) {
		int c = h[v] % (k - 1);
		a[c].push_back(v);
		if ((int)a[c].size() == k) {
			printf("1\n");
			for (int x : a[c])
				printf("%d ", x);
			printf("\n");
			exit(0);
		}
	}
	throw;
	return 0;
}