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

const int N = 200200;
const int LOG = 18;
int a[N];
int p[N];
int nxt[N];
int b[N][LOG];
int sparse[LOG][N];
int p2[N];
int n, m, q;

int getMin(int l, int r) {
	int k = p2[r - l];
	return min(sparse[k][l], sparse[k][r - (1 << k)]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &m, &n, &q);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		p[x] = i;
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[i] = p[x];
	}
	/*
	for (int i = 0; i < n; i++)
		eprintf("%d ", a[i]);
	eprintf("\n");
	*/
	for (int i = 0; i < m; i++)
		nxt[i] = n;
	for (int i = 0; i <= n; i++)
		for (int k = 0; k < LOG; k++)
			b[i][k] = n;
	for (int i = n - 1; i >= 0; i--) {
		int x = a[i];
		int y = x + 1;
		if (y == m) y = 0;
		b[i][0] = nxt[y];
		nxt[x] = i;
	}
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 0; i < n; i++) {
			int w = b[i][k];
			b[i][k + 1] = b[w][k];
		}
	for (int i = 0; i < n; i++) {
		int x = i;
		for (int k = 0; k < LOG; k++)
			if (((m - 1) >> k) & 1)
				x = b[x][k];
		sparse[0][i] = x;
	}
	/*
	for (int i = 0; i < n; i++)
		eprintf("%d ", sparse[0][i]);
	eprintf("\n");
	*/
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 0; i + (1 << (k + 1)) <= n; i++)
			sparse[k + 1][i] = min(sparse[k][i], sparse[k][i + (1 << k)]);

	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;

	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		if (getMin(l, r) < r)
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	return 0;
}