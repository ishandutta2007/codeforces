#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,x,a[215],dp[215][215],ans=-1;
signed main(){
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)	cin>>a[i];
	memset(dp,128,sizeof(dp));
	for(int i=1;i<=k;i++)	dp[i][1]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=2;j<=x;j++){
			for(int l=i-1;l>=max(i-k,1ll);l--){
				dp[i][j]=max(dp[i][j],dp[l][j-1]+a[i]);
			}
		}
	}
	for(int i=n;i>=n-k+1;i--)	ans=max(ans,dp[i][x]);
	cout<<ans<<endl;
}