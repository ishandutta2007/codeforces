#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

const int N = 1 << 20;

int t, n, dp[N];
int a[] = {
	11,
	111,
	1111,
	11111,
	111111,
	1111111};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	dp[0] = 1;
	rep(i, 1, N - 1) 
		rep(j, 0, 5)
			if (a[j] <= i)
				dp[i] |= dp[i - a[j]];
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (n >= N || dp[n] ? "YES\n" : "NO\n");
	}
	return 0;
}