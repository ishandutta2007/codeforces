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
#define pll pair <ll, ll>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;

vector <int> ed[maxn];
ld v[maxn];
int sz[maxn];

int make(int u) {
	sz[u] = 1;

	for (int i = 0; i < (int)ed[u].size(); i++) {
		int x = ed[u][i];

		sz[u] += make(x);
	}

	return sz[u];
}

void dfs(int u) {
	ld now = 0;
	for (int i = 0; i < (int)ed[u].size(); i++) {
		now += sz[ed[u][i]];
	}

	now /= 2;

	for (int i = 0; i < (int)ed[u].size(); i++) {
		v[ed[u][i]] = v[u] + 1 + now - (ld)sz[ed[u][i]] / 2;
	}

	for (int i = 0; i < (int)ed[u].size(); i++) {
		dfs(ed[u][i]);
	}
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		int p;

		scanf("%d", &p);

		ed[p].push_back(i);
	}

	v[1] = 1.0;

	make(1);
	dfs(1);

	for (int i = 1; i <= n; i++) {
		printf("%.10lf ", v[i]);
	}

	return 0;
}