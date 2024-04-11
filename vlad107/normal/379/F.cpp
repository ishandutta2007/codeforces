#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define INF 1000000000
#define N 1500500
#define K 20
#define time asdgasdgasd

using namespace std;

int tin[N], tout[N], pred[N][K], a[N], dep[N], time, n, m, x, mt, ans, e;
vector<int> g[N];

int dfs(int x) {
	for (int i = 1; i < 20; i++)
		if (pred[x][i - 1] == -1)
			pred[x][i] = -1;
		else
			pred[x][i] = pred[pred[x][i - 1]][i - 1];
	time++;
	tin[x] = time;
	for (int i = 0; i < g[x].size(); i++) {
		dep[g[x][i]] = dep[x] + 1;
		pred[g[x][i]][0] = x;
		dfs(g[x][i]);
	}
	time++;
	tout[x] = time;
}

int lca(int x, int y) {
	if (x == y)
		return x;
	if ((tin[y] < tin[x]) && (tout[x] < tout[y]))
		return y;
	swap(x, y);
	if ((tin[y] < tin[x]) && (tout[x] < tout[y]))
		return y;
	for (int i = 19; i >= 0; i--) {
		if (pred[x][i] == -1)
			continue;
		int t = pred[x][i];
		if ((tin[t] < tin[y]) && (tout[y] < tout[t]))
			continue;
		x = t;
	}
	return pred[x][0];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &m);
	g[0].push_back(1);
	g[0].push_back(2);
	g[0].push_back(3);
	dep[0] = 0;
	dep[1] = 1;
	dep[2] = 1;
	dep[3] = 1;
	n = 4;
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
		--a[i];
		g[a[i]].push_back(n);
		g[a[i]].push_back(n + 1);
		n += 2;
	}
	memset(pred, -1, sizeof(pred));
	dfs(0);
	mt = 1;
	e = 1;
	n = 4;
	ans = 2;
	for (int i = 0; i < m; i++) {
		x = a[i];
		n += 2;
		if (dep[n - 1] == mt + 1) {
			ans++;
			mt++;
			e = n - 1;
		} else
			ans = max(ans, dep[n - 1] + dep[e] - 2 * dep[lca(n - 1, e)]);
		printf("%d\n", ans);
	}
}