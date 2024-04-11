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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int TAND = 0;
const int TOR = 1;
const int TXOR = 2;
const int TNOT = 3;
const int TIN = 4;

const int N = (int)1e6 + 7;

char s[10];
int tp[N];
int g[N][2];
int a[N];
int ans[N];
int n, m;
int leafId[N];

void dfsVal(int v) {
	if (tp[v] == TIN) return;
	if (tp[v] == TNOT) {
		dfsVal(g[v][0]);
		a[v] = a[g[v][0]] ^ 1;
		return;
	}
	dfsVal(g[v][0]);
	dfsVal(g[v][1]);
	if (tp[v] == TAND)
		a[v] = a[g[v][0]] & a[g[v][1]];
	if (tp[v] == TOR)
		a[v] = a[g[v][0]] | a[g[v][1]];
	if (tp[v] == TXOR)
		a[v] = a[g[v][0]] ^ a[g[v][1]];
}

void dfsAns(int v, int val0, int val1) {
	if (tp[v] == TIN) {
		if (a[v] == 0)
			ans[leafId[v]] = val1;
		else
			ans[leafId[v]] = val0;
		return;
	}
	if (tp[v] == TNOT) {
		dfsAns(g[v][0], val1, val0);
		return;
	}
	int u = g[v][0], w = g[v][1];
	if (tp[v] == TAND) {
		if (a[w] == 0) {
			dfsAns(u, val0, val0);
		} else {
			dfsAns(u, val0, val1);
		}
		swap(u, w);
		if (a[w] == 0) {
			dfsAns(u, val0, val0);
		} else {
			dfsAns(u, val0, val1);
		}
		return;
	}
	if (tp[v] == TOR) {
		if (a[w] == 0) {
			dfsAns(u, val0, val1);
		} else {
			dfsAns(u, val1, val1);
		}
		swap(u, w);
		if (a[w] == 0) {
			dfsAns(u, val0, val1);
		} else {
			dfsAns(u, val1, val1);
		}
		return;
	}
	if (tp[v] == TXOR) {
		if (a[w] == 0) {
			dfsAns(u, val0, val1);
		} else {
			dfsAns(u, val1, val0);
		}
		swap(u, w);
		if (a[w] == 0) {
			dfsAns(u, val0, val1);
		} else {
			dfsAns(u, val1, val0);
		}
		return;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int v = 0; v < n; v++) {
		scanf("%s", s);
		if (s[0] == 'A')
			tp[v] = TAND;
		else if (s[0] == 'O')
			tp[v] = TOR;
		else if (s[0] == 'X')
			tp[v] = TXOR;
		else if (s[0] == 'N')
			tp[v] = TNOT;
		else if (s[0] == 'I')
			tp[v] = TIN;
		else
			throw;
		if (tp[v] == TIN) {
			scanf("%d", &a[v]);
			leafId[v] = m++;
			continue;
		}
		leafId[v] = -1;
		int sz = 2;
		if (tp[v] == TNOT) 
			sz = 1;
		for (int i = 0; i < sz; i++) {
			scanf("%d", &g[v][i]);
			g[v][i]--;
		}
	}
	dfsVal(0);
	dfsAns(0, 0, 1);
	for (int i = 0; i < m; i++)
		printf("%d", ans[i]);

	return 0;
}