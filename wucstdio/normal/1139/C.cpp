#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
int n,k,pa[100005],size[100005];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)pa[i]=i,size[i]=1;
	for(int i=1;i<n;i++)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		if(l==0)
		{
			u=find(u),v=find(v);
			if(u==v)continue;
			if(size[u]>size[v])swap(u,v);
			pa[u]=v;
			size[v]+=size[u];
		}
	}
	ll ans=quick_pow(n,k);
	for(int i=1;i<=n;i++)
	{
		if(find(i)==i)
		  ans-=quick_pow(size[i],k);
	}
	ans%=MOD;
	if(ans<0)ans+=MOD;
	printf("%I64d\n",ans);
	return 0;
}