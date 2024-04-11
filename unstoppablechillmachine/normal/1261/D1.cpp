#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int MOD = 998244353;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

const int N = 2010;
int a[N], dp[N][2 * N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0][n] = 1;
	for (int i = 0; i < n; i++) {
		for (int balance = 1; balance < 2 * n; balance++) {
			int cur = i + 1, nxt = i + 2;
			if (nxt > n) {
				nxt = 1;
			}
			if (a[cur] == a[nxt]) {
				add(dp[i + 1][balance], mult(dp[i][balance], k));
			}
			else {
				add(dp[i + 1][balance - 1], dp[i][balance]);
				add(dp[i + 1][balance + 1], dp[i][balance]);
				add(dp[i + 1][balance], mult(dp[i][balance], k - 2));
			}
		}
	}
	int ans = 0;
	/*for (int i = 0; i <= 2 * n; i++) {
		cout << dp[n][i] << ' ';
	}
	cout << '\n'*/
	for (int balance = n + 1; balance <= 2 * n; balance++) {
		add(ans, dp[n][balance]);
	}		
	cout << ans << '\n';
}