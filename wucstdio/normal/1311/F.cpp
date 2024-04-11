#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,_v[200005],_x[200005],v[200005],x[200005],sa[200005];
ll c1[200005],c2[200005];
bool cmp1(int a,int b)
{
	return _x[a]<_x[b];
}
bool cmp(int a,int b)
{
	return v[a]<v[b]||(v[a]==v[b]&&x[a]<x[b]);
}
void add(int p,ll v)
{
	while(p<=n)
	{
		c1[p]++;
		c2[p]+=v;
		p+=p^(p&(p-1));
	}
}
pair<ll,ll>sum(int p)
{
	ll ans1=0,ans2=0;
	while(p)
	{
		ans1+=c1[p];
		ans2+=c2[p];
		p&=p-1;
	}
	return make_pair(ans1,ans2);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&_x[i]);
		sa[i]=i;
	}
	for(int i=1;i<=n;i++)scanf("%d",&_v[i]);
	sort(sa+1,sa+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		v[i]=_v[sa[i]];
		x[i]=_x[sa[i]];
		sa[i]=i;
	}
	sort(sa+1,sa+n+1,cmp);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		pair<ll,ll>res=sum(sa[i]-1);
		ans+=res.first*x[sa[i]]-res.second;
		add(sa[i],x[sa[i]]);
	}
	printf("%lld\n",ans);
	return 0;
}