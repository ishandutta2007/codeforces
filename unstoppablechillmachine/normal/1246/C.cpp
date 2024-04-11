#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
 
const int MOD = 1e9 + 7;

int sum(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

const int N = 2010;
int dp[N][N][2], pref0[N][N], pref1[N][N], calc1[N][N], calc0[N][N];
char c[N][N];

int get_sum1(int a, int l, int r) {
	if (l > r) {
		return 0;
	}
	int res = pref1[a][r] - pref1[a][l - 1];
	if (res < 0) {
		res += MOD;
	}
	return res;
}

int get_sum0(int a, int l, int r) {
	if (l > r) {
		return 0;
	}
	int res = pref0[a][r] - pref0[a][l - 1];
	if (res < 0) {
		res += MOD;
	}
	return res;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 	int n, m;
 	cin >> n >> m;
 	if (n == 1 && m == 1) {
 		cout << 1 << '\n';
 		exit(0);
 	}
 	int cnt0 = 0, cnt1 = 0;
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m; j++) {
 			cin >> c[i][j];
 			if (c[i][j] == 'R') {
 				if (i == 1) {
 					cnt1++;
 				}
 				if (j == 1) {
 					cnt0++;
 				}
 			}
 		}
 	}
 	for (int j = 1; j <= m; j++) {
 		int cnt = 0;
 		for (int i = n; i >= 1; i--) {
 			if (c[i][j] == 'R') {
 				cnt++;
 				calc1[j][cnt] = i;
 			}
 		}
 		for (int i = cnt + 1; i <= n; i++) {
 			calc1[j][i] = 1;
 		}
 	}
 	for (int i = 1; i <= n; i++) {
 		int cnt = 0;
 		for (int j = m; j >= 1; j--) {
 			if (c[i][j] == 'R') {
 				cnt++;
 				calc0[i][cnt] = j;
 			}
 		}
 		for (int j = cnt + 1; j <= m; j++) {
 			calc0[i][j] = 1;
 		}
 	}
 	for (int j = 2; j <= m; j++) {
 		if (cnt1 <= m - j) {
 			dp[1][j][1] = 1;
 			pref1[j][1] = 1;
 		}
 	}
 	for (int i = 2; i <= n; i++) {
 		if (cnt0 <= n - i) {
 			dp[i][1][0] = 1;
 			pref0[i][1] = 1;
 		}
 	}
 	for (int i = 2; i <= n; i++) {
 		for (int j = 2; j <= m; j++) {
 			int up = calc1[j][n - i + 1], lef = calc0[i][m - j + 1];
 			dp[i][j][0] = get_sum1(j, up, i - 1);
 			dp[i][j][1] = get_sum0(i, lef, j - 1);
 			pref1[j][i] = sum(pref1[j][i - 1], dp[i][j][1]);
 			pref0[i][j] = sum(pref0[i][j - 1], dp[i][j][0]);
 		}
 	}
 	cout << sum(dp[n][m][0], dp[n][m][1]) << '\n';
}