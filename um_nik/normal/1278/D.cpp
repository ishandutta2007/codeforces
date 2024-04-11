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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 500500;
int par[N];
int sz[N];
int n;
int b[N];
int ev[2 * N];
int m;

int getPar(int v) {
	return par[v] == -1 ? v : par[v] = getPar(par[v]);
}
bool unite(int v, int u) {
	v = getPar(v);
	u = getPar(u);
	if (v == u) return false;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;r--;
		ev[l] = i;
		ev[r] = -i;
	}
	for (int i = 1; i <= n; i++) {
		par[i] = -1;
		sz[i] = 1;
	}
	m = 0;
	int cntEdges = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (ev[i] > 0) {
			b[m++] = ev[i];
		} else {
			int v = -ev[i];
			int p = m - 1;
			while(b[p] != v) p--;
			for (int j = p + 1; j < m; j++) {
				cntEdges++;
				if (!unite(v, b[j])) {
					printf("NO\n");
					return 0;
				}
				b[j - 1] = b[j];
			}
			m--;
		}
	}
	if (cntEdges == n - 1)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}