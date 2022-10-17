#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
const int MOD = 1e9 + 7;

const int N = 1010;
const int MX = 20010;
int dp[N][MX];

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

signed main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	int K = 10000;
	dp[0][K] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 2 * K; j++) {
			if (j - a[i] >= 0) {
				add(dp[i][j], dp[i - 1][j - a[i]]);
			}
			if (j + a[i] <= 2 * K) {
				add(dp[i][j], dp[i - 1][j + a[i]]);
			}
			if (abs(j - K) == a[i] && i > 1) {
				add(dp[i][j], 1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		//cout << dp[i][K] << '\n';
		add(ans, dp[i][K]);
	}
	cout << ans << '\n';
}