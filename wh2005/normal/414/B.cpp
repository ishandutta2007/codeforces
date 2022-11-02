#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
bool f[2009];
int pri[2009],tot;
vector<int >p[2009];
void init(){
	memset(f,0,sizeof(f));tot=0;f[1]=1;
	for(int i=2;i<=2000;i++){
		p[i].push_back(1);p[i].push_back(i);
		if(!f[i]){pri[++tot]=i;} 
		for(int j=2;j*i<=2000;j++){
			p[j*i].push_back(i);
			f[j*i]=1;
		}
	}
	return ;
}
int n,k;
ll dp[2009][2009];

int main(){
	init();
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&k);
	ll ans=1;
	for(int i=1;i<=k;i++) dp[1][i]=1;
	for(int i=2;i<=n;i++){
		dp[i][1]=1;
		for(int j=2;j<=k;j++){
			dp[i][j]=0;
			for(int t=0;t<p[i].size();t++){
				dp[i][j]=(dp[i][j]+dp[p[i][t]][j-1])%mod;
			}
		}
		ans=(ans+dp[i][k])%mod;
	}
	printf("%lld\n",ans%mod);
	return 0;
}