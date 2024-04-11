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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int K = 12;
const int N = 111;
int a[K][N][N];
int c, q;

void solve()
{
	int n;
	scanf("%d%d%d", &n, &q, &c);
	c++;
	while(n--) {
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		a[t][x][y]++;
	}
	for (int k = 0; k < c; k++) {
		for (int x = 1; x < N; x++)
			for (int y = 1; y < N; y++)
				a[k][x][y] += a[k][x - 1][y] + a[k][x][y - 1] - a[k][x - 1][y - 1];
	}
}

int query()
{
	int t, x, xx, y, yy;
	scanf("%d%d%d%d%d", &t, &x, &y, &xx, &yy);
	x--;y--;
	t %= c;
	int ans = 0;
	for (int k = 0; k < c; k++) {
		int cur = a[k][xx][yy] - a[k][xx][y] - a[k][x][yy] + a[k][x][y];
		ans += ((t + k) % c) * cur;
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	solve();
	while(q--)
		printf("%d\n", query());

	return 0;
}