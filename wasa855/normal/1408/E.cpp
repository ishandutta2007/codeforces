#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 300005
struct Edge
{
	int u,v,w;
};
Edge edge[N];
bool cmp(Edge x,Edge y){return x.w>y.w;}
int fa[N],a[N],b[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
signed main()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	for(int i=1;i<=n+m;i++) fa[i]=i;
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		int s=read();
		for(int j=1;j<=s;j++)
		{
			int x=read();
			edge[++cnt].u=x,edge[cnt].v=i+m,edge[cnt].w=a[i]+b[x];
			ans+=a[i]+b[x];
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u!=v)
		{
			fa[u]=v,ans-=edge[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}