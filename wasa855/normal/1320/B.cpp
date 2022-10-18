#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 200005
struct Edge
{
	int v,nxt;
};
Edge edge[N*2];
int fir[N],ss;
void add(int u,int v)
{
	ss++;
	edge[ss].v=v,edge[ss].nxt=fir[u];
	fir[u]=ss;
}
int n,m,Q;
int dis[N],ok[N],fa[N];
int a[N];
void bfs(int s)
{
	for(int i=1;i<=n;i++) dis[i]=mod;
	dis[s]=0;
	queue<int> q; q.push(s);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=fir[u];i!=0;i=edge[i].nxt)
		{
			int v=edge[i].v;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				fa[v]=u;
				ok[v]=0;
				q.push(v);
			}
			else if(dis[v]==dis[u]+1) ok[v]=1;
		}
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(v,u);
	}
	Q=read();
	for(int i=1;i<=Q;i++) a[i]=read();
	bfs(a[Q]);
	int a1=0,a2=0;
	for(int i=1;i<Q;i++)
	{
//		printf("%d %d\n",dis[a[i]],dis[a[i+1]]);
		if(dis[a[i]]!=dis[a[i+1]]+1) a1++,a2++;
		if(dis[a[i]]==dis[a[i+1]]+1&&ok[a[i]]) a2++;
	}
	printf("%d %d\n",a1,a2);
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}