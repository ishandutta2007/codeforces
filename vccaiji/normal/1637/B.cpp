#include<bits/stdc++.h>
using namespace std;
int a[110];
int dp[110][110];
bool in[1000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		long long ans=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n-k+1;i++){
				for(int ii=0;ii<=110;ii++) in[ii]=false;
				for(int ii=i;ii<=i+k-1;ii++){
					if(a[ii]<=110) in[a[ii]]=true;
				}
				for(int ii=0;;ii++){
					if(!in[ii]){
						dp[i][i+k-1]=1+ii;
						break;
					}
				}
				for(int ii=i;ii<=i+k-2;ii++) dp[i][i+k-1]=max(dp[i][i+k-1],dp[i][ii]+dp[ii+1][i+k-1]);
				ans+=dp[i][i+k-1];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}