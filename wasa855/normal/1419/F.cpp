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
#define inf 10000000000LL
#define QAQ 1145141919810LL
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 3005
struct Node
{
	int x,y;
};
Node a[N],b[N];
int tx[N],ty[N];
int ix[N],iy[N];
int n;
struct Union_set
{
	int fa[N],siz[N];
	int find(int u){return fa[u]==u?u:find(fa[u]);}
	int stu[N],stv[N],tp;
	void init(){for(int i=1;i<=n+1;i++) fa[i]=i,siz[i]=1; tp=0;}
	void merge(int u,int v)
	{
		u=find(u),v=find(v);
		if(u==v) return ;
		if(siz[u]<siz[v]) swap(u,v);
		siz[u]+=siz[v],fa[v]=u;
		stu[++tp]=u,stv[tp]=v;
	}
	void pop()
	{
		int u=stu[tp],v=stv[tp]; tp--;
		siz[u]-=siz[v],fa[v]=v;
	}
	inline int size(){return tp;}
}dsu;
vector<pii> vx[N],vy[N];
bool chk(int mid)
{
	dsu.init();
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i].x==a[j].x&&abs(a[i].y-a[j].y)<=mid) dsu.merge(i,j);
			if(a[i].y==a[j].y&&abs(a[i].x-a[j].x)<=mid) dsu.merge(i,j);
		}
	}
	int cx=0,cy=0;
	for(int i=1;i<=n;i++) tx[++cx]=a[i].x-mid,tx[++cx]=a[i].x,tx[++cx]=a[i].x+mid;
	sort(tx+1,tx+cx+1); cx=unique(tx+1,tx+cx+1)-tx-1;
	for(int i=1;i<=n;i++) ty[++cy]=a[i].y-mid,ty[++cy]=a[i].y,ty[++cy]=a[i].y+mid;
	sort(ty+1,ty+cy+1); cy=unique(ty+1,ty+cy+1)-ty-1;
	for(int i=1;i<=cx;i++) vx[i].clear();
	for(int i=1;i<=cy;i++) vy[i].clear();
	for(int i=1;i<=n;i++) ix[i]=lower_bound(tx+1,tx+cx+1,a[i].x)-tx;
	for(int i=1;i<=n;i++) iy[i]=lower_bound(ty+1,ty+cy+1,a[i].y)-ty;
	for(int i=1;i<=n;i++) vx[ix[i]].eb(i,a[i].y);
	for(int i=1;i<=n;i++) vy[iy[i]].eb(i,a[i].x);
	for(int i=1;i<=cx;i++)
	{
		for(int j=1;j<=cy;j++)
		{
			int S=dsu.size();
			int px=-inf,pid=0,sx=inf,sid=0;
			for(auto [id,x]:vy[j])
			{
				if(x<=tx[i]&&x>px) px=x,pid=id;
				if(x>=tx[i]&&x<sx) sx=x,sid=id;
			}
			if(pid&&abs(px-tx[i])<=mid) dsu.merge(n+1,pid);
			if(sid&&abs(sx-tx[i])<=mid) dsu.merge(n+1,sid);
			int py=-inf,sy=inf; pid=0,sid=0;
			for(auto [id,y]:vx[i])
			{
				if(y<=ty[j]&&y>py) py=y,pid=id;
				if(y>=ty[j]&&y<sy) sy=y,sid=id;
			}
			if(pid&&abs(py-ty[j])<=mid) dsu.merge(n+1,pid);
			if(sid&&abs(sy-ty[j])<=mid) dsu.merge(n+1,sid);
			if(dsu.size()==n) return 1;
			while(dsu.size()>S) dsu.pop();
		}
	}
	return 0;
	
	/*
	vx.clear(),vy.clear();
	for(int i=1;i<=cx;i++) for(int j=1;j<=cy;j++) px[i][j]=py[i][j]=sx[i][j]=sy[i][j]=QAQ;
	for(int l=1;l<=n;l++)
	{
		int rk=lower_bound(tx+1,tx+cx+1,b[i].x);
		int r=l; while(r!=n&&b[l].x==b[r+1].x) r++;
		int tmp=l
				
		l=r;
	}
	*/
}
signed main()
{
	cin>>n; for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	for(int i=1;i<=n;i++) b[i]=a[i];
	int l=0,r=inf,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chk(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}