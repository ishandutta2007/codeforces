#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
using namespace std;	

int n, a[5005], b[5005];
long long dp[5005][5005], pref[5005], suf[5005];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	rep(i, 1, n)
		cin >> a[i];
	rep(i, 1, n) 
		cin >> b[i];
	rep(i, 1, n)
		pref[i] = pref[i - 1] + 1ll * a[i] * b[i];
	per(i, 1, n)
		suf[i] = suf[i + 1] + 1ll * a[i] * b[i];
	rep(i, 1, n) dp[i][i] = 1ll * a[i] * b[i];
	rep(len, 2, n)
		rep(l, 1, n - len + 1) {
			int r = l + len - 1;
			dp[l][r] = dp[l + 1][r - 1] + 1ll * a[l] * b[r] + 1ll * a[r] * b[l];
		}
	long long ans = 0;
	rep(l, 1, n)
		rep(r, l, n)
			ans = max(ans, pref[l - 1] + suf[r + 1] + dp[l][r]);
	cout << ans << "\n";
	return 0;
}