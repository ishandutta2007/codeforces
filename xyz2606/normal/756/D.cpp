#include<bits/stdc++.h>
using namespace std;
const int N(5011), A(26);
char a[N];
int c[N][N], dp[N][A], sum[N];
int modulo(1e9 + 7);
int main() {
	int n;
	cin >> n;
	for(int i(0); i <= n; i++) {
		for(int j(0); j <= i; j++) {
			c[i][j] = (i == 0 || j == 0) ? 1 : (c[i - 1][j - 1] + c[i - 1][j]) % modulo;
		}
	}
	sum[0] = 1;
	scanf("%s", a + 1);
	for(int i(1); i <= n; i++) {
		int c(a[i] - 'a');
		for(int j(i); j >= 1; j--) {
			int delta((0ll + sum[j - 1] - dp[j - 1][c] - dp[j][c] + 2 * modulo) % modulo);
			dp[j][c] = (dp[j][c] + delta) % modulo;
			//printf("dp[%d][%d] = %d\n", j, c, dp[j][c]);
			sum[j] = (sum[j] + delta) % modulo;
		}
//		dp[1][c] = (dp[1][c] + 1) % modulo;
//		sum[1] = (sum[1] + 1) % modulo;
	}
	int ans(0);
	for(int i(1); i <= n; i++) {
		ans = (ans + (long long)sum[i] * c[n - 1][i - 1]) % modulo;
	}
	cout << ans << endl;
}