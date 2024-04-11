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

using namespace std;

const int N = 5e5;

int n, x, y;
int deg[N], f[N][2];
vector<int> g[N];

void dfs(int x, int px) {
	vector<int> h(3, 1e9);
	h[0] = 0;
	bool leaf = true;
	for (int i = 0; i < (int)g[x].size(); i++) {
		int y = g[x][i];
		if (y == px) continue;
		dfs(y, x);
//		if (x == 2) {
//			cerr << y << ": " << h[0] << " " << h[1] << " " << h[2] << endl;
//		}
		leaf = false;
		vector<int> hh(3);
		for (int j = 0; j < 3; j++) hh[j] = h[j] + f[y][0];
		for (int j = 1; j < 3; j++) hh[j] = min(hh[j], h[j - 1] + f[y][1]);
		h = hh;
	}
	if (leaf) {
		f[x][0] = 1;
		f[x][1] = 1;
		return;
	}
	f[x][0] = min(h[0] + 1, h[2] - 1);
	f[x][0] = min(h[1], f[x][0]);
	f[x][1] = h[1];
//	cerr << x << ": " << f[x][0] << " " << f[x][1] << endl;
//	cerr << x << ": " << h[0] << " " << h[1] << " " << h[2]  << endl;
}

long long solve( vector< pair<int, int> > e, int x, int y) {
	for (int i = 0; i < n; i++) {
		deg[i] = 0;
		g[i].clear();
	}
	n = e.size() + 1;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		u = e[i].first;
		v = e[i].second;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	if (x == y) {
		return (n - 1) * 1LL * x;
	}
	if (x < y) {
		dfs(0, -1);
		int cp = min(f[0][0], f[0][1]);
		return (cp - 1) * 1LL * y + (n - cp) * 1LL * x;
	} else {
		int mx = 0;
		for (int i = 0; i < n; i++) mx = max(mx, deg[i]);
		if (mx == n - 1) {
			return y * 1LL * (n - 2) + x;
		} else {
			return y * 1LL * (n - 1);
		}
	}
}

long long brute(vector< pair<int, int> > e, int x, int y) {
	set< pair<int, int> > s;
	for (int i = 0; i < (int)e.size(); i++) {
		s.insert(e[i]);
		s.insert(make_pair(e[i].second, e[i].first));
	}
	int n = (int)e.size() + 1;
	vector<int> nom(n);
	for (int i = 0; i < n; i++) nom[i] = i;
	long long ans = 1e9;
	do {
		long long cost = 0;
		for (int i = 1; i < n; i++) {
			if (s.find(make_pair(nom[i - 1], nom[i])) != s.end()) cost += x; else cost += y;
		}
		if (cost < ans) ans = cost;
	} while (next_permutation(nom.begin(), nom.end()));
	return ans;
}

void stress(bool flag) {
	if (!flag) return;
	srand(time(0));
	while (1) {
		vector< pair<int, int> > e;
		int n = 8;
		for (int i = 1; i < n; i++) {
			e.push_back(make_pair(i, rand() % i));
		}
		long long ans1 = solve(e, 1, 2);
		long long ans2 = brute(e, 1, 2);
		if (ans1 != ans2) {
			cerr << ans1 << "!=" << ans2 << endl;
			cout << n << " " << x << " " << y << endl;
			for (int i = 0; i < n - 1; i++) {
				cout << e[i].first << " " << e[i].second << endl;
			}
			assert(false);
		} else {
			cerr << "ok" << endl;
		}
	}
}

int main() {
	stress(0);
//	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	if (x == y) {
		cout << (n - 1) * 1LL * x << endl;
		return 0;
	}
	if (x < y) {
		dfs(0, -1);
		int cp = min(f[0][0], f[0][1]);
		cout << (cp - 1) * 1LL * y + (n - cp) * 1LL * x << endl;
	} else {
		int mx = 0;
		for (int i = 0; i < n; i++) mx = max(mx, deg[i]);
		if (mx == n - 1) {
			cout << y * 1LL * (n - 2) + x;
		} else {
			cout << y * 1LL * (n - 1) << endl;
		}
	}
}