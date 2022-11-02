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

const int INF = 1e9;
const int N = 1e5;
const int K = 17;
const int A = 10;

vector<int> e[N][K];
vector<int> ee[N];
int pr[N][K], tin[N], tout[N];
vector<int> g[N];
int n, m, q, curt;

void dfs(int x, int px) {
	if (px != -1) e[x][0] = ee[px];
	pr[x][0] = px;
	tin[x] = curt++;
	for (int i = 1; i < K; i++) {
		if (pr[x][i - 1] == -1) {
			pr[x][i] = -1; 
		} else {
			pr[x][i] = pr[pr[x][i - 1]][i - 1];
			e[x][i].resize(e[x][i - 1].size() + e[pr[x][i - 1]][i - 1].size());
			merge(
				e[x][i - 1].begin(), e[x][i - 1].end(),
				e[pr[x][i - 1]][i - 1].begin(), e[pr[x][i - 1]][i - 1].end(),
				e[x][i].begin()
			);
			if ((int)e[x][i].size() > A) e[x][i].resize(A);
		}
	}
	for (int i = 0; i < (int)g[x].size(); i++) {
		int y = g[x][i];
		if (y == px) continue;
		dfs(y, x);
	}
	tout[x] = curt++;
}

bool is_up(int x, int y) {
	return ((tin[x] <= tin[y]) && (tout[y] <= tout[x]));
}

vector<int> get(int x, int z) {
	vector<int> res = ee[x];
	if (x == z) return res;
	for (int i = K - 1; i >= 0; i--) {
		int px = pr[x][i];
		if ((px == -1) || (is_up(px, z))) continue;
		// cerr << x << " -> " << px << endl;
		vector<int> nres(res.size() + e[x][i].size());
		merge(res.begin(), res.end(),
			e[x][i].begin(), e[x][i].end(),
			nres.begin());
		if ((int)nres.size() > A) nres.resize(A);
		res = nres;
		x = px;
	}
	vector<int> nres(res.size() + e[x][0].size());
	merge(res.begin(), res.end(), 
		e[x][0].begin(), e[x][0].end(),
		nres.begin());
	if ((int)nres.size() > A) nres.resize(A);
	res = nres;
	return res;
}

int get_lca(int x, int y) {
	if (is_up(x, y)) return x;
	for (int i = K - 1; i >= 0; i--) {
		int px = pr[x][i];
		if ((px == -1) || (is_up(px, y))) continue;
		x = px;
	}
	return pr[x][0];
}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		--x;
		if ((int)ee[x].size() < A) ee[x].push_back(i);
	}
	curt = 0;
	dfs(0, -1);
	for (int i = 0; i < q; i++) {
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		--x; --y;
		int z = get_lca(x, y);
		vector<int> u = get(x, z);
		vector<int> v = get(y, z);
		vector<int> uv(u.size() + v.size());
		merge(u.begin(), u.end(), v.begin(), v.end(), uv.begin());
		uv.resize(unique(uv.begin(), uv.end()) - uv.begin());
		if ((int)uv.size() > k) uv.resize(k);
		printf("%d ", (int)uv.size());
		for (int j = 0; j < (int)uv.size(); j++) printf("%d ", uv[j] + 1);
		puts("");
	}
}