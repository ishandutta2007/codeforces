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
set<int> used;
vector<int> g[N];
int n, m;

void dfs(int v) {
	int x = -1;
	used.erase(v);
	int pos = 0;
	sort(g[v].begin(), g[v].end());
	while(true) {
		auto it = used.upper_bound(x);
		if (it == used.end()) break;
		x = *it;
		while(pos < (int)g[v].size() && g[v][pos] < x) pos++;
		if (pos < (int)g[v].size() && g[v][pos] == x)
			continue;
		dfs(x);
	}
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
	int ans = -1;
	for (int i = 0; i < n; i++)
		used.insert(i);
	for (int v = 0; v < n; v++) {
		if (used.count(v) == 0) continue;
		ans++;
		dfs(v);
	}
	printf("%d\n", ans);

	return 0;
}