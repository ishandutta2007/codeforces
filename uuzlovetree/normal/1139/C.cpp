#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
const ll mod = 1000000007;
#define maxn 100005
int n,k;
int fa[maxn];
ll sz[maxn];
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
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
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<n;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(!w)
		{
			if(find(u)!=find(v))fa[find(u)]=find(v);
		}
	}
	ll ans=fastpow(n,k);
	for(int i=1;i<=n;++i)sz[find(i)]++;
	for(int i=1;i<=n;++i)if(find(i)==i)
	{
		ans=(ans-fastpow(sz[i],k)+mod)%mod;
	}
	printf("%I64d\n",ans);
}