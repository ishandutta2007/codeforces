#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
vector<int> G[N];
int n;
int dis[N],fa[N];
int x,y,z,ans;
void bfs(int u)
{
	for(int i=1;i<=n;i++) dis[i]=N;
	for(int i=1;i<=n;i++) fa[i]=0;
	dis[u]=0;
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:G[u])
		{
			if(dis[v]==N) dis[v]=dis[u]+1,q.push(v),fa[v]=u;
		}
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u); 
	}
	bfs(1); x=1;
	for(int i=1;i<=n;i++) if(dis[i]>dis[x]) x=i;
	bfs(x); y=1;
	for(int i=1;i<=n;i++) if(dis[i]>dis[y]) y=i;
	ans+=dis[y];
	for(int i=1;i<=n;i++) dis[i]=N;
	queue<int> q;
	q.push(x),dis[x]=0;
	int tmp=y;
	while(tmp!=x)
	{
		q.push(tmp),dis[tmp]=0,tmp=fa[tmp];
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:G[u])
		{
			if(dis[v]==N) dis[v]=dis[u]+1,q.push(v);
		}
	}
	z=1;
	while(z==x||z==y) z++;
	for(int i=1;i<=n;i++) if(dis[i]>dis[z]) z=i;
	ans+=dis[z];
	cout<<ans<<endl;
	printf("%d %d %d\n",x,y,z);
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}