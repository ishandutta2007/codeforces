#include <bits/stdc++.h>
#define Maxn 400007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,ans=0,cnt=-1;
int r[Maxn][4];
int last[Maxn],pre[Maxn],other[Maxn];
bool vis[Maxn],v1[Maxn];
int tot;
void insert(int u,int v)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
	vis[u]=true;
	int tot=0;
	pair<int,int> s;
	for (int q=last[u];q>-1;q=pre[q])
	{
		int v=other[q];
		if (v!=fa&&!vis[v])
		{
			dfs(v,u);
			if (v1[q]) 
			{
				if (tot==0) {s=make_pair(v,q);++tot;}
				else
				{
					tot=0;
					++ans;
					r[ans][1]=s.first;
					r[ans][2]=u;
					r[ans][3]=v;
					v1[s.second]=false;v1[s.second^1]=false;
					v1[q]=false;v1[q^1]=false;
				}
			}
		} else if (v!=fa&&vis[v])
		{
			if (v1[q]) 
			{
				if (tot==0) {s=make_pair(v,q);++tot;}
				else
				{
					tot=0;
					++ans;
					r[ans][1]=s.first;
					r[ans][2]=u;
					r[ans][3]=v;
					v1[s.second]=false;v1[s.second^1]=false;
					v1[q]=false;v1[q^1]=false;
				}
			}
		}
	}
	int a=-1;
	for (int q=last[u];q>-1;q=pre[q]) if (other[q]==fa) a=q;
	if (tot==1&&a>-1&&v1[a])
	{
					tot=0;
					++ans;
					r[ans][1]=s.first;
					r[ans][2]=u;
					r[ans][3]=fa;
					v1[s.second]=false;v1[s.second^1]=false;
					v1[a]=false;v1[a^1]=false;
	}
}
int main()
{
	n=read(),m=read();
	memset(last,-1,sizeof(last));
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		insert(u,v),insert(v,u);
	}
	memset(vis,false,sizeof(vis));
	memset(v1,true,sizeof(v1));
	for (int i=1;i<=n;i++)
		if (!vis[i]) dfs(i,0);
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++)
		printf("%d %d %d\n",r[i][1],r[i][2],r[i][3]);
	return 0;
}