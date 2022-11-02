#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
using namespace std;

#define N 210000
int fa[N], dep[N], rk[N];
vector <int> ve[N];
int a[N];
int n;

void dfs(int k, int f) {
	fa[k] = f;
	dep[k] = dep[f] + 1;
	for (int i = 0; i < (int) ve[k].size(); i++)
		if (ve[k][i] != f)
			dfs(ve[k][i], k);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ve[x].push_back(y);
		ve[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
		if (dep[a[i]] > dep[a[i + 1]]) {
			printf("No\n");
			return 0;
		}
	for (int i = 1; i <= n; i++)
		rk[a[i]] = i;
	for (int i = 1; i < n; i++)
		if (dep[a[i]] == dep[a[i + 1]] && rk[fa[a[i]]] > rk[fa[a[i + 1]]]) {
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
}