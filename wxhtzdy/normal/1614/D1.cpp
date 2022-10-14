#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
const int M=5000050;
int n,a[N],cnt[M];
ll dp[M];
int main(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),cnt[a[i]]++;
	for(int i=1;i<M;i++)for(int j=i+i;j<M;j+=i)cnt[i]+=cnt[j];
	for(int i=M-1;i>=1;i--){
		dp[i]=cnt[i]*1LL*i;
		for(int j=i+i;j<M;j+=i){
			dp[i]=max(dp[i],dp[j]+i*1LL*(cnt[i]-cnt[j]));
		}
	}
	ll ans=0;
	for(int i=1;i<M;i++)ans=max(ans,dp[i]);
	printf("%lld",ans);
}