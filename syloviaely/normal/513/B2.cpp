#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,ans[60];
long long k,dp[60];
void find(int k1,int k2,long long k3,int k4){
	if (k1==k2){
		ans[k1]=k4; return;
	}
	if (dp[k2-k1]>=k3){
		ans[k1]=k4; find(k1+1,k2,k3,k4+1);
	} else {
		ans[k2]=k4; find(k1,k2-1,k3-dp[k2-k1],k4+1);
	}
}
int main(){
	scanf("%d%I64d",&n,&k);
	dp[1]=1;
	for (int i=2;i<=n;i++) dp[i]=dp[i-1]*2;
	find(1,n,k,1);
	for (int i=1;i<=n;i++) cout<<ans[i]<<" "; cout<<endl;
	return 0;
}