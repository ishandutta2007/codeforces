#include<stdio.h>
int a[100001];
long long dp[31][100001];
int n, k;
int c[100001];
long long C = 0;
#define add(x) (C+=(c[(x)]++))
#define rem(x) (C-=(--c[(x)]))
void solve(int K, int s, int e, int l, int r) { // dp[K][s~e] from dp[K-1][l~r] , c : [l, s)
	if (s > e) return;

	int m = (s + e) / 2;
	int t = l, i;
	long long k;

	for (int i = s; i <= m; i++) add(a[i]);
	k = C + dp[K-1][l-1];
	// c : [l,m]
	for (i = l + 1; i <= r && i <= m; i++) {
		rem(a[i-1]);
		// c : [i,m]
		if (C+dp[K-1][i-1] < k) {
			k = C+dp[K-1][i-1];
			t = i;
		}
	}
	dp[K][m] = k;
	// c : [i-1 ~ m]
	for (i-=2; i >= t; i--) add(a[i]);
	// c : [t ~ m]
	solve(K, m + 1, e, t, r);
	for (int i = t - 1; i >= l; i--) add(a[i]); // c:[l, m]
	for (int i = m; i >= s; i--) rem(a[i]); // c:[l, s)
	solve(K, s, m - 1, l, t);
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)scanf("%d", a + i);
	//n = 100000;
	//k = 20;
	//for (int i = 1; i <= n; i++) a[i] = i;
	for (int i = 1; i <= n; i++) {
		add(a[i]);
		dp[1][i] = C;
	}
	for (int j = 1; j <= n; j++) c[j] = 0;
	C = 0;
	for (int i = 2; i <= k; i++) {
		solve(i, 1, n, 1, n);
	}
	printf("%lld\n", dp[k][n]);
	return 0;
}