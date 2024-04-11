#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m,sa[100005],from[300005],to[300005];
ll a[100005],d[300005];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v;
		ll l;
		scanf("%d%d%lld",&u,&v,&l);
		a[u]+=l;
		a[v]-=l;
	}
	for(int i=1;i<=n;i++)sa[i]=i;
	sort(sa+1,sa+n+1,cmp);
	int i=1,j=n;
	m=0;
	while(i!=j)
	{
		if(a[sa[i]]==0)i++;
		else if(a[sa[j]]==0)j--;
		else
		{
			from[++m]=sa[j];
			to[m]=sa[i];
			d[m]=min(a[sa[j]],-a[sa[i]]);
			a[sa[j]]-=d[m],a[sa[i]]+=d[m];
		}
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++)printf("%d %d %lld\n",from[i],to[i],d[i]);
	return 0;
}