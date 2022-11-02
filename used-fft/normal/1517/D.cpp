#include <bits/stdc++.h>
using namespace std;
#define int long long

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

const int INF = 1e18;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k; cin >> n >> m >> k;
	int right[n][m], down[n][m];
	for(int i=0; i<n; ++i){
		for(int j=0; j+1<m; ++j){
			cin >> right[i][j];
		}
	}
	for(int i=0; i+1<n; ++i){
		for(int j=0; j<m; ++j){
			cin >> down[i][j];
		}
	}
	if(k & 1){
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				cout << -1 << ' ';
			}
			cout << '\n';
		}
		return 0;
	}
	k/=2;

	int dp[n][m][k+1];
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			dp[i][j][0] = 0;
		}
	}
	for(int c=1; c<=k; ++c){
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				int r = INF;
				if(i){
					r = min(r, dp[i-1][j][c-1] + down[i-1][j]);
				}
				if(i+1<n){
					r = min(r, dp[i+1][j][c-1] + down[i][j]);
				}
				if(j){
					r = min(r, dp[i][j-1][c-1] + right[i][j-1]);
				}
				if(j+1<m){
					r = min(r, dp[i][j+1][c-1] + right[i][j]);
				}
				dp[i][j][c] = r;
			}
		}
	}

	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cout << 2LL*dp[i][j][k] << ' ';
		}
		cout << '\n';
	}
}