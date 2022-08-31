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

const int N = 100100;
int n, m, q;
vector<int> g[N];
ll deg[N];
ll ANS;

ll get(int v) {
	return (deg[v] - (ll)g[v].size()) * (ll)g[v].size();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		if (v > u) swap(v, u);
		g[v].push_back(u);
		deg[v]++;
		deg[u]++;
	}
	for (int i = 1; i <= n; i++)
		ANS += get(i);
	printf("%lld\n", ANS);
	scanf("%d", &q);
	while(q--) {
		int v;
		scanf("%d", &v);
		while(!g[v].empty()) {
			int u = g[v].back();
			ANS -= get(v) + get(u);
			g[v].pop_back();
			g[u].push_back(v);
			ANS += get(v) + get(u);
		}
		printf("%lld\n", ANS);
	}

	return 0;
}