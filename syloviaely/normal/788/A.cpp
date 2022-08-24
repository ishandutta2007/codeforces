#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long x[110000],dp[110000][2];
int n,a[110000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		if (i&1) x[i]=x[i-1]+abs(a[i]-a[i+1]);
		else x[i]=x[i-1]-abs(a[i]-a[i+1]);
	}
	long long mi0=0,ma0=0,mi1=1e18,ma1=-1e18;
	long long ans=-1e18;
	dp[0][0]=0; dp[0][1]=-1e18;
	for (int i=1;i<n;i++){
		dp[i][1]=max(0ll,dp[i-1][0])+abs(a[i]-a[i+1]);
		dp[i][0]=dp[i-1][1]-abs(a[i]-a[i+1]);
		ans=max(ans,max(dp[i][0],dp[i][1]));
	}
	cout<<ans<<endl;
}