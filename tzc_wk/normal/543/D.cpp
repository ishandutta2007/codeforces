/*
Contest: -
Problem: Codeforces 543D
Author: tzc_wk
Time: 2020.10.19
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
const ll MOD=1e9+7;
int n,fa[200005];vector<int> son[200005];
vector<ll> pre[200005],suf[200005];
ll dp[200005],f[200005],ff[200005];
inline ll qpow(ll x,int e){
	ll ans=1;while(e){
		if(e&1) ans=ans*x%MOD;
		x=x*x%MOD;e>>=1;
	} return ans;
}
inline void dfs(int x){
	dp[x]=1;pre[x].resize(son[x].size());suf[x].resize(son[x].size());
	for(int i=0;i<son[x].size();i++){
		int y=son[x][i];dfs(y);
		dp[x]=dp[x]*(dp[y]+1)%MOD;
	}
}
inline void cgrt(int x){
	for(int i=0;i<son[x].size();i++){
		int y=son[x][i];
		if(i==0) pre[x][i]=(dp[y]+1)%MOD;
		else pre[x][i]=pre[x][i-1]*(dp[y]+1)%MOD;
	}
	for(int i=(int)(son[x].size()-1);~i;i--){
		int y=son[x][i];
		if(i==((int)son[x].size()-1)) suf[x][i]=(dp[y]+1)%MOD;
		else suf[x][i]=suf[x][i+1]*(dp[y]+1)%MOD;
	}
	for(int i=0;i<son[x].size();i++){
		int y=son[x][i];
		int _pre=((i==0)?1:pre[x][i-1]);
		int _suf=((i==(int)(son[x].size()-1))?1:suf[x][i+1]);
		ff[y]=ff[x]*_pre%MOD*_suf%MOD;ff[y]=(ff[y]+1)%MOD;
//		printf("%d %lld\n",y,ff[y]);
		f[y]=ff[y]*dp[y]%MOD;
		cgrt(y);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		son[fa[i]].pb(i);
	}
	dfs(1);f[1]=dp[1];ff[1]=1;cgrt(1);
	for(int i=1;i<=n;i++) printf("%lld ",f[i]);
	return 0;
}