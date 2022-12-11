#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll l,r;
int k;
int num[22],cnt;
ll f[22][10][1050][2][2],g[22][10][1050][2][2];
bool vis[22][10][1050][2][2];
ll fastpow(ll a,ll p)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;p>>=1;
	}
	return ans;
}
void dfs(int l,int x,int S,bool pz,bool lim)
{
	if(vis[l][x][S][pz][lim])return;
	vis[l][x][S][pz][lim]=1;
	int t=0;
	for(int i=0;i<10;++i)if(S&(1<<i))t++;
	if(t>k)return;
	if(l==1)
	{
		f[l][x][S][pz][lim]=1,g[l][x][S][pz][lim]=x;
		return;
	}
	int up=(lim)?num[l-1]:9;
	for(int i=0;i<=up;++i)
	{
		dfs(l-1,i,(pz&(!i))?0:(S|(1<<i)),pz&(!i),lim&(i==num[l-1]));
		f[l][x][S][pz][lim]=(f[l][x][S][pz][lim]+f[l-1][i][(pz&(!i))?0:(S|(1<<i))][pz&(!i)][lim&(i==num[l-1])])%mod;
		g[l][x][S][pz][lim]=(g[l][x][S][pz][lim]+g[l-1][i][(pz&(!i))?0:(S|(1<<i))][pz&(!i)][lim&(i==num[l-1])])%mod;
	}
	g[l][x][S][pz][lim]=(g[l][x][S][pz][lim]+f[l][x][S][pz][lim]*x%mod*fastpow(10,l-1)%mod)%mod;
}
ll solve(ll n)
{
	if(!n)return 0; 
	memset(num,0,sizeof(num));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	memset(vis,0,sizeof(vis));
	cnt=0;
	ll x=n;
	while(x)
	{
		num[++cnt]=x%10;
		x/=10;
	}
	ll ans=0;
	for(int i=0;i<=num[cnt];++i)
	{
		dfs(cnt,i,(i==0)?0:(1<<i),(i==0),(i==num[cnt]));
		ans=(ans+g[cnt][i][(i==0)?0:(1<<i)][(i==0)][(i==num[cnt])])%mod;
	}
	return ans;
}
int main()
{
	scanf("%I64d%I64d%d",&l,&r,&k);
	printf("%I64d\n",(solve(r)-solve(l-1)+mod)%mod);
	return 0;
}