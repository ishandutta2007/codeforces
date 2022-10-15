#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100007;
const int mod=1e9+7;

long long dp[maxn][15][20];
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
int main(){
	scanf("%d%d%d",&n,&m,&c);
	memset(dp,0,sizeof(dp));
	for (int i=0;i<=n;++i){
		dp[i][0][0]=1;
	}
	for (int i=1;i<=n;++i){
		for (int k=1;k<=m;++k){
			for (int r=0;r<(1<<c);++r){
				if (r&1){
					dp[i][k][r]=(dp[i-1][k-1][r>>1]*bitmask(r)+dp[i-1][k-1][(1<<(c-1))+(r>>1)]*(1+bitmask(r)))%mod;
				} 
				else{
					dp[i][k][r]=(dp[i-1][k][r>>1]+dp[i-1][k][(1<<(c-1))+(r>>1)])%mod;
				}
			}
		}
	}
	long long ans=0;
	for (int r=0;r<(1<<c);++r){
		ans=(ans+dp[n][m][r])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}