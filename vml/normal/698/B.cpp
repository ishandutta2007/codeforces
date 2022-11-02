#pragma comment(linker, "/STACK:3200000")
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

const int maxn = (int)2e5 + 10;

int v[maxn];
bool st[maxn];
int used[maxn];

vector <int> f;

void dfs(int x) {
	used[x] = 1;

	if (used[v[x]] == 1) {
		f.push_back(x);
	} else if (used[v[x]] == 0) {
		dfs(v[x]);
	}

	used[x] = 2;
}

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	int p = -1;

	for (int i = 1; i <= n; i++) {
		if (v[i] == i) {
			p = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		st[v[i]] = true;
	}

	for (int i = 1; i <= n; i++) {
		if (!st[i]) {
			dfs(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (used[i] == 0) {
			dfs(i);
		}
	}

	if (p == -1) {
		printf("%d\n", (int)f.size());
		p = f[0];
		v[p] = p;
	} else {
		printf("%d\n", (int)f.size() - 1);
	}

	for (int i = 0; i < (int)f.size(); i++) {
		if (f[i] != p) {
			v[f[i]] = p;
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", v[i]);
	}

	return 0;
}