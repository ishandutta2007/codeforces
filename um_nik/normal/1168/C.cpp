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
const int K = 19;
int n, q;
int a[N];
int b[N][K];
int c[N][K];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	a[n] = (1 << K) - 1;
	for (int j = 0; j < K; j++)
		b[n - 1][j] = n;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < K; j++) {
			b[i][j] = b[i + 1][j];
			if ((a[i + 1] >> j) & 1)
				b[i][j] = i + 1;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < K; j++)
			c[i][j] = n;
		for (int j = 0; j < K; j++) {
			if (((a[i] >> j) & 1) == 0) continue;
			c[i][j] = i;
			int p = b[i][j];
			if (p == n) continue;
			for (int h = 0; h < K; h++)
				c[i][h] = min(c[i][h], c[p][h]);
		}
	}
	while(q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;y--;
		bool ok = false;
		for (int i = 0; !ok && i < K; i++) {
			if (((a[y] >> i) & 1) == 0) continue;
			ok |= c[x][i] <= y;
		}
		if (ok)
			printf("Shi\n");
		else
			printf("Fou\n");
	}

	return 0;
}