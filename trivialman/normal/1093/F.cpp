#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int a[N],cnt[110],n,k,len;
LL dp[N][110],sdp[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d%d",&n,&k,&len);
	sdp[0] = 1;
	rep(i,1,n){
		scanf("%d",&a[i]);
		rep(j,1,k){
			if(a[i]==-1||a[i]==j){
				++cnt[j];
				dp[i][j] = sdp[i-1];
				if(cnt[j]>=len) dp[i][j] -= (sdp[i-len] - dp[i-len][j]);
				dp[i][j] = (dp[i][j] + MOD) %MOD;
				sdp[i] += dp[i][j];
			}else cnt[j] = 0;
		}
		sdp[i] %= MOD;
	}
	cout<<sdp[n]<<endl;
	return 0;
}