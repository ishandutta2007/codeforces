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
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 200005
vector<int> G[N];
int a[N];
bool s[N];
int n,m,k;
int dis[N];
int dm[N];
int fa[N];
bool iw[N];
void dij()
{
	for(int i=1;i<=n;i++) dis[i]=N;
	dis[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:G[u])
		{
			if(dis[v]>dis[u]+1)
			{
				fa[v]=u;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
void dij2()
{
	for(int i=1;i<=n;i++) dm[i]=N;
	dm[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:G[u])
		{
			if(dm[v]>dm[u]+1)
			{
				fa[v]=u;
				dm[v]=dm[u]+1;
				q.push(v);
			}
		}
	}
}
bool cmp(int x,int y)
{
	if(dis[x]!=dis[y]) return dis[x]>dis[y];
	return dm[x]>dm[y];
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) a[i]=read();
	for(int i=1;i<=k;i++) s[a[i]]=1;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dij(); dij2();
//	for(int i=1;i<=n;i++) printf("%d ",dis[i]); cout<<"\n";
//	for(int i=1;i<=n;i++) printf("%d ",dm[i]); cout<<"\n";
	int ans=0;
	sort(a+1,a+k+1,cmp);
	int maxn=dm[a[1]];
	for(int i=2;i<=k;i++)
	{
		if(dis[a[i]]+maxn+1>ans) ans=dis[a[i]]+maxn+1;
		if(dm[a[i]]>maxn) maxn=dm[a[i]];
	}
	cout<<min(ans,dis[n])<<endl;
//	vector<int> ou,way;
//	int t=n;
//	while(t!=1)
//	{
//		way.pb(t);
//		iw[t]=1;
//		t=fa[t];
//	}
//	iw[1]=1;
//	way.pb(1);
//	int minn=0;
//	for(int i=0;i<way.size()-1;i++)
//	{
//		if(way)
//	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}