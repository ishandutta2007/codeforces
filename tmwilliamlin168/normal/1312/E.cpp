#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=500;
int a[mxN], n;
int dp[mxN][mxN], dp2[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		dp[i][i]=a[i];
	}
	for(int i=n-2; ~i; --i) {
		for(int j=i+1; j<n; ++j) {
			dp[i][j]=-1;
			for(int k=i; k<j; ++k) {
				if(~dp[i][k]&&dp[i][k]==dp[k+1][j])
					dp[i][j]=dp[i][k]+1;
			}
		}
	}
	for(int i=1; i<=n; ++i) {
		dp2[i]=1e9;
		for(int j=0; j<i; ++j)
			if(~dp[j][i-1])
				dp2[i]=min(dp2[i], dp2[j]+1);
	}
	cout << dp2[n];
}