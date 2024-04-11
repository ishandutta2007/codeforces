#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1005][1005],ans=0,dp1[1005][1005],dp2[1005][1005],dp3[1005][1005],dp4[1005][1005];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)	for(int j=1;j<=m;j++)	cin>>a[i][j];
	for(int i=1;i<=n;i++)	for(int j=1;j<=m;j++)	dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+a[i][j];
	for(int i=1;i<=n;i++)	for(int j=m;j>=1;j--)	dp2[i][j]=max(dp2[i-1][j],dp2[i][j+1])+a[i][j];
	for(int i=n;i>=1;i--)	for(int j=1;j<=m;j++)	dp3[i][j]=max(dp3[i+1][j],dp3[i][j-1])+a[i][j];
	for(int i=n;i>=1;i--)	for(int j=m;j>=1;j--)	dp4[i][j]=max(dp4[i+1][j],dp4[i][j+1])+a[i][j];
	for(int i=2;i<n;i++)	for(int j=2;j<m;j++)	ans=max(ans,dp1[i][j-1]+dp2[i-1][j]+dp3[i+1][j]+dp4[i][j+1]),ans=max(ans,dp1[i-1][j]+dp2[i][j+1]+dp3[i][j-1]+dp4[i+1][j]);
	cout<<ans<<endl;
	return 0;
}