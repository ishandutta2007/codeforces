#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 500100;
bool used[N];
int ord[N];
int ordSz;
int a[N];
int nxt[N];
int st[N];
int stSz;
int n;
vector<int> g[N];

void dfs(int v) {
	used[v] = 1;
	for (int u : g[v]) {
		if (used[u]) continue;
		dfs(u);
	}
	ord[ordSz++] = v;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		g[i].clear();
	ordSz = stSz = 0;
	for (int i = 0; i < n; i++)
		used[i] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &nxt[i]);
		if (nxt[i] != -1)
			nxt[i]--;
	}
	st[stSz++] = n;
	for (int i = n - 1; i >= 0; i--) {
		if (nxt[i] != -1) {
			while(stSz > 0 && st[stSz - 1] < nxt[i]) {
				stSz--;
				g[i].push_back(st[stSz]);
			}
			if (nxt[i] != n)
				g[nxt[i]].push_back(i);
		}
		st[stSz++] = i;
	}
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		dfs(i);
	}
	for (int i = 0; i < n; i++)
		a[ord[i]] = i;
	stSz = 0;
	st[stSz++] = n;
	a[n] = n;
	for (int i = n - 1; i >= 0; i--) {
		while(a[i] > a[st[stSz - 1]]) stSz--;
		if (nxt[i] != -1 && nxt[i] != st[stSz - 1]) {
			printf("-1\n");
			return;
		}
		st[stSz++] = i;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i] + 1);
	printf("\n");
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}