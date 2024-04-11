#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1000, M=998244353;
int n, a[mxN];
ll dp[mxN+1][mxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	dp[0][0]=1;
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<n; ++j) {
			dp[i][j]=dp[i-1][j];
			if(j+1<n)
				dp[i][j]=(dp[i-1][j+1]+dp[i][j])%M;
		}
		if(a[i-1]>0&&a[i-1]<=n-i)
			dp[i][a[i-1]]=(dp[i-1][0]+dp[i][a[i-1]])%M;
	}
	cout << (dp[n][0]+M-1)%M;
}