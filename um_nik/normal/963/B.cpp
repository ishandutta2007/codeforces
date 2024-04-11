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

const int N = 200200;
int n;
vector<int> g[N];
int ans[N];
int ansSz;
bool used[N];

void kill(int v, int par) {
	if (used[v]) return;
	ans[ansSz++] = v;
	used[v] = 1;
	for (int u : g[v])
		if (u != par)
			kill(u, v);
		
}

void dfs(int v, int par) {
	int cnt = 1;
	if (par == -1) cnt = 0;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
		if (!used[u]) cnt ^= 1;
	}
	if (cnt == 0) kill(v, par);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int v = 1; v <= n; v++) {
		int x;
		scanf("%d", &x);
		if (x == 0) continue;
		g[v].push_back(x);
		g[x].push_back(v);
	}
	dfs(1, -1);
	if (ansSz != n) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);

	return 0;
}