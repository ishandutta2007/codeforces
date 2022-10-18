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
map<pii,int> vis;
set<int> a[N],b[N];
int n,m,Q;
struct SMT
{
	
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)/2)
	int f[N*4],ta[N*4],tb[N*4];
	void pushup(int u)
	{
		ta[u]=min(ta[ls],ta[rs]);
		tb[u]=max(tb[ls],tb[rs]);
		f[u]=f[ls]||f[rs]||(ta[ls]<=tb[rs]);
	}
	void build(int u,int l,int r)
	{
		if(l==r)
		{
			ta[u]=*a[l].begin(),tb[u]=*(--b[l].end());
			f[u]=ta[u]<=tb[u];
			return ;
		}
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
	void update(int u,int l,int r,int pl)
	{
		if(l==r)
		{
			ta[u]=*a[l].begin(),tb[u]=*(--b[l].end());
			f[u]=ta[u]<=tb[u];
			return ;
		}
		if(pl<=mid) update(ls,l,mid,pl);
		else update(rs,mid+1,r,pl);
		pushup(u);
	}
	int query(){return f[1];}
#undef ls
#undef rs
#undef mid
}smt;
signed main()
{
	cin>>n>>m>>Q;
	for(int i=1;i<=m;i++) a[i].insert(inf),b[i].insert(0);
	smt.build(1,1,m);
	while(Q--)
	{
		int x=read(),y=read();
		if(vis[{x,y}])
		{
			vis[{x,y}]=0;
			if(x%2==1) a[(y+1)/2].erase((x+1)/2);
			else b[(y+1)/2].erase((x+1)/2);
		}
		else
		{
			vis[{x,y}]=1;
			if(x%2==1) a[(y+1)/2].insert((x+1)/2);
			else b[(y+1)/2].insert((x+1)/2);
		}
		smt.update(1,1,m,(y+1)/2);
		printf("%s\n",smt.query()?"NO":"YES");
	}
	return 0;
}