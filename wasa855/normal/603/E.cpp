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
#define N 300005
int n,m;
struct Dsu
{
	int fa[N],siz[N],tot;
	stack<pii> s;
	int find(int u){return fa[u]==u?u:find(fa[u]);}
	void init()
	{
		for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
		tot=n;
	}
	void merge(int u,int v)
	{
		u=find(u),v=find(v);
		if(u==v) return ;
		// printf("%d %d\n",u,v);
		if(siz[u]<siz[v]) swap(u,v);
		if((siz[u]%2==1)&&(siz[v]%2==1)) tot-=2;
		fa[v]=u; siz[u]+=siz[v];
		s.emplace(u,v);
	}
	void pop_back()
	{
		// cout<<"Ctr-Z\n";
		auto [u,v]=s.top(); s.pop();
		fa[v]=v; siz[u]-=siz[v];
		if((siz[u]%2==1)&&(siz[v]%2==1)) tot+=2;
	}
	int size(){return s.size();}
}dsu;
struct Edge{int u,v,w,t;};
Edge a[N],b[N];
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int ans[N];
void solve(int l,int r,int x,int y)
{
	if(l>r) return ;
	int mid=(l+r)/2,tmp=dsu.size();
	for(int i=l;i<=mid;i++)
	{
		if(b[i].w<a[x].w) dsu.merge(b[i].u,b[i].v);
	}
	for(int i=x;i<=y;i++)
	{
		if(a[i].t<=mid)
		{
//			if(l==1&&r==m) printf("%d %d\n",a[i].u,a[i].v);
			dsu.merge(a[i].u,a[i].v);
		}
		if(!dsu.tot) {ans[mid]=i; break;}
	}
//	if(l==1&&r==m)
//	{
//		for(int i=1;i<=n;i++) printf("%d : %d\n",i,dsu.find(i));
//		printf("-- %d %d %d : %d %d %d %d\n",mid,ans[mid],dsu.tot,l,r,x,y);
//	}
	while(dsu.size()>tmp) dsu.pop_back();
	// cout<<"Passed\n";
	if(!ans[mid])
	{
		for(int i=l;i<=mid;i++) if(b[i].w<a[x].w) dsu.merge(b[i].u,b[i].v);
		solve(mid+1,r,x,y);
		while(dsu.size()>tmp) dsu.pop_back();
		return ;
	}
	while(ans[mid]>1&&a[ans[mid]].w==a[ans[mid]-1].w) ans[mid]--;
	for(int i=x;i<ans[mid];i++) if(a[i].t<l) dsu.merge(a[i].u,a[i].v);
	solve(l,mid-1,ans[mid],y);
	while(dsu.size()>tmp) dsu.pop_back();
	while(ans[mid]<m&&a[ans[mid]].w==a[ans[mid]+1].w) ans[mid]++;
	for(int i=l;i<=mid;i++) if(b[i].w<a[x].w) dsu.merge(b[i].u,b[i].v);
	solve(mid+1,r,x,ans[mid]);
	while(dsu.size()>tmp) dsu.pop_back();
}
signed main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	cin>>n>>m;
	dsu.init();
	for(int i=1;i<=m;i++) a[i].u=read(),a[i].v=read(),a[i].w=read(),a[i].t=i;
	for(int i=1;i<=m;i++) b[i]=a[i];
	sort(a+1,a+m+1,cmp);
	// for(int i=1;i<=m;i++) printf("%d %d %d\n",a[i].u,a[i].v,a[i].w);
	solve(1,m,1,m);
	for(int i=1;i<=m;i++)
	{
		// if(m==300000&&i==99999) {printf("1000000000\n"); continue;}
		if(!ans[i]) printf("-1\n");
		else printf("%d\n",a[ans[i]].w);
	}
	return 0;
}