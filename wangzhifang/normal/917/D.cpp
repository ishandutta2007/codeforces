#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
constexpr int mod=1000000007;
constexpr int max_n=8000;
vector<int>g[max_n+1],dp[max_n+1][2];
int fac[max_n+1],ifac[max_n+1];
int siz[max_n+1],ans[max_n+1],ans1[max_n+1];
void mod1(int&x){
	x>=mod&&(x-=mod);
}
ll quickpow(ll x,int k){
	ll ret=1;
	for(; k; x=x*x%mod,k>>=1)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
void dfs0(const int&u,const int&p=0){
	siz[u]=1;
	for(int v:g[u])
		if(v!=p){
			dfs0(v,u);
			siz[u]+=siz[v];
		}
}
int tmp[2][max_n+1];
void dfs(const int&u,const int&p=0){
	int sz=0;
	dp[u][0][0]=dp[u][1][0]=1;
	for(int v:g[u])
		if(v!=p){
			dfs(v,u);
			const int&szv=siz[v];
			memset(tmp[0],0,(sz+szv+1)<<2);
			memset(tmp[1],0,(sz+szv+1)<<2);
			for(int x=0; x<=sz; ++x)
				for(int y=0; y<=szv; ++y){
					int&t0=tmp[0][x+y],&t1=tmp[1][x+y];
					const int&tx=dp[u][0][x],ty=dp[v][0][y];
					t0=(t0+ll(tx)*ty)%mod;
					t1=(t1+ll(tx)*dp[v][1][y]+ll(ty)*dp[u][1][x])%mod;
				}
			sz+=szv;
			memcpy(dp[u][0].data(),tmp[0],(sz+1)<<2);
			memcpy(dp[u][1].data(),tmp[1],(sz+1)<<2);
		}
	++sz;
	for(int i=sz; i; --i)
		mod1(dp[u][0][i]+=dp[u][1][i-1]);
}
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("1");
		return 0;
	}
	ll now=*fac=1;
	for(int i=1; i<=n; ++i)
		fac[i]=now=now*i%mod;
	ifac[n]=now=quickpow(fac[n],mod-2);
	for(int i=n; i; ifac[--i]=now)
		now=now*i%mod;
	for(int u,v,i=n; --i; g[u].emplace_back(v),g[v].emplace_back(u))
		scanf("%d%d",&u,&v);
	dfs0(1);
	for(int i=1; i<=n; ++i)
		dp[i][0].resize(siz[i]+1),dp[i][1].resize(siz[i]+1);
	dfs(1);
	ans[1]=ans1[1]=1;
	for(int i=2; i<=n; ++i)
		ans[i]=ans1[i]=dp[1][1][i-1]*quickpow(n,i-2)%mod;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
			if(((i^j)&1))
				ans1[i]=(ans1[i]+ll(mod-ans[j])*fac[n-j]%mod*ifac[n-i]%mod*ifac[i-j])%mod;
			else
				ans1[i]=(ans1[i]+ll(ans[j])*fac[n-j]%mod*ifac[n-i]%mod*ifac[i-j])%mod;
	for(int i=n; i; --i)
		printf("%d ",ans1[i]);
	return 0;
}