#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int T,n;
struct edge
{
	int to,next;
}e[maxn*8];
int head[maxn*4],p;
void addedge(int u,int v)
{
	e[++p].to=v;e[p].next=head[u];head[u]=p;
	e[++p].to=u;e[p].next=head[v];head[v]=p;
}
char col[maxn*4];
int d[maxn*4];
int has[5];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		p=0;
		for(int i=1;i<=n*4;++i)head[i]=0,d[i]=0,col[i]=0;
		memset(has,0,sizeof(has));
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			d[u]++;d[v]++;
			addedge(u,v);
		}
		scanf("%s",col+1);
		int cnt=n;
		for(int i=1;i<=n;++i)if(col[i]=='W')
		{
			d[i]++;
			d[++cnt]=3;
			addedge(i,cnt);
			d[++cnt]=1;
			addedge(cnt-1,cnt);
			d[++cnt]=1;
			addedge(cnt-2,cnt);
		}
		n=cnt;
		for(int i=1;i<=n;++i)has[min(d[i],4)]++;
		if(has[4])puts("White");
		else if(has[3])
		{
			bool yes=0;
			for(int u=1;u<=n;++u)if(d[u]==3)
			{
				int num=0;
				for(int i=head[u];i;i=e[i].next)
				{
					int v=e[i].to;
					if(d[v]>1)num++;
				}
				if(num>=2)yes=1;
			}
			if(yes)puts("White");
			else
			{
				if(has[3]==2)
				{
					if(n&1)puts("White");
					else puts("Draw");
				}
				else puts("Draw");
			}
		}
		else puts("Draw");
	}
	return 0;
}