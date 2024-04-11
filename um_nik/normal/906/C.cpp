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

const int N = 23;
int n;
int a[N][N];
int ans[N];
int ansSz;
int cur[N];
int curSz;

void brute(int p) {
	if (curSz >= ansSz) return;
	if (p == n) {
		bool ok = true;
		for (int i = 0; i < n; i++)
			ok &= (a[p][i] == (1 << n) - 1);
		if (!ok) return;
		ansSz = curSz;
		for (int i = 0; i < ansSz; i++)
			ans[i] = cur[i];
		return;
	}
	for (int i = 0; i < n; i++) {
		a[p + 1][i] = a[p][i];
	}
	brute(p + 1);
	for (int i = 0; i < n; i++) {
		if (((a[p][p] >> i) & 1) == 0) continue;
		a[p + 1][i] |= a[p + 1][p];
	}
	cur[curSz++] = p;
	brute(p + 1);
	curSz--;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		a[0][v] |= 1 << u;
		a[0][u] |= 1 << v;
	}
	for (int v = 0; v < n; v++)
		a[0][v] |= 1 << v;
	ansSz = n + 1;
	brute(0);
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");

	return 0;
}