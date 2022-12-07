#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const int N = 3e5 + 5;
const ll INF = 1e18;
const int T = 1 << 19;

int t, n, q, a[N];
ll dp[T + T][2][2];

void combine(int v) {
	if (dp[2 * v][0][0] == INF) {
		for (int j = 0; j < 2; ++j)
			for (int g = 0; g < 2; ++g)
				dp[v][j][g] = dp[2 * v + 1][j][g];
		return;
	}
	if (dp[2 * v + 1][0][0] == INF) {
		for (int j = 0; j < 2; ++j)
			for (int g = 0; g < 2; ++g)
				dp[v][j][g] = dp[2 * v][j][g];
		return;
	}
	int l = 2 * v, r = 2 * v + 1;
	dp[v][0][0] = min(dp[l][0][0] + dp[r][0][0], dp[l][1][0] - dp[r][1][1]);
	dp[v][0][1] = max(dp[l][0][1] + dp[r][0][1], dp[l][1][1] - dp[r][1][0]);
	dp[v][1][0] = min(dp[l][0][0] + dp[r][1][0], dp[l][1][0] - dp[r][0][1]);
	dp[v][1][1] = max(dp[l][0][1] + dp[r][1][1], dp[l][1][1] - dp[r][0][0]);
}

void change(int v, int x) {
	v += T;
	dp[v][0][0] = dp[v][0][1] = 0;
	dp[v][1][0] = dp[v][1][1] = x;
	v /= 2;
	while (v) {
		combine(v);
		v /= 2;
	}
}

void ans() {
	printf ("%lld\n", max(dp[1][0][1], dp[1][1][1]));
}

int main() {
	scanf ("%d", &t);
	for (int i = T; i < T + T; ++i)
		dp[i][0][0] = INF;
	for (int i = T - 1; i; i--)
		combine(i);
	while (t--) {
		scanf ("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i) { 
			scanf ("%d", a + i);
			change(i, a[i]);
		}
		//int v = (T + 2);
		//cout << dp[v][1][1] << endl;
		ans();
		while (q--) {
			int l, r;
			scanf ("%d%d", &l, &r);
			swap(a[l], a[r]);
			change(l, a[l]);
			change(r, a[r]);
			ans();
		}
		for (int i = 1; i <= n; ++i) {
			int v = i + T;
			dp[v][0][0] = INF;
			v /= 2;
			while (v) {
				combine(v);
				v /= 2;
			}
		}
	}
	
}