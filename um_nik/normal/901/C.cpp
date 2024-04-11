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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 300300;
int ed[N][2];
int n, m;
vector<int> g[N];
int h[N];
int minH[N];
bool isBridge[N];
ll a[N];
int minV, maxV;
bool used[N];
ll prefSum[N];

int getOther(int id, int v) {
	return v ^ ed[id][0] ^ ed[id][1];
}

void dfs1(int v, int par) {
	minH[v] = h[v];
	for (int id : g[v]) {
		if (id == par) continue;
		int u = getOther(id, v);
		if (h[u] != -1) {
			if (h[u] < h[v])
				minH[v] = min(minH[v], h[u]);
			continue;
		}
		h[u] = h[v] + 1;
		dfs1(u, id);
		if (minH[u] > h[v]) isBridge[id] = 1;
		minH[v] = min(minH[v], minH[u]);
	}
}

void dfs2(int v) {
	used[v] = 1;
	minV = min(minV, v);
	maxV = max(maxV, v);
	for (int id : g[v]) {
		if (isBridge[id]) continue;
		int u = getOther(id, v);
		if (used[u]) continue;
		dfs2(u);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &ed[i][0], &ed[i][1]);
		ed[i][0]--;
		ed[i][1]--;
		g[ed[i][0]].push_back(i);
		g[ed[i][1]].push_back(i);
	}
	for (int i = 0; i < n; i++)
		h[i] = -1;
	for (int i = 0; i < n; i++) {
		if (h[i] != -1) continue;
		h[i] = 0;
		dfs1(i, -1);
	}
	for (int i = 0; i < n; i++)
		a[i] = n;
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		minV = n;
		maxV = -1;
		dfs2(i);
		if (minV < maxV) a[minV] = min(a[minV], (ll)maxV);
	}
	for (int i = n - 2; i >= 0; i--)
		a[i] = min(a[i], a[i + 1]);
/*
	for (int i = 0; i < n; i++)
		printf("%lld ", a[i]);
	printf("\n");
*/
	prefSum[0] = 0;
	for (int i = 0; i < n; i++)
		prefSum[i + 1] = prefSum[i] + a[i];

	int q;
	scanf("%d", &q);
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		int pos = lower_bound(a, a + n, (ll)r) - a;
		if (pos > r) throw;
		if (pos < l) pos = l;
		ll ans = prefSum[pos] - prefSum[l] + (ll)(r - pos) * r - (ll)(r - l) * l - (ll)(r - l) * (r - l - 1) / 2;
		printf("%lld\n", ans);
	}

	return 0;
}