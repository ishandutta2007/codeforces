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
#define ll long long
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
#define N 200005
int fa[N*2],siz[N*2],n;
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
int a[N],b[N];
vector<int> v[N];
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if(u==v) return ;
	fa[u]=v; siz[v]+=siz[u];
}
bool vis[N*2],ch[N*2];
void work()
{
	cin>>n;
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<=n;i++) a[i]=read(),v[a[i]].pb(i);
	for(int i=1;i<=n;i++) b[i]=read(),v[b[i]].pb(i+n);
	for(int i=1;i<=2*n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) siz[i]=1;
	for(int i=n+1;i<=2*n;i++) siz[i]=0;
	for(int i=1;i<=n*2;i++) vis[i]=ch[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(v[i].size()!=2) {cout<<"-1\n"; return ;}
		int a=v[i][0],b=v[i][1];
		if(a>b) swap(a,b);
		if(a==b-n) continue;
		if(a>n)
		{
			a-=n,b-=n;
			merge(a,b+n),merge(a+n,b);
		}
		else if(b<=n) merge(a,b+n),merge(a+n,b);
		else
		{
			b-=n;
			merge(a,b),merge(a+n,b+n);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(find(i)==find(i+n)) {cout<<"-1\n"; return ;}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int u=find(i),v=find(i+n);
		if(vis[u]||vis[v]) continue;
		ans+=min(siz[u],siz[v]);
		vis[u]=vis[v]=1;
		if(siz[u]<siz[v]) ch[u]=1;
		else ch[v]=1;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		int u=find(i);
		if(ch[u]) printf("%d ",i);
	}
	cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}