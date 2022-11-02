#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;

vector <int> ed[maxn];
int cl[maxn];
vector <int> ans[2];

void dfs(int v, int c) {
	cl[v] = c;
	ans[c - 1].push_back(v);

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (cl[u] == 0) {
			dfs(u, 3 - c);
		} else if (cl[u] == cl[v]) {
			cout << -1 << endl;
			exit(0);
		}
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (cl[i] == 0) {
			dfs(i, 1);
		}
	}

	for (int i = 0; i < 2; i++) {
		cout << ans[i].size() << endl;
		for (int j = 0; j < (int)ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}