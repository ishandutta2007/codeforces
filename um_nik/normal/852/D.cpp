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

const int INF = (int)1e7;

const int N = 620;
const int M = 210;
int g[N][N];
int D[M][N];
int st[M];
int n, m, k;
bool G[M][N];
int mt[N];
bool used[N];
int q[N];
int topQ;

void read() {
	int e;
	scanf("%d%d%d%d", &n, &e, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d", &st[i]);
		st[i]--;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = INF;
	for (int i = 0; i < n; i++)
		g[i][i] = 0;
	while(e--) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		v--;u--;
		g[v][u] = g[u][v] = min(g[v][u], w);
	}
	return;
}

bool dfs(int x) {
	if (used[x]) return false;
	used[x] = 1;
	for (int y = 0; y < n; y++) {
		if (!G[x][y]) continue;
		if (mt[y] == -1 || dfs(mt[y])) {
			mt[y] = x;
			return true;
		}
	}
	return false;
}
bool solve(int X) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			G[i][j] = (D[i][j] <= X);
	for (int i = 0; i < n; i++)
		mt[i] = -1;
	int res = 0;
	for (int x = 0; x < m; x++) {
		for (int i = 0; i < m; i++)
			used[i] = 0;
		res += dfs(x);
	}
	return res >= k;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int h = 0; h < n; h++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = min(g[i][j], g[i][h] + g[h][j]);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			D[i][j] = g[st[i]][j];
	int l = -1, r = INF;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	if (r == INF)
		printf("-1\n");
	else
		printf("%d\n", r);

	return 0;
}