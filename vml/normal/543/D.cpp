#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>
#include <unordered_map>

using namespace std;

const int maxn = (int)2e5 + 10;

vector <long long> pref[maxn];
vector <long long> suff[maxn];
long long rs[maxn];
int num[maxn];
long long ans[maxn];
int p[maxn];

long long q = (int)1e9 + 7;

vector <int> ed[maxn];

long long dfs(int v, int par) {
	p[v] = par;
	vector <long long> a;
	a.resize(ed[v].size());

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != par) {
			long long x = (1 + dfs(u, v)) % q;

			a[i] = x;
		} else {
			a[i] = 1;
		}
	}

	if (!a.empty()) {
		long long now = 1;
		pref[v].resize(a.size());

		for (int i = 0; i < (int)a.size(); i++) {
			now *= a[i];
			now %= q;
			pref[v][i] = now;
		}

		suff[v].resize(a.size());
		rs[v] = now;

		now = 1;

		for (int i = (int)a.size() - 1; i >= 0; i--) {
			now *= a[i];
			now %= q;
			suff[v][i] = now;
		}
	}

	return rs[v];
}

map <pair <int, int>, long long> dp;

void dfs1(int v, int par) {
	if (par == -1) {
		ans[v] = rs[v];

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i];

			long long f = 1;

			if (i != 0) {
				f *= pref[v][i - 1];
				f %= q;
			}

			if (i != (int)ed[v].size() - 1) {
				f *= suff[v][i + 1];
				f %= q;
			}

			dp[make_pair(v, u)] = f;
		}
	} else {
		ans[v] = rs[v];

		ans[v] *= (dp[make_pair(par, v)] + 1);
		ans[v] %= q;

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i];

			if (u != par) {
				long long f = dp[make_pair(par, v)] + 1;
				f %= q;

				if (i != 0) {
					f *= pref[v][i - 1];
					f %= q;
				}

				if (i != (int)ed[v].size() - 1) {
					f *= suff[v][i + 1];
					f %= q;
				}

				dp[make_pair(v, u)] = f;
			}
		}
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != par) {
			dfs1(u, v);
		}
	}
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		int x;

		scanf("%d", &x);

		ed[x].push_back(i);
		ed[i].push_back(x);
	}

	dfs(1, -1);
	dfs1(1, -1);

	for (int i = 1; i <= n; i++) {
		printf("%d ", (int)ans[i]);
	}

	return 0;
}