#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,a[315],b[315],t[315],last=0,cur=1,dp[2][150005],l,r,q[150005];
signed main(){
	scanf("%I64d%I64d%I64d",&n,&m,&d);
	for(int i=1;i<=m;i++)	scanf("%I64d%I64d%I64d",&a[i],&b[i],&t[i]);
	memset(dp,128,sizeof(dp));
	for(int i=1;i<=n;i++)	dp[0][i]=0;
	for(int i=1;i<=m;i++){
		memset(dp[cur],128,sizeof(dp[cur]));
		l=1,r=0;
		for(int j=1;j<=n;j++){
			while(l<=r&&q[l]<j-d*(t[i]-t[i-1]))		l++;
			while(l<=r&&dp[last][q[r]]<dp[last][j])	r--;
			q[++r]=j;
			dp[cur][j]=max(dp[cur][j],dp[last][q[l]]+b[i]-abs(a[i]-j));
		}
		l=1,r=0;
		for(int j=n;j>=1;j--){
			while(l<=r&&q[l]>j+d*(t[i]-t[i-1]))		l++;
			while(l<=r&&dp[last][q[r]]<dp[last][j])	r--;
			q[++r]=j;
			dp[cur][j]=max(dp[cur][j],dp[last][q[l]]+b[i]-abs(a[i]-j));
		}
		swap(last,cur);
	}
	int ans=-1e9;
	for(int i=1;i<=n;i++)	ans=max(ans,dp[last][i]);
	printf("%I64d\n",ans);
}