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

const ll MOD = (ll)1e9 + 7;

const int N = (int)12e5 + 7;
const int A = 10;
int n, m, k;
vector<pii> g[N];
int cc[A][2];
int dist[N];
int q[N];
int topQ;
ll ans[N];
int pos[N];

void addEdge(int v, int u, int w) {
	int z = 0;
	while(w > 0) {
		cc[z++][1] = w % 10;
		w /= 10;
	}
	cc[0][0] = u;
	cc[z][0] = v;
	for (int i = 1; i < z; i++)
		cc[i][0] = k++;
	for (int i = z - 1; i >= 0; i--) {
		g[cc[i + 1][0]].push_back(mp(cc[i][1], cc[i][0]));
	}
}

void dfs(vector<int> vv) {
	for (int c = 0; c < A; c++) {
		vector<int> uu;
		for (int v : vv) {
			while(pos[v] < (int)g[v].size() && g[v][pos[v]].first == c) {
				int u = g[v][pos[v]].second;
				pos[v]++;
				if (dist[u] == dist[v] + 1 && ans[u] == -1) {
					ans[u] = (ans[v] * 10 + c) % MOD;
					uu.push_back(u);
				}
			}
		}
		if (!uu.empty()) dfs(uu);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	k = n;
	for (int i = 1; i <= m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		addEdge(v, u, i);
		addEdge(u, v, i);
	}
	for (int v = 0; v < k; v++)
		sort(g[v].begin(), g[v].end());
	for (int v = 0; v < k; v++)
		dist[v] = N;
	dist[0] = 0;
	q[topQ++] = 0;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		for (pii e : g[v]) {
			int u = e.second;
			if (dist[u] > dist[v] + 1) {
				dist[u] = dist[v] + 1;
				q[topQ++] = u;
			}
		}
	}
	for (int v = 0; v < k; v++)
		ans[v] = -1;
	ans[0] = 0;
	dfs({0});
	for (int i = 1; i < n; i++)
		printf("%lld\n", ans[i]);

	return 0;
}