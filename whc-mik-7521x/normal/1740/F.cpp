#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10,mod=998244353;
int n,ans,ct[N],suf[N],sum[N],lim[N],dp[N][N];
int main(){
    scanf("%d",&n);
	for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        ct[x]++;
    }
	sort(ct+1,ct+n+1);
	reverse(ct+1,ct+n+1);
	for(int i=n;i>=0;i--)sum[i]=sum[i+1]+ct[i],suf[i]=max(suf[i+1],ct[i]);
	for(int i=1,t=n;i<=n;i++){
		while(t&&suf[t]<i)t--;
		lim[i]=sum[t+1]+i*t;
	}
	dp[0][0]=1;
	for(int o=n;o;o--){
		for(int i=1;i*o<=n;i++){
            for(int k=o;k<=lim[i];k++){
                dp[i][k]=(dp[i][k]+dp[i-1][k-o])%mod;
            }
        }
	}
	for(int i=1;i<=n;i++)ans=(ans+dp[i][n])%mod;
    printf("%d",ans);
}