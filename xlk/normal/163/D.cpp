#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;
ll sq, V, b, pw[100][100], z, za, zb;
int n, q[100];
ii p[100];
void dfs(int d, ll c) {
	if (c > sq)
		return;
	if (!d) {
		b = max(c, b);
		return;
	}
	for (int i = q[d]; i >= 0; i--)
		dfs(d - 1, c * pw[d][i]);
}

void sol(int d, ll a) {
	if ((double) a * a * a > V)
		return;
	if (!d) {
		ll x = V / a;
		sq = int(sqrt(x) + 0.5);
		if (2 * sq * a + x < z) {
			b = 1;
			dfs(n, 1);
			if ((b + x / b) * a + x < z) {
				z = (b + x / b) * a + x;
				za = a;
				zb = b;
			}
		}
		return;
	}
	for (int i = p[d].Y; i >= 0; i--) {
		q[d] = p[d].Y - i;
		sol(d - 1, a * pw[d][i]);
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int _ = 0; _ < t; _++) {
		scanf("%d", &n);
		V = 1;
		z = 6000000000000000000LL;
		for (int i = 1; i <= n; i++) {
			scanf("%I64d%d", &p[i].X, &p[i].Y);
		}
		sort(p + 1, p + n + 1);
		for (int i = 1; i <= n; i++) {
			pw[i][0] = 1;
			for (int j = 1; j <= p[i].Y; j++) {
				V *= p[i].X;
				pw[i][j] = pw[i][j - 1] * p[i].X;
			}
		}
		sol(n, 1);
		printf("%I64d %I64d %I64d %I64d\n", z * 2, za, zb, V / za / zb);
	}
	return 0;
}