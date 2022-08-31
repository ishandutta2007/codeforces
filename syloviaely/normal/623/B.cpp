#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,A[1100000],w1,w2,B[1100000];
long long dp[1100000][3];
const long long inf=1e18;
long long solve(int k){
	for (int i=1;i<=n;i++){
		int k1=A[i]%k;
		if (k1==0) B[i]=1; else if (k1==1||k1==k-1) B[i]=2; else B[i]=3;
	}
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
//	cout<<"solve "<<k<<endl;
//	for (int i=1;i<=n;i++) cout<<B[i]<<" "; cout<<endl;
	for (int i=1;i<=n;i++)
		if (B[i]==1){
			dp[i][0]=dp[i-1][0];
			dp[i][1]=min(dp[i-1][0],dp[i-1][1])+w1;
			dp[i][2]=min(dp[i-1][1],dp[i-1][2]);
		} else if (B[i]==2){
			dp[i][0]=dp[i-1][0]+w2;
			dp[i][1]=min(dp[i-1][0],dp[i-1][1])+w1;
			dp[i][2]=min(dp[i-1][1],dp[i-1][2])+w2;
		} else if (B[i]==3){
			dp[i][0]=inf;
			dp[i][1]=min(dp[i-1][0],dp[i-1][1])+w1;
			dp[i][2]=inf;
		}
	return min(min(dp[n][0],dp[n][1]),dp[n][2]);
}
long long solve(){
	int rem=A[1]; long long ans=1e18;
	for (int i=2;1ll*i*i<=rem;i++)
		if (rem%i==0){
			ans=min(ans,solve(i));
			while (rem%i==0) rem/=i;
		}
	if (rem>1) ans=min(ans,solve(rem));
	rem=A[1]+1; 
	for (int i=2;1ll*i*i<=rem;i++)
		if (rem%i==0){
			ans=min(ans,solve(i));
			while (rem%i==0) rem/=i;
		}
	if (rem>1) ans=min(ans,solve(rem));
	rem=A[1]-1; 
	for (int i=2;1ll*i*i<=rem;i++)
		if (rem%i==0){
			ans=min(ans,solve(i));
			while (rem%i==0) rem/=i;
		}
	if (rem>1) ans=min(ans,solve(rem));
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&w1,&w2);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	long long ans=1e18;
	ans=min(ans,solve());
	for (int i=1;i<=n;i++) if (i<=n-i+1) swap(A[i],A[n-i+1]);
	ans=min(ans,solve());
	cout<<ans<<endl; return 0;
}