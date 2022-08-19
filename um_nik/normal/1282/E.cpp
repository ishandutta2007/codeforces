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

const int N = 100100;
vector<int> triangForV[N];
int ans[N];
int ans2[N];
int tr[N][3];
int n;
int deg[N];
bool aliveTr[N];
bool aliveV[N];
int q[N];
int topQ;
int nxt[N];

int findAlive(int v) {
	for (int id : triangForV[v])
		if (aliveTr[id])
			return id;
	throw;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		triangForV[i].clear();
		deg[i] = 0;
		aliveV[i] = true;
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &tr[i][j]);
			triangForV[tr[i][j]].push_back(i);
			deg[tr[i][j]]++;
		}
		aliveTr[i] = true;
	}
	topQ = 0;
	for (int v = 1; v <= n; v++)
		if (deg[v] == 1)
			q[topQ++] = v;
	for (int i = 0; i < n - 2; i++) {
		int v = q[i];
//		eprintf("v = %d\n", v);
		int id = findAlive(v);
		aliveV[v] = false;
		aliveTr[id] = false;
		ans2[i] = id;
		for (int j = 0; j < 3; j++) {
			int u = tr[id][j];
			deg[u]--;
			if (deg[u] == 1)
				q[topQ++] = u;
		}
	}
	nxt[q[n - 2]] = q[n - 1];
	nxt[q[n - 1]] = q[n - 2];
	for (int i = n - 3; i >= 0; i--) {
		int id = ans2[i];
		int v = q[i];
		int u = -1, w = -1;
		for (int j = 0; j < 3; j++) {
			if (tr[id][j] == v) continue;
			if (u == -1)
				u = tr[id][j];
			else
				w = tr[id][j];
		}
		if (nxt[u] != w) swap(u, w);
		if (nxt[u] != w) throw;
		nxt[v] = w;
		nxt[u] = v;
	}
	int sz = 0;
	int v = 1;
	while(sz < n) {
		ans[sz++] = v;
		v = nxt[v];
	}
	if (v != 1) throw;
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	for (int i = 0; i < n - 2; i++)
		printf("%d ", ans2[i] + 1);
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