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
vector<int> g[N];
vector<int> rg[N];
int deg[N];
bool used[N];
int par[N];
int S;
int n, m;
int topQ;
int q[N];

void dfs(int v) {
	used[v] = 1;
	for (int u : g[v % n]) {
		int w = u;
		if (v < n) w += n;
		if (used[w]) continue;
		par[w] = v;
		dfs(w);
	}
}

void printAns(int v) {
	vector<int> ans;
	while(v != S) {
		ans.push_back(v % n);
		v = par[v];
	}
	ans.push_back(S);
	reverse(ans.begin(), ans.end());
	printf("Win\n");
	for (int x : ans)
		printf("%d ", x + 1);
	printf("\n");
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int v = 0; v < n; v++) {
		int k;
		scanf("%d", &k);
		while(k--) {
			int u;
			scanf("%d", &u);
			u--;
			g[v].push_back(u);
			rg[u].push_back(v);
		}
	}
	scanf("%d", &S);
	S--;
	dfs(S);
	for (int v = n; v < 2 * n; v++) {
		if (used[v] && g[v % n].empty()) {
			printAns(v);
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
		used[i] = 0;
	for (int v = 0; v < n; v++) {
		deg[v] = (int)g[v].size();
		if (deg[v] == 0)
			q[topQ++] = v;
	}
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		for (int u : rg[v]) {
			deg[u]--;
			if (deg[u] == 0) {
				q[topQ++] = u;
			}
		}
	}
	if (deg[S] > 0)
		printf("Draw\n");
	else
		printf("Lose\n");

	return 0;
}