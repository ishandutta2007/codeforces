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

const int LOG = 19;
const int N = 400400;
int p2[N];
pii sparse[LOG][N];
int n;
int a[N];
int st;

pii getMin(int l, int r) {
	int k = p2[r - l];
	return min(sparse[k][l], sparse[k][r - (1 << k)]);
}

int getH(int l, int r) {
	if (l >= r) return 0;
	pii t = getMin(l, r);
	return max(getH(l, t.second), getH(t.second + 1, r)) + 1;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1)
			st = i;
	}
	rotate(a, a + st, a + n);
	for (int i = 0; i < 2 * n; i++)
		sparse[0][i] = mp(a[i % n], i);
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 0; i + (1 << (k + 1)) <= 2 * n; i++)
			sparse[k + 1][i] = min(sparse[k][i], sparse[k][i + (1 << k)]);
	int l = 0, r = n;
	while(r - l > 1) {
		int m = (l + r) / 2;
		int h1 = getH(n - m, n), h2 = getH(n + 1, 2 * n - m);
		if (h1 < h2)
			l = m;
		else
			r = m;
	}
	int hl = getH(n - l, 2 * n - l), hr = getH(n - r, 2 * n - r);
	if (hr < hl) {
		l = r;
		hl = hr;
	}
	st -= l;
	if (st < 0) st += n;
	printf("%d %d\n", hl, st);

	return 0;
}