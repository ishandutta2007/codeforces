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

const int A = 26;
const int N = 150100;
int n, q;
int deg[N];
char s[N];
int a[N][2][A];
int par[N];
pii realPar[N];
bool imp[N];
vector<int> g[N];
int h[N];
bool ALL_BAD = false;
int cntBad = 0;
int H;
int curV[N];
int sumForV[N];

void dfs(int v, pii rp) {
	realPar[v] = rp;
	if (imp[v]) {
		for (int i = 0; i < (int)g[v].size(); i++)
			dfs(g[v][i], mp(v, i));
	} else {
		for (int u : g[v])
			dfs(u, rp);
	}
}

bool badV(int v) {
	return h[v] + sumForV[v] > H;
}

void setForLet(int v, int c, int p, int val) {
	if (badV(v)) cntBad--;
	sumForV[v] -= max(a[v][0][c], a[v][1][c]);
	a[v][p][c] = val;
	sumForV[v] += max(a[v][0][c], a[v][1][c]);
	if (badV(v)) cntBad++;
}

void updUp(int v, int c, int dx) {
	if (v == 0) return;
	bool st = false;
	while(v != 0) {
		int u = realPar[v].first;
		int p = realPar[v].second;
		int old = max(a[u][0][c], a[u][1][c]);
		setForLet(u, c, p, a[u][p][c] + dx);
		if (old == max(a[u][0][c], a[u][1][c])) break;
		v = u;
	}
}

void printAns() {
	if (cntBad != 0) {
		printf("Fou\n");
		return;
	}
	int res = 0;
	for (int c = 0; c < A; c++) {
		res += (c + 1) * (H - sumForV[0] + max(a[0][0][c], a[0][1][c]));
	}
	printf("Shi %d\n", res);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	h[0] = 0;
	for (int i = 1; i < n; i++) {
		int v;
		char c;
		scanf("%d %c", &v, &c);
		v--;
		s[i] = c;
		par[i] = v;
		g[v].push_back(i);
		deg[v]++;
		h[i] = h[v] + 1;
	}
//	for (int i = 0; i < n; i++)
//		eprintf("%d ", h[i]);
//	eprintf("\n");
	H = -1;
	for (int i = 0; i < n; i++) {
		if (deg[i] != 0) continue;
		if (H == -1)
			H = h[i];
		if (H != h[i])
			ALL_BAD = true;
	}
	if (ALL_BAD) {
		while(q--) printf("Fou\n");
		return 0;
	}
//	eprintf("H = %d\n", H);
	for (int i = 0; i < n; i++)
		if (deg[i] == 2)
			imp[i] = 1;
	imp[0] = 1;
	dfs(0, mp(-1, -1));
	for (int i = 1; i < n; i++) {
		if (s[i] != '?')
			updUp(i, (int)(s[i] - 'a'), 1);
	}
	while(q--) {
		int v;
		char c;
		scanf("%d %c", &v, &c);
		v--;
		if (s[v] != '?')
			updUp(v, (int)(s[v] - 'a'), -1);
		s[v] = c;
		if (s[v] != '?')
			updUp(v, (int)(s[v] - 'a'), 1);
		printAns();
	}

	return 0;
}