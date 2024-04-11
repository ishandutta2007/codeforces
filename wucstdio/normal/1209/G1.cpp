#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005],nxt[200005],last[200005],ans,pa[200005],size[200005];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main()
{
	scanf("%d%*d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		size[a[i]]++;
	}
	for(int i=1;i<=200000;i++)pa[i]=i;
	for(int i=n;i>=1;i--)
	{
		nxt[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(!nxt[i])continue;
		for(int j=i;j<=nxt[i];j++)
		{
			int x=find(a[i]),y=find(a[j]);
			nxt[i]=max(nxt[i],nxt[j]);
			if(x!=y)
			{
				pa[x]=y;
				ans+=min(size[x],size[y]);
				size[y]=max(size[y],size[x]);
			}
		}
		i=nxt[i]-1;
	}
	printf("%d\n",ans);
	return 0;
}