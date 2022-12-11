#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;

int r,n,t[N],x[N],y[N],dp[N];
int main(){
	scanf("%d%d",&r,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
	}
	memset(dp,-127,sizeof dp);
	t[0]=0,x[0]=1,y[0]=1;
	dp[0]=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int o=i-1;o>=0&&i-o<=4*r;o--){
			if(t[i]-t[o]>=abs(x[i]-x[o])+abs(y[i]-y[o]))dp[i]=max(dp[i],dp[o]+1);
		}
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}