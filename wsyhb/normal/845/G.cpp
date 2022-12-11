#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int T=27+5;
int a[T];
const int M=1e5+5;
struct edge
{
	int x,y,w;
}e[M];
bool mark[M];
const int N=1e5+5;
int f[N];
int get(int x)
{
	return f[x]!=x?f[x]=get(f[x]):x;
}
int End[N<<1],Next[N<<1],Last[N],Len[N<<1];
int now;
void addedge(int x,int y,int z)
{
	End[++now]=y;
	Next[now]=Last[x];
	Last[x]=now;
	Len[now]=z;
	End[++now]=x;
	Next[now]=Last[y];
	Last[y]=now;
	Len[now]=z;
}
int val[N];
void dfs(int x,int fa)
{
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			val[y]=val[x]^Len[i];
			dfs(y,x);
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
		int x=get(e[i].x),y=get(e[i].y);
		if(x!=y)
		{
			f[x]=y;
			addedge(e[i].x,e[i].y,e[i].w);
			mark[i]=true;
		}
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
		if(!mark[i])
		{
			int x=val[e[i].x]^val[e[i].y]^e[i].w;
			for(int j=27;j>=0;j--)
				if(x&(1<<j))
				{
					if(!a[j])
					{
						a[j]=x;
						break;
					}
					else x^=a[j];
				}
		}
	int ans=val[1]^val[n];
	for(int i=27;i>=0;i--)
		if(ans>(ans^a[i])) ans^=a[i];
	printf("%d",ans);
	return 0;
}