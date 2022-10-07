#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,pa[600005],size[600005],ans,a[300005],b[300005];
bool flag[600005];
char s[300005];
int find(int x)
{
	return pa[x]==x?x:pa[x]=find(pa[x]);
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=2*k;i++)pa[i]=i,size[i]=i<=k?1:0;
	for(int i=1;i<=k;i++)
	{
		int c;
		scanf("%d",&c);
		while(c--)
		{
			int x;
			scanf("%d",&x);
			if(!a[x])a[x]=i;
			else b[x]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			printf("%d\n",ans);
			continue;
		}
		if(s[i]=='1')
		{
			if(!b[i])
			{
				int u=find(a[i]),v=find(a[i]+k);
				ans-=flag[u]||flag[v]?flag[u]*size[u]+flag[v]*size[v]:min(size[u],size[v]);
				ans+=size[v];
				flag[v]=1;
			}
			else
			{
				int u=find(a[i]),v=find(a[i]+k);
				int c=find(b[i]),d=find(b[i]+k);
				ans-=flag[u]||flag[v]?flag[u]*size[u]+flag[v]*size[v]:min(size[u],size[v]);
				if(u!=c)
				{
					ans-=flag[c]||flag[d]?flag[c]*size[c]+flag[d]*size[d]:min(size[c],size[d]);
					pa[c]=u,flag[u]|=flag[c],size[u]+=size[c];
					pa[d]=v,flag[v]|=flag[d],size[v]+=size[d];
				}
				ans+=flag[u]||flag[v]?flag[u]*size[u]+flag[v]*size[v]:min(size[u],size[v]);
			}
		}
		else
		{
			if(!b[i])
			{
				int u=find(a[i]),v=find(a[i]+k);
				ans-=flag[u]||flag[v]?flag[u]*size[u]+flag[v]*size[v]:min(size[u],size[v]);
				ans+=size[u];
				flag[u]=1;
			}
			else
			{
				int u=find(a[i]),v=find(a[i]+k);
				int d=find(b[i]),c=find(b[i]+k);
				ans-=flag[u]||flag[v]?flag[u]*size[u]+flag[v]*size[v]:min(size[u],size[v]);
				if(u!=c)
				{
					ans-=flag[c]||flag[d]?flag[c]*size[c]+flag[d]*size[d]:min(size[c],size[d]);
					pa[c]=u,flag[u]|=flag[c],size[u]+=size[c];
					pa[d]=v,flag[v]|=flag[d],size[v]+=size[d];
				}
				ans+=flag[u]||flag[v]?flag[u]*size[u]+flag[v]*size[v]:min(size[u],size[v]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}