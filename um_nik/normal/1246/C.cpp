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

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}

const int N = 2020;
char s[N][N];
int n, m;
int a[N][N], b[N][N];
int dp1[N][N], dp2[N][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	if (n == 1 && m == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		a[i][m - 1] = 0;
		for (int j = m - 1; j > 0; j--)
			a[i][j - 1] = a[i][j] + (int)(s[i][j] == 'R');
	}
	for (int j = 0; j < m; j++) {
		b[n - 1][j] = 0;
		for (int i = n - 1; i > 0; i--)
			b[i - 1][j] = b[i][j] + (int)(s[i][j] == 'R');
	}
	dp1[0][0] = dp2[0][0] = 1;
	dp1[0][1] = sub(0, 1);
	dp2[1][0] = sub(0, 1);
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			if (y > 0) dp1[x][y] = add(dp1[x][y], dp1[x][y - 1]);
			if (x > 0) dp2[x][y] = add(dp2[x][y], dp2[x - 1][y]);
			int lst;
			lst = n - b[x][y];
			dp2[x + 1][y] = add(dp2[x + 1][y], dp1[x][y]);
			dp2[lst][y] = sub(dp2[lst][y], dp1[x][y]);
			lst = m - a[x][y];
			dp1[x][y + 1] = add(dp1[x][y + 1], dp2[x][y]);
			dp1[x][lst] = sub(dp1[x][lst], dp2[x][y]);
		}
	printf("%d\n", add(dp1[n - 1][m - 1], dp2[n - 1][m - 1]));

	return 0;
}