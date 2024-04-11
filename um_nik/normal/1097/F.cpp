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

const int N = (int)1e5 + 5;
const int B = 20;
const int M = 7001;
const int S = M / B + 1;
int ppc[(1 << B) + 7];
int a[N][S];
int b[M][S], c[M][S];
int mu[M];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 1; i < (1 << B); i++)
		ppc[i] = ppc[i / 2] + (i & 1);

	mu[1] = 1;
	for (int i = 1; i < M; i++)
		for (int j = 2 * i; j < M; j += i)
			mu[j] ^= mu[i];

	for (int x = 1; x < M; x++)
		for (int y = x; y < M; y += x) {
			b[y][x / B] ^= 1 << (x % B);
			if (mu[y / x])
				c[x][y / B] ^= 1 << (y % B);
		}
	int n, q;
	scanf("%d%d", &n, &q);
	while(q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int p, x;
			scanf("%d%d", &p, &x);
			p--;
			for (int i = 0; i < S; i++)
				a[p][i] = b[x][i];
		} else if (t == 2) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			x--;y--;z--;
			for (int i = 0; i < S; i++)
				a[x][i] = a[y][i] ^ a[z][i];
		} else if (t == 3) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			x--;y--;z--;
			for (int i = 0; i < S; i++)
				a[x][i] = a[y][i] & a[z][i];
		} else {
			int p, x;
			scanf("%d%d", &p, &x);
			p--;
			int ans = 0;
			for (int i = 0; i < S; i++)
				ans += ppc[a[p][i] & c[x][i]];
			printf("%d", ans & 1);
		}
//		for (int i = 0; i < n; i++)
//			eprintf(" %d ", a[i][0]);
	}
	printf("\n");

	return 0;
}