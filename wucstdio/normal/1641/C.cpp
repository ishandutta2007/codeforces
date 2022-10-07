#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q,pa[1000005],ll[1000005];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n+1;i++)ll[i]=-1,pa[i]=i;
	while(q--)
	{
		int t;
		scanf("%d",&t);
		if(t==0)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			if(x==0)
			{
				while(find(l)!=find(r+1))
				{
					int u=find(l),v=find(r+1);
					pa[u]=v;
					ll[v]=max(ll[v],ll[u]);
					l=u+1;
				}
			}
			else ll[find(r+1)]=max(ll[find(r+1)],find(l));
		}
		else
		{
			int x;
			scanf("%d",&x);
			if(find(x)!=x)printf("NO\n");
			else if(find(ll[find(x+1)])==x)printf("YES\n");
			else printf("N/A\n");
		}
	}
	return 0;
}