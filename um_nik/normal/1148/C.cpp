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

const int N = 300300;
int a[N];
int b[N];
int ans[5 * N][2];
int ansSz;
int n;

void swap2(int x, int y) {
	int xx = a[x], yy = a[y];
	b[xx] = y;
	b[yy] = x;
	swap(a[x], a[y]);
	ans[ansSz][0] = x;
	ans[ansSz][1] = y;
	ansSz++;
}

void mySwap(int x, int y) {
	if (x > y) swap(x, y);
	if (abs(x - y) >= n / 2) {
		swap2(x, y);
		return;
	}
	if (y < n /2) {
		swap2(x, n - 1);
		swap2(y, n - 1);
		swap2(x, n - 1);
	} else if (x < n / 2) {
		swap2(x, n - 1);
		swap2(0, y);
		swap2(0, n - 1);
		swap2(0, y);
		swap2(x, n - 1);
	} else {
		swap2(0, x);
		swap2(0, y);
		swap2(0, x);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		b[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		/*
		for (int j = 0; j < n; j++)
			eprintf("%d ", a[j]);
		eprintf("\n");
		*/
		int p = b[i];
		if (p == i) continue;
		mySwap(i, p);
	}
	for (int i = 0; i < n; i++)
		if (a[i] != i) throw;
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);

	return 0;
}