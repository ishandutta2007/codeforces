#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[100005],dep[100005],d[100005],pa[100005],root,ddep[100005],size[100005],maxx[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void getroot(int node)
{
	size[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		getroot(to);
		size[node]+=size[to];
		maxx[node]=max(maxx[node],size[to]);
	}
	maxx[node]=max(maxx[node],n-size[node]);
	if(maxx[node]<maxx[root])root=node;
}
void dfs(int node)
{
	dep[node]=dep[pa[node]]+1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
	}
}
int main()
{
	maxx[0]=1000000000;
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		d[u]++,d[v]++;
	}
	getroot(1);
	memset(dep,0,sizeof(dep));
	memset(pa,0,sizeof(pa));
	dfs(root);
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		if(ddep[dep[i]]==0)
		{
			ddep[dep[i]]=d[i];
			continue;
		}
		else if(ddep[dep[i]]!=d[i])
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		printf("%d\n",root);
		return 0;
	}
	int d1=0,d2=0,num1=0,num2=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]!=1)continue;
		if(!d1)d1=i,num1=1;
		else if(dep[i]==dep[d1])num1++;
		else if(!d2)d2=i,num2=1;
		else if(dep[i]==dep[d2])num2++;
		else
		{
			printf("-1\n");
			return 0;
		}
	}
	if(num1!=1&&num2!=1)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]!=1)continue;
			root=i;
			memset(dep,0,sizeof(dep));
			memset(pa,0,sizeof(pa));
			memset(ddep,0,sizeof(ddep));
			dfs(root);
			bool flag=1;
			for(int i=1;i<=n;i++)
			{
				if(ddep[dep[i]]==0)
				{
					ddep[dep[i]]=d[i];
					continue;
				}
				else if(ddep[dep[i]]!=d[i])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				printf("%d\n",root);
				return 0;
			}
		}
		printf("-1\n");
		return 0;
	}
	if(num1!=1)swap(d1,d2);
	root=d1;
	memset(dep,0,sizeof(dep));
	memset(pa,0,sizeof(pa));
	memset(ddep,0,sizeof(ddep));
	dfs(root);
	for(int i=1;i<=n;i++)
	{
		if(ddep[dep[i]]==0)
		{
			ddep[dep[i]]=d[i];
			continue;
		}
		else if(ddep[dep[i]]!=d[i])
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",root);
	return 0;
}