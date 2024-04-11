using namespace std;

#include <iostream>

#define MAXN 1005

// if N is odd, always best to take 0
// if N is even, always take 1

int N,M,a[MAXN][MAXN],dp[MAXN][MAXN][2];

void solve() {
	cin >> N >> M;
	for(int i = 0;i < N;++i) {
		for(int j = 0;j < M;++j) {
			cin >> a[i][j];
			dp[i][j][0] = 1e9;
			dp[i][j][1] = -1e9;
			if(i) {
				dp[i][j][0] = min(dp[i][j][0],dp[i - 1][j][0]);
				dp[i][j][1] = max(dp[i][j][1],dp[i - 1][j][1]);
			}
			if(j) {
				dp[i][j][0] = min(dp[i][j][0],dp[i][j - 1][0]);
				dp[i][j][1] = max(dp[i][j][1],dp[i][j - 1][1]);
			}
			if(dp[i][j][0] >= 1e9 || dp[i][j][1] <= -1e9) {
				dp[i][j][0] = dp[i][j][1] = 0;
			} 
			dp[i][j][0] += a[i][j];
			dp[i][j][1] += a[i][j];
		}
	}
	// cout << dp[N - 1][M - 1][0] << " " << dp[N - 1][M - 1][1] << endl;
	if((N + M) & 1) {
		if(dp[N - 1][M - 1][0] <= 0 && dp[N - 1][M - 1][1] >= 0) {
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}else{
		cout << "NO" << endl;
	}
	
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}