#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 2005
struct Node
{
	int x,y;
};
struct Edge
{
	int u,v,w;
};
Edge edge[N*N];
Node a[N];
int c[N],k[N];
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int fa[N];
int find(int u)
{
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
vector<int> bui;
vector<Edge> con;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i].x=read(),a[i].y=read();
	}
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++) k[i]=read();
	int ss=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ss++;
			edge[ss].u=i,edge[ss].v=j;
			edge[ss].w=(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y))*(k[i]+k[j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		ss++;
		edge[ss].u=i,edge[ss].v=n+1;
		edge[ss].w=c[i];
	}
	sort(edge+1,edge+ss+1,cmp);
	for(int i=1;i<=n+1;i++) fa[i]=i;
	int ans=0;
	for(int i=1;i<=ss;i++)
	{
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u!=v)
		{
			ans+=edge[i].w;
			fa[u]=v;
			if(edge[i].u==n+1) bui.pb(edge[i].v);
			else if(edge[i].v==n+1) bui.pb(edge[i].u);
			else con.pb(edge[i]);
		}
	}
	cout<<ans<<endl;
	cout<<bui.size()<<endl;
	for(int u:bui) printf("%lld ",u);
	cout<<"\n";
	cout<<con.size()<<endl;
	for(Edge u:con) printf("%lld %lld\n",u.u,u.v);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}