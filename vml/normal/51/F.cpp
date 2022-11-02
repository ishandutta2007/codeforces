/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;
vector <int> ed[maxn];
int tin[maxn], tup[maxn];
bool used[maxn];

#define tm asjdhajkh

int tm = 0;

vector <pii> a, b;

void dfs(int v, int p = -1) {
	used[v] = true;
	tin[v] = tm++;
	tup[v] = tin[v];

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u == p) {
			continue;
		}

		if (used[u]) {
			tup[v] = min(tup[v], tin[u]);
		} else {
			dfs(u, v);
			tup[v] = min(tup[v], tup[u]);

			if (tup[u] > tin[v]) {
				a.push_back(mp(min(v, u), max(v, u)));
			}
		}
	}
}

int p[maxn];

int getp(int x) {
	if (p[x] == x) {
		return x;
	}

	return p[x] = getp(p[x]);
}

vector <int> ver;

void make(int v, int p = -1) {
	used[v] = true;
	ver.push_back(v);

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (used[u] && u != p) {
			throw 1;
		}

		if (!used[u]) {
			make(u, v);
		}
	}
}

int dp[maxn];

void build(int v, int p = -1) {
	dp[v] = 0;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			build(u, v);
			if ((int)ed[u].size() > 1) {
				dp[v] += dp[u] + 1;
			}
		}
	}
}

int go(int v, int sum = 0, int p = -1) {
	int res = (int)1e9;

	if ((int)ed[v].size() <= 1 && p != -1) {
		res = sum;
		return res;
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			int x = dp[u];
			if ((int)ed[u].size() > 1) {
				x += 1;
			}

			sum += x;
		}
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			int x = dp[u];
			
			if ((int)ed[u].size() > 1) {
				x += 1;
			}

			res = min(res, go(u, sum - x, v));
		}
	}

	return res;
}

int main() {
	int n, m;

	cin >> n >> m;

	set <pii> s;

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);
		b.push_back(mp(min(x, y), max(x, y)));
	}

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			dfs(i);
		}
	}

	memset(used, 0, sizeof used);

	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}

	int ans = n - 1 - (int)a.size();
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int pos = 0;

	for (int i = 0; i < (int)b.size(); i++) {
		if (pos < (int)a.size() && a[pos] == b[i]) {
			pos++;
			continue;
		}

		int x = getp(b[i].first);
		int y = getp(b[i].second);

		p[x] = y;
	}

	if (pos != (int)a.size()) {
		throw 1;
	}

	for (int i = 1; i <= n; i++) {
		ed[i].clear();
	}

	for (int i = 0; i < (int)a.size(); i++) {
		int x = getp(a[i].first);
		int y = getp(a[i].second);

		if (x == y) {
			throw 1;
		}

		ed[x].push_back(y);
		ed[y].push_back(x);

		if (x == y || s.count(mp(x, y))) {
			throw 1;
		}

		s.insert(mp(x, y));
		s.insert(mp(y, x));
	}

	for (int i = 1; i <= n; i++) {
		if (p[i] != i) {
			continue;
		}

		if (!used[i]) {
			ver.clear();
			make(i);

			int res = (int)ver.size();

			for (int j = 0; j < (int)ver.size(); j++) {
				if (ed[ver[j]].empty()) {
					res = 0;
					break;
				}
				build(ver[j]);
				res = min(res, go(ver[j]));
			}

			ans += res;
		}
	}

	cout << ans << endl;

	return 0;
}