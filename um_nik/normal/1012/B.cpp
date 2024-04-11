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

const int N = 400400;
int n, m, k;
vector<int> g[N];
bool used[N];

void dfs(int v) {
	used[v] = 1;
	for (int u : g[v]) {
		if (used[u]) continue;
		dfs(u);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	while(k--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;
		u += n - 1;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	int ans = -1;
	for (int v = 0; v < n + m; v++) {
		if (used[v]) continue;
		dfs(v);
		ans++;
	}
	printf("%d\n", ans);

	return 0;
}