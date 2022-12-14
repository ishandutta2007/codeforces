#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define mod 998244353
inline int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
int fac[N],inv[N],n,head[N],f[N],siz[N],cnt,d[N];
struct node{int to,next;}e[N<<1];
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;d[x]++;}
void dfs(int x,int from)
{
	siz[x]=1;if(from)f[x]=fac[d[x]];else f[x]=fac[d[x]];
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs(to1,x),siz[x]+=siz[to1],f[x]=(ll)f[x]*f[to1]%mod;
	}
}
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;inv[n]=q_pow(fac[n],mod-2);
	for(int i=n;i;i--)inv[i-1]=(ll)inv[i]*i%mod;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dfs(1,0);printf("%lld\n",(ll)f[1]*n%mod);
}