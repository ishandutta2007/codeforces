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

const int N = 200200;
int n, m, k;
vector<int> g[N];
int dist[N];
int q[N];
int topQ;
pii a[N];
int suf[N];
int b[N];

void BFS(int v) {
	topQ = 0;
	for (int i = 0; i < n; i++)
		dist[i] = N;
	dist[v] = 0;
	q[topQ++] = v;
	for (int i = 0; i < topQ; i++) {
		v = q[i];
		for (int u : g[v]) {
			if (dist[u] <= dist[v] + 1) continue;
			dist[u] = dist[v] + 1;
			q[topQ++] = u;
		}
	}
}

bool check(int x) {
	for (int i = 0; i < k; i++) {
		int pos = lower_bound(a, a + k, mp(x - a[i].second, -1)) - a;
		pos = max(pos, i + 1);
		if (a[i].first + suf[pos] >= x)
			return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &b[i]);
		b[i]--;
	}
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	BFS(0);
	for (int i = 0; i < k; i++)
		a[i].first = dist[b[i]];
	BFS(n - 1);
	int l = 0, r = dist[0];
	for (int i = 0; i < k; i++)
		a[i].second = dist[b[i]];
	sort(a, a + k);
	suf[k] = -N;
	for (int i = k - 1; i >= 0; i--) {
		suf[i] = max(suf[i + 1], a[i].second);
	}
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (check(x))
			r = x;
		else
			l = x;
	}
	printf("%d\n", r);

	return 0;
}