#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int N = 75;
const int INF = 1e9;

int a[N][N];
int dp[N][N][N][N];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;
	forn(i, n) forn(j, m) {
		cin >> a[i][j];
	}
	
	forn(i, N) forn(j, N) forn(cnt, N) forn(rem, N) dp[i][j][cnt][rem] = -INF;
	dp[0][0][0][0] = 0;
	forn(i, n) forn(j, m) forn(cnt, m / 2 + 1) forn(rem, k) {
		if (dp[i][j][cnt][rem] == -INF) continue;
		int ni = (j == m - 1 ? i + 1 : i);
		int nj = (j == m - 1 ? 0 : j + 1);
		if (i != ni) {
			dp[ni][nj][0][rem] = max(dp[ni][nj][0][rem], dp[i][j][cnt][rem]);
		} else {
			dp[ni][nj][cnt][rem] = max(dp[ni][nj][cnt][rem], dp[i][j][cnt][rem]);
		}
		if (cnt + 1 <= m / 2) {
			int nrem = (rem + a[i][j]) % k;
			if (i != ni) {
				dp[ni][nj][0][nrem] = max(dp[ni][nj][0][nrem], dp[i][j][cnt][rem] + a[i][j]);
			} else {
				dp[ni][nj][cnt + 1][nrem] = max(dp[ni][nj][cnt + 1][nrem], dp[i][j][cnt][rem] + a[i][j]);
			}
		}
	}
	
	cout << max(0, dp[n][0][0][0]) << endl;
	
	return 0;
}