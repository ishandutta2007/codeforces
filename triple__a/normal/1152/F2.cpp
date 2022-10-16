#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100007;
const int mod=1e9+7;

long long dp[300][300];
long long ans[300][300];
int n,m,c;

int bitmask(int r){
	int ans=0;
	while(r){
		if (r&1){
			ans++;
		}
		r>>=1;
	}
	return ans;
}

void solve(){
	int t=n;
	for (int i=0;i<(m+1)*(1<<c);++i){
		ans[i][i]=1;
	}
	while (t){
		if (t&1){
			long long tmp[300][300];
			memset(tmp,0,sizeof(tmp));
			for (int i=0;i<(m+1)*(1<<c);++i){
				for (int j=0;j<(m+1)*(1<<c);++j){
					for (int k=0;k<(m+1)*(1<<c);++k){
						tmp[i][j]=(tmp[i][j]+ans[i][k]*dp[k][j])%mod;
					}
				}
			}
			for (int i=0;i<(m+1)*(1<<c);++i){
				for (int j=0;j<(m+1)*(1<<c);++j){
					ans[i][j]=tmp[i][j];
				}
			}	
		}
		long long tmp[300][300];
		memset(tmp,0,sizeof(tmp));
		for (int i=0;i<(m+1)*(1<<c);++i){
			for (int j=0;j<(m+1)*(1<<c);++j){
				for (int k=0;k<(m+1)*(1<<c);++k){
					tmp[i][j]=(tmp[i][j]+dp[i][k]*dp[k][j])%mod;
				}
			}
		}
		for (int i=0;i<(m+1)*(1<<c);++i){
			for (int j=0;j<(m+1)*(1<<c);++j){
				dp[i][j]=tmp[i][j];
			}
		}
		t>>=1;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&c);
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i=(1<<c);i<(m+1)*(1<<c);++i){
		int r=i%(1<<c),k=i/(1<<c);
		if (r&1&&k>0){
			dp[i][(k-1)*(1<<c)+(r>>1)]=bitmask(r);
			dp[i][(k-1)*(1<<c)+(1<<(c-1))+(r>>1)]=bitmask(r)+1;
		}
		else{
			dp[i][k*(1<<c)+(r>>1)]=dp[i][k*(1<<c)+(r>>1)+(1<<(c-1))]=1;
		}
	}
	solve();
	long long ret=0;
	for (int i=m*(1<<c);i<(m+1)*(1<<c);++i){
		ret=(ret+ans[i][0])%mod;
	}
	printf("%lld\n",ret);
	return 0;
}