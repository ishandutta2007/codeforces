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
bool used[N];
vector<int> g[N];
int n, m;
pii a[N];
int k;
int ans;
int mx;

void dfs(int v) {
	used[v] = 1;
	mx = max(mx, v);
	for (int u : g[v])
		if (!used[u])
			dfs(u);
}

void add(pii t) {
	while(k > 0 && a[k - 1].second > t.first) {
		ans++;
		k--;
		t.first = min(t.first, a[k].first);
		t.second = max(t.second, a[k].second);
	}
	a[k++] = t;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int v = 0; v < n; v++) {
		if (used[v]) continue;
		mx = -1;
		dfs(v);
		add(mp(v, mx));
	}
	printf("%d\n", ans);

	return 0;
}