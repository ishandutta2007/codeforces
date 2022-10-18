#include<bits/stdc++.h>
using namespace std;
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
#define M 1000005
#define N 100005
struct Edge
{
	int u,v,w;
};
Edge edge[M];
int fa[N];
int find(int u)
{
	int i=u;
	while(fa[i]!=i) i=fa[i];
	int j=u;
	while(j!=fa[j])
	{
		int k=fa[j];
		fa[j]=i;
		j=k;
	}
	return i;
}
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
	}
	edge[1].w=INF;
	for(int i=1;i<=n;i++) fa[i]=i;
	int xx=edge[1].u,yy=edge[1].v;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u!=v)
		{
			int xxx=find(xx),yyy=find(yy);
			if((xxx==u&&yyy==v)||(xxx==v&&yyy==u))
			{
				if(edge[i].w==INF)
				{
					cout<<(int)1e9<<endl;
					return 0;
				}
				printf("%d\n",edge[i].w);
				return 0;
			}
			fa[u]=v;
		}
	}
	return 0;
}