#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=15, mxA=225, M=1e9+7;
int n, T, t[mxN], g[mxN], ans;
//mask, time, last genre
int dp[1<<mxN][mxA+1][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> T;
	for(int i=0; i<n; ++i) {
		cin >> t[i] >> g[i], --g[i];
	}
	dp[0][0][0]=1;
	for(int i=1; i<1<<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(i>>j&1^1)
				continue;
			int pi=i^1<<j;
			for(int k=0; k+t[j]<=T; ++k) {
				for(int l=0; l<3; ++l) {
					if(l==g[j]&&pi)
						continue;
					dp[i][k+t[j]][g[j]]=(dp[i][k+t[j]][g[j]]+dp[pi][k][l])%M;
				}
			}
		}
		for(int j=0; j<3; ++j)
			ans=(ans+dp[i][T][j])%M;
	}
	cout << ans;
}