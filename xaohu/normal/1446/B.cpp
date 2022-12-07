#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

int n, m, dp[5005][5005], ans;
char s[5005], t[5005];
 
int main() {
	cin >> n >> m >> s + 1 >> t + 1;
	rep(i, 1, n)
		rep(j, 1, m) {
			if (s[i] == t[j])
				dp[i][j] = 2 + dp[i - 1][j - 1];
			else 
				dp[i][j] = max(0, -1 + max(dp[i - 1][j], dp[i][j - 1]));
			ans = max(ans, dp[i][j]);
		}
	cout << ans << endl;
	return 0;
}