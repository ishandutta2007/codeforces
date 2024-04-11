#include <bits/stdc++.h>
using namespace std;

const int mxN=5000, mxA=1e5;
int n, a[mxN+1], dp[mxN+1][mxN+1], l1[mxA+2], l2[7], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<=n; ++i) {
		if(i)
			dp[i][i]=-n;
		for(int j=0; j<n; ++j)
			l1[a[j]-1]=l1[a[j]+1]=l2[a[j]%7]=dp[0][i];
		for(int j=0; j<i; ++j) {
			dp[i][j]=dp[j][i];
			if(j) {
				l1[a[j-1]]=max(dp[i][j], l1[a[j-1]]);
				l2[a[j-1]%7]=max(dp[i][j], l2[a[j-1]%7]);
			}
		}
		for(int j=i+1; j<=n; ++j) {
			dp[i][j]=max(max(l1[a[j-1]-1], l1[a[j-1]+1]), l2[a[j-1]%7])+1;
//			cout << i << " " << j << " " << dp[i][j] << endl;
			ans=max(dp[i][j], ans);
			l1[a[j-1]]=max(dp[i][j], l1[a[j-1]]);
			l2[a[j-1]%7]=max(dp[i][j], l2[a[j-1]%7]);
		}
	}
	cout << ans;
}