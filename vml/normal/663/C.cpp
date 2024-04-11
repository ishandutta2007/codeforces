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
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 
 
using namespace std;

const int maxn = (int)1e5 + 10;

vector <int> ed[maxn][2];
int n;

int num[maxn];
int cnt[maxn];

void dfs(int v, int cl) {
	num[v] = cl;

	for (int i = 0; i < (int)ed[v][0].size(); i++) {
		int u = ed[v][0][i];

		if (num[u] == -1) {
			dfs(u, cl);
		}
	}
}

vector <int> edg[maxn];
int col[maxn];
vector <int> on;
vector <int> tw;
int a, b;

bool getans(int v, int c) {
	col[v] = c;

	if (c == 1) {
		a += cnt[v];
		on.push_back(v);
	} else {
		b += cnt[v];
		tw.push_back(v);
	}

	for (int i = 0; i < (int)edg[v].size(); i++) {
		int u = edg[v][i];

		if (col[u] == -1) {
			if (!getans(u, 3 - c)) {
				return false;
			}
		} else if (col[u] == col[v]) {
			return false;
		}
	}

	return true;
}

vector <int> now;

bool go() {
	memset(num, -1, sizeof num);
	memset(cnt, 0, sizeof cnt);

	int it = 0;

	for (int i = 1; i <= n; i++) {
		if (num[i] == -1) {
			dfs(i, it);
			it++;
		}
	}

	for (int i = 0; i < it; i++) {
		edg[i].clear();
	}

	for (int i = 1; i <= n; i++) {
		cnt[num[i]]++;
		for (int j = 0; j < (int)ed[i][1].size(); j++) {
			int u = ed[i][1][j];

			if (num[i] == num[u]) {
				return false;
			}

			edg[num[i]].push_back(num[u]);
			edg[num[u]].push_back(num[i]);
		}
	}

	memset(col, -1, sizeof col);

	for (int i = 0; i < it; i++) {
		if (col[i] == -1) {
			a = 0;
			b = 0;
			on.clear();
			tw.clear();

			if (!getans(i, 1)) {
				return false;
			}

			if (a > b) {
				for (int j = 0; j < (int)on.size(); j++) {
					col[on[j]] = 2;
				}

				for (int j = 0; j < (int)tw.size(); j++) {
					col[tw[j]] = 1;
				}
			}
		}
	}

	now.clear();

	for (int i = 1; i <= n; i++) {
		if (col[num[i]] == 1) {
			now.push_back(i);
		}
	}

	return true;
}

int main() {
	int m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int x, y;
		char c;

		scanf("%d %d %c", &x, &y, &c);

		if (c == 'R') {
			ed[x][0].push_back(y);
			ed[y][0].push_back(x);
		} else {
			ed[x][1].push_back(y);
			ed[y][1].push_back(x);
		}
	}

	vector <int> ans(n + 10, 0);

	if (go()) {
		ans = now;
	}

	for (int i = 1; i <= n; i++) {
		swap(ed[i][0], ed[i][1]);
	}

	if (go()) {
		if (ans.size() > now.size()) {
			ans = now;
		}
	}

	if ((int)ans.size() > n) {
		cout << -1 << endl;
	} else {
		cout << ans.size() << endl;

		for (int i = 0; i < (int)ans.size(); i++) {
			printf("%d ", ans[i]);
		}
	}

	return 0;
}