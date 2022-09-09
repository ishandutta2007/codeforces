#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
const int mod=998244353;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int inv(int x){ return pow(x,mod-2);}
int dvd(int x, int y){ return mul(x,inv(y));}
int p[N],dp[N],cnt[N],Z[N];
vector<int> E[N];
void Solve(int u)
{
	if(E[u].empty()){ dp[u]=cnt[u]=1;return;}
	vector<int> pre(1,1),suf,taj;
	for(int v:E[u]) Solve(v),pre.pb(dp[v]),taj.pb(dp[v]);
	for(int i=0;i<E[u].size();i++) pre[i+1]=mul(pre[i],pre[i+1]);
	suf.resize(E[u].size()+2);
	suf[E[u].size()+1]=1;
	for(int i=E[u].size();i>0;i--) suf[i]=mul(suf[i+1],taj[i-1]);
	int pdp=1;
	for(int v:E[u]) pdp=mul(pdp,dp[v]);
	int pcn=1;
	for(int v:E[u]) pcn=mul(pcn,add(cnt[v],dp[v]));
	int smc=0;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		int d=mul(pre[i],suf[i+2]);
		smc=add(smc,mul(cnt[v],d));
	}
	Z[u]=sub(pcn,add(pdp,smc));
	dp[u]=add(pdp,Z[u]);
	cnt[u]=add(Z[u],smc);
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=2;i<=n;i++) scanf("%i",&p[i]),E[p[i]].pb(i);
	Solve(1);
	printf("%i\n",dp[1]);
	return 0;
}