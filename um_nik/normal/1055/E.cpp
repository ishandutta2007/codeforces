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

const int N = 1505;
int n, m, k, s;
int a[N];
int b[N];
int d[N];
int xs[N];
int c[N][2];
int q;
int dp[2][N];
int maxAll[N];

void read() {
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		xs[i] = b[i];
	}
	sort(xs, xs + n);
	q = unique(xs, xs + n) - xs;
	while(m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		d[l] = max(d[l], r);
	}
	int curMax = 0;
	m = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] <= curMax) continue;
		curMax = d[i];
		c[m][0] = i;
		c[m][1] = d[i];
		m++;
	}
	k = min(k, m);
	int r = m;
	for (int i = m - 1; i >= 0; i--) {
		while(r > 0 && c[r - 1][0] >= c[i][1]) r--;
		d[i] = r;
	}
}

int solve(int X) {
	for (int i = 0; i <= n; i++)
		a[i] = 0;
	for (int i = 0; i < n; i++) {
		a[i + 1] = a[i];
		if (b[i] <= X)
			a[i + 1]++;
	}
	for (int i = 0; i < m; i++)
		dp[0][i] = 0;
	for(int it = 0; it < k; it++) {
		for (int i = 0; i <= m; i++)
			maxAll[i] = 0;
		for (int i = 0; i < m; i++)
			dp[1][i] = 0;
		int curMaxAll = 0;
		for (int i = 0; i < m; i++) {
			int p = d[i];
			curMaxAll = max(curMaxAll, maxAll[i]);
			dp[1][i] = max(dp[1][i], curMaxAll + a[c[i][1]] - a[c[i][0]]);
			dp[1][p - 1] = max(dp[1][p - 1], dp[0][i] + a[c[p - 1][1]] - a[c[i][1]]);
			maxAll[p] = max(maxAll[p], dp[0][i]);
		}
		for (int i = 0; i < m; i++)
			dp[0][i] = max(dp[0][i], dp[1][i]);
	}
	int res = 0;
	for (int i = 0; i < m; i++)
		res = max(res, dp[0][i]);
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	int l = -1, r = q;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (solve(xs[x]) >= s)
			r = x;
		else
			l = x;
	}
	if (r == q)
		printf("-1\n");
	else
		printf("%d\n", xs[r]);

	return 0;
}