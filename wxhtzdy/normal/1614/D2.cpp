#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
const int M=20000050;
int n,a[N],prime[M/2],cnt[M];
ll dp[M];
bool is[M];
int main(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),cnt[a[i]]++;
	for(int i=1;i<M;i++)is[i]=1;
	int pc=0;
	for(int i=2;i<M;i++){
		if(is[i])prime[++pc]=i;
		for(int j=1;j<=pc&&i*prime[j]<M;j++)is[i*prime[j]]=0;
	}
	for(int j=1;j<=pc;j++){
		for(int i=M/prime[j];i>=1;i--){
			cnt[i]+=cnt[i*prime[j]];
		}
	}
	for(int i=M-1;i>=1;i--){
		dp[i]=cnt[i]*1LL*i;
		for(int p=1;p<=pc&&i*prime[p]<M;p++){
			int j=i*prime[p];
			dp[i]=max(dp[i],dp[j]+i*1LL*(cnt[i]-cnt[j]));
		}
	}
	ll ans=0;
	for(int i=1;i<M;i++)ans=max(ans,dp[i]);
	printf("%lld",ans);
}