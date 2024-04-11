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

const int maxn = 5010;

int used[maxn];
int tin[maxn];
int t = 0;
int tup[maxn];
vector <int> st;
vector <int> v[maxn];
vector <int> ed[maxn];
int pos = 0;
int col[maxn];

void dfs(int u) {
	used[u] = 1;
	t++;
	tin[u] = t;
	tup[u] = t;
	st.push_back(u);

	for (int i = 0; i < (int)ed[u].size(); i++) {
		int w = ed[u][i];

		if (used[w] == 2) {
			continue;
		}

		if (used[w] == 1) {
			tup[u] = min(tup[u], tin[w]);
		} else {
			dfs(w);

			tup[u] = min(tup[u], tup[w]);
		}
	}

	if (tup[u] == tin[u]) {
		col[u] = pos;
		used[u] = 2;
		while (st.back() != u) {
			v[pos].push_back(st.back());
			col[st.back()] = pos;
			used[st.back()] = 2;
			st.pop_back();
		}

		v[pos].push_back(st.back());
		st.pop_back();
		pos++;
	}
}

int dst[maxn];

int go(int u) {
	int c = col[u];

	for (int i = 0; i < (int)v[c].size(); i++) {
		dst[v[c][i]] = (int)1e9;
	}

	dst[u] = 0;

	queue <int> q;

	q.push(u);

	while (!q.empty()) {
		int w = q.front();
		q.pop();

		for (int i = 0; i < (int)ed[w].size(); i++) {
			int x = ed[w][i];

			if (x == u) {
				return dst[w] + 1;
			}

			if (dst[x] > dst[w] + 1) {
				dst[x] = dst[w] + 1;
				q.push(x);
			}
		}
	}

	throw 1;
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
	}

	for (int i = 1; i <= n; i++) {
		if (used[i] == 0) {
			dfs(i);
		}
	}

	int ans = n;

	for (int i = 0; i < pos; i++) {
		bool st = false;

		for (int j = 0; j < (int)v[i].size(); j++) {
			int u = v[i][j];
			for (int k = 0; k < (int)ed[u].size(); k++) {
				int w = ed[u][k];

				if (col[u] != col[w]) {
					st = true;
				}
			}
		}

		if (st) {
			continue;
		}

		if (v[i].size() == 1) {
			continue;
		}

		int cnt = n;

		for (int j = 0; j < (int)v[i].size(); j++) {
			int u = v[i][j];

			cnt = min(cnt, go(u));
		}

		ans += cnt * 998;
		ans++;
	}

	cout << ans << endl;

	return 0;
}