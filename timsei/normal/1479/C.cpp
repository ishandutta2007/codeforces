// twojinzhi - bu - 1 de wenti
//  
// -1 
#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int dp[N], cnt, n, m, l, r;
int ans[N][N];


int main() {
	cin >> l >> r;
	int all = (r - l + 1);
	int it = 1, cnt = 1;
	for(cnt = 1; cnt <= 21; ++ cnt) {
		if((1 << (cnt - 1)) >= all) {
			break;
		}
	}
	
	n = cnt + 2;
	
	if(l == 1) {
		-- n;
	}
	
	memset(ans, -1, sizeof(ans));
	dp[n] = 1;
	for(int i = n - 1; i >= 2 - (l == 1); -- i) {
		if(i == n - 1) dp[i] = 1; else
		dp[i] = dp[i + 1] * 2;
		int beg = 1;
		if(dp[i] >= all) {
			-- all;
			ans[i][n] = 1;
			for(int j = i + 1; j < n; ++ j) {
				if(all >= dp[j]) {
					all -= dp[j];
					ans[i][j] = beg;
					beg += dp[j];
				}
			} break;
		} else {
			for(int j = n; j >= i + 1; -- j) {
				ans[i][j] = beg;
				beg += dp[j] - (j == n);
			}
		}
	}
	
	if(l != 1) {
		ans[1][2] = l - 1;
	}
	
	int tot = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) if(ans[i][j] != -1) ++ tot;
	}
	puts("YES");
	cout << n <<' ' << tot << endl;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) if(ans[i][j] != -1) {
			cout << i <<' ' << j <<' ' << ans[i][j] << endl;
		}
	}
	cout << endl;
}