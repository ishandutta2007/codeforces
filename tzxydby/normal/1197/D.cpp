#include<bits/stdc++.h>
using namespace std;
 
const int maxn=300007;
 
typedef long long ll;
 
const int INF=1e9;
int n,m,k;
 
ll dp[maxn][17];
ll a[maxn];
 
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	if (m==1){
		dp[0][0]=0;
		for (int i=1;i<=n;++i){
			dp[i][0]=max(dp[i-1][0],0ll)+a[i]-k;
		}
		ll ans=0;
		for (int i=1;i<=n;++i){
			ans=max(dp[i][0],ans);
		}
		printf("%lld\n",ans);
		return 0;
	}
	dp[0][0]=0;
	for (int j=1;j<m;++j){
		dp[0][j]=-INF;
	}
	for (int i=1;i<=n;++i){
		for (int j=2;j<m;++j){
			dp[i][j]=dp[i-1][j-1]+a[i];
		}
		dp[i][1]=max(dp[i-1][0]+a[i]-k,a[i]-k);
		dp[i][0]=dp[i-1][m-1]+a[i];
	}
	ll ans=0;
	for (int i=1;i<=n;++i){
		for (int j=0;j<m;++j){
			ans=max(dp[i][j],ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
}