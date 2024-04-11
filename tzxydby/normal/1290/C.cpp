#include<bits/stdc++.h>
using namespace std;
const int N=600005;
long long fa[N],a[N],n,k,ans;
int b[N];
vector<int>e[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unite(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)
		return;
	fa[x]=y;
	ans-=min(a[x],a[x^1]);
	ans-=min(a[y],a[y^1]);
	a[y]+=a[x];
	ans+=min(a[y],a[y^1]);
	a[x]=0;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=(k<<1|1);i++)
		fa[i]=i,a[i]=i&1;
	for(int i=1;i<=n;i++)
		scanf("%1d",&b[i]);
	for(int i=1;i<=k;i++)
	{
		int m;
		scanf("%d",&m);
		while(m--)
		{
			int x;
			scanf("%d",&x);
			e[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!e[i].size())
		{
			printf("%d\n",ans);
			continue;
		}
		if(e[i].size()==1)
		{
			int p=b[i]==1?find(e[i][0]<<1|1):find(e[i][0]<<1);
			ans-=min(a[p],a[p^1]);
			a[p]=1e9;
			ans+=a[p^1];
		}
		else
		{
			if(b[i]==1)
			{
				unite(e[i][0]<<1,e[i][1]<<1);
				unite(e[i][0]<<1|1,e[i][1]<<1|1);
			}
			else
			{
				unite(e[i][0]<<1,e[i][1]<<1|1);
				unite(e[i][0]<<1|1,e[i][1]<<1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}