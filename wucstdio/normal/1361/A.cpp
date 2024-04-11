#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[1000005];
int n,m,edgenum,head[500005],t[500005],sa[500005],tmp[500005],top;
bool flag[500005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
bool cmp(int a,int b)
{
	return t[a]<t[b];
}
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)scanf("%d",&t[i]),sa[i]=i;
	sort(sa+1,sa+n+1,cmp);
	for(int o=1;o<=n;o++)
	{
		int i=sa[o];
		top=0;
		for(int hd=head[i];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(flag[to])tmp[++top]=t[to];
		}
		sort(tmp+1,tmp+top+1);
		int ans=1;
		for(int j=1;j<=top;j++)
		{
			if(tmp[j]>ans)break;
			if(tmp[j]==ans)ans++;
		}
		if(ans!=t[i])
		{
			printf("-1\n");
			return 0;
		}
		flag[i]=1;
	}
	for(int i=1;i<=n;i++)printf("%d ",sa[i]);
	printf("\n");
	return 0;
}