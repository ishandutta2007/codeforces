#include<bits/stdc++.h>
using namespace std;
const long long N=1001;
const long long mod=1e9+7;
long long fp(long long x,long long y){
	long long res=1;
	while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
	return res;
}
long long inv(long long x){return fp(x,mod-2);}
struct edge{
	long long nxt,to;
};
struct graph{
	edge ed[N<<1];
	long long n,cnt;
	long long h[N],son[N][N],siz[N],bit[N];
	void add(long long x,long long y){ed[++cnt].to=y;ed[cnt].nxt=h[x];h[x]=cnt;}
	void init(){
		scanf("%lld",&n);
		for(long long i=1;i<n;i++){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			add(x,y);
			add(y,x);
		}
	}
	void dfs(long long x,long long fa){
		siz[x]=bit[x]=0;
		for(long long i=h[x];i;i=ed[i].nxt){
			if(ed[i].to^fa)dfs(son[x][++siz[x]]=ed[i].to,x),bit[x]|=1<<ed[i].to-1;
		}
	}
}S,T;
long long dp[N][1<<12],ans1,ans2;
bool vis[N][1<<12];
long long dfs(long long f,long long y,long long V){
	if(!y)return!V;
	long long x=S.son[f][y];
	if(vis[x][V])return dp[x][V];
	vis[x][V]=1;
	dp[x][V]=dfs(f,y-1,V);
	for(long long i=0;i<T.n;i++)if(V>>i&1)
	dp[x][V]=(1ll*dfs(f,y-1,V^(1<<i))*dfs(x,S.siz[x],T.bit[i+1])+dp[x][V])%mod;
	return dp[x][V];
}
int main(){
	S.init();
	T.init();
	S.dfs(1,0);
	for(long long i=1;i<=T.n;i++){
		memset(dp,0,sizeof dp);
		memset(vis,0,sizeof vis);
		T.dfs(i,0);
		for(long long j=1;j<=S.n;j++)(ans1+=dfs(j,S.siz[j],T.bit[i]))%=mod;
	}
	S=T;
	S.dfs(1,0);
	for(long long i=1;i<=T.n;i++){
		memset(dp,0,sizeof dp);
		memset(vis,0,sizeof vis);
		T.dfs(i,0);
		(ans2+=dfs(1,S.siz[1],T.bit[i]))%=mod;
	}
	ans1=1ll*ans1*inv(ans2)%mod;
	return printf("%lld\n",ans1),0;
}