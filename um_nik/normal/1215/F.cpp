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

const int N = 400400;
//const int N = 333;
const int V = 4 * N;
vector<int> g[V], rg[V];

void addEdge(int v, int u) {
	g[v].push_back(u);
	rg[u].push_back(v);
}

int n, q1, q2;
int segm[N][2];
pii ordByL[N];
pii ordByR[N];

int ord[V];
pii ord2[V];
int ordSz;
int col[V];
bool used[V];
int ans[V];
int C = 1;

void read() {
	scanf("%d%d%d%d", &q1, &n, &q2, &q2);
	while(q1--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		addEdge(2 * v, 2 * u + 1);
		addEdge(2 * u, 2 * v + 1);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &segm[i][0], &segm[i][1]);
		ordByL[i] = mp(segm[i][0], i);
		ordByR[i] = mp(segm[i][1], i);
	}
	sort(ordByL, ordByL + n);
	sort(ordByR, ordByR + n);
	while(q2--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		addEdge(2 * v + 1, 2 * u);
		addEdge(2 * u + 1, 2 * v);
	}
	for (int i = 0; i < n; i++) {
		addEdge(2 * n + i, 2 * ordByL[i].second);
		if (i > 0) addEdge(2 * n + i - 1, 2 * n + i);
	}
	for (int i = 0; i < n; i++) {
		addEdge(3 * n + i, 2 * ordByR[i].second);
		if (i > 0) addEdge(3 * n + i, 3 * n + i - 1);
	}
	for (int i = 0; i < n; i++) {
		int p = lower_bound(ordByR, ordByR + n, mp(segm[i][0], -1)) - ordByR - 1;
		if (p >= 0) addEdge(2 * i + 1, 3 * n + p);
		p = lower_bound(ordByL, ordByL + n, mp(segm[i][1] + 1, -1)) - ordByL;
		if (p < n) addEdge(2 * i + 1, 2 * n + p);
	}
}

void dfsOrd(int v) {
	used[v] = 1;
	for (int u : g[v])
		if (!used[u])
			dfsOrd(u);
	ord[ordSz++] = v;
}
void dfsCol(int v) {
	col[v] = C;
	for (int u : rg[v])
		if (col[u] == 0)
			dfsCol(u);
}
void dfsAns(int v) {
	used[v] = 1;
	ans[v / 2] = v & 1;
	for (int u : g[v])
		if (!used[u])
			dfsAns(u);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int v = 0; v < 4 * n; v++) {
		if (used[v]) continue;
		dfsOrd(v);
	}
	reverse(ord, ord + 4 * n);
	C = 1;
	for (int i = 0; i < 4 * n; i++) {
		int v = ord[i];
		if (col[v] != 0) continue;
		dfsCol(v);
		C++;
	}
	for (int i = 0; i < n; i++) {
		if (col[2 * i] == col[2 * i + 1]) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
		ans[i] = -1;
	for (int i = 0; i < 4 * n; i++)
		used[i] = 0;
	for (int i = 0; i < 2 * n; i++)
		ord2[i] = mp(-col[i], i);
	sort(ord2, ord2 + 2 * n);
	for (int i = 0; i < 2 * n; i++) {
		int v = ord2[i].second;
		if (ans[v / 2] != -1) continue;
		dfsAns(v);
	}
	int cnt = 0, F = 0;
	for (int i = 0; i < n; i++) {
		if (ans[i] == 0) continue;
		cnt++;
		F = max(F, segm[i][0]);
	}
	printf("%d %d\n", cnt, F);
	for (int i = 0; i < n; i++)
		if (ans[i])
			printf("%d ", i + 1);
	printf("\n");

	return 0;
}