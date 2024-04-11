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

const int N = 101;
int n;
int a[N][N];

int query(int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
	fflush(stdout);
	scanf("%d", &x1);
	return x1;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	a[0][0] = 1;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++) {
			if (x == 0 && y == 0) continue;
			if (x == n - 1 && y == n - 1) continue;
			if (((x + y) & 1) && (x == 0)) continue;
			if (x == 1 && y == 0) continue;
			int x1, y1;
			if (y >= 2) {
				x1 = x;
				y1 = y - 2;
			} else if (x >= 1 && y >= 1) {
				x1 = x - 1;
				y1 = y - 1;
			} else if (x >= 2) {
				x1 = x - 2;
				y1 = y;
			} else throw;
			a[x][y] = 1 ^ a[x1][y1] ^ query(x1, y1, x, y);
		}
	for (int y = 1; y < n; y += 2)
		a[0][y] = 1 ^ a[2][y] ^ query(0, y, 2, y);
	int p = 0;
	while(a[p + 2][p + 2] == a[p][p]) p++;
	if ((a[p][p + 1] ^ a[p + 2][p + 2]) == (a[p + 1][p + 1] ^ a[p + 2][p + 1])) {
		int t = query(p, p + 1, p + 2, p + 2);
		if (1 ^ t ^ a[p][p + 1] ^ a[p + 2][p + 2]) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if ((i + j) & 1)
						a[i][j] ^= 1;
		}
	} else {
		int t = query(p, p, p + 2, p + 1);
		if (1 ^ t ^ a[p][p] ^ a[p + 2][p + 1]) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if ((i + j) & 1)
						a[i][j] ^= 1;
		}
	}
	printf("!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d", a[i][j]);
		printf("\n");
	}
	fflush(stdout);

	return 0;
}