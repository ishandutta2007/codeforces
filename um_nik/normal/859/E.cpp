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

const ll MOD = (ll)1e9 + 7;
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = (int)2e5 + 3;
int n;
ll ans = 1;
vector<int> g[N];
bool used[N];
bool bad[N];
vector<int> a;

void dfs(int v) {
	used[v] = 1;
	a.push_back(v);
	for (int u : g[v])
		if (!used[u])
			dfs(u);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
		if (x == y) bad[x] = 1;
	}
	n *= 2;
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		a.clear();
		dfs(i);
		int k = 0;
		for (int v : a)
			k += (int)g[v].size();
		if (k & 1) throw;
		k /= 2;
		k = (int)a.size() - k;
		if (k != 0 && k != 1) throw;
		if (k == 1) {
			ans = mult(ans, (int)a.size());
		} else {
			bool good = true;
			for (int v : a)
				good &= !bad[v];
			if (good) ans = mult(ans, 2);
		}
	}
	printf("%lld\n", ans);

	return 0;
}