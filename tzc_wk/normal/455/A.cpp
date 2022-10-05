#include <bits/stdc++.h>
using namespace std;
long long n,a[100002],s[100002],dp[100002],mn=INT_MAX,mx=0,ans=0;
int main(){
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(long long i=0;i<n;i++){
		scanf("%d",a+i);
		s[a[i]]++;
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	for(long long i=mn;i<=mx;i++){
		if(i==1)	dp[i]=max(dp[i-1],s[i]);
		else	dp[i]=max(dp[i-1],dp[i-2]+i*s[i]);
	}
	for(long long i=0;i<=100000;i++){
		ans=max(ans,dp[i]);
	}
	printf("%I64d\n",ans);
}