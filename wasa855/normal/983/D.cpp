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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 400005
int l[N],r[N],u[N],d[N],n,t1[N*2],t2[N*2];
struct Opt
{
	int l,r,id;
	Opt(int a=0,int b=0,int c=0){l=a,r=b,id=c;}
};
vector<Opt> a[N];
struct Cmp
{
	bool operator () (const int &x,const int &y) const {return x>y;}
};
set<int,Cmp> t[N*4];
int minn[N*4],maxn[N*4];
bool vis[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)/2)
void pushup(int u,int l,int r)
{
	if(l==r)
	{
		if(!t[u].empty())
		{
			int v=*t[u].begin();
			if(!vis[v]) maxn[u]=v;
			else minn[u]=v;
			if(maxn[u]<minn[u]) maxn[u]=0;
		}
		else maxn[u]=minn[u]=0;
	}
	maxn[u]=max(maxn[ls],maxn[rs]),minn[u]=min(minn[ls],minn[rs]);
	if(!t[u].empty())
	{
		int v=*t[u].begin();
		if(!vis[v]) maxn[u]=max(maxn[u],v);
		else minn[u]=max(minn[u],v);
		if(maxn[u]<minn[u]) maxn[u]=0;
	}
}
void update(int u,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R)
	{
		if(v>0) t[u].insert(v);
		if(v<0) t[u].erase(-v);
		pushup(u,l,r);
		return ;
	}
	if(mid>=L) update(ls,l,mid,L,R,v);
	if(mid<R) update(rs,mid+1,r,L,R,v);
	pushup(u,l,r);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) l[i]=read(),u[i]=read(),r[i]=read(),d[i]=read();
	for(int i=1;i<=n;i++) t1[i]=l[i],t1[i+n]=r[i];
	for(int i=1;i<=n;i++) t2[i]=u[i],t2[i+n]=d[i];
	sort(t1+1,t1+n+n+1); int s1=unique(t1+1,t1+n+n+1)-t1-1;
	for(int i=1;i<=n;i++) l[i]=lower_bound(t1+1,t1+s1+1,l[i])-t1,r[i]=lower_bound(t1+1,t1+s1+1,r[i])-t1-1;
	sort(t2+1,t2+n+n+1); int s2=unique(t2+1,t2+n+n+1)-t2-1;
	for(int i=1;i<=n;i++) u[i]=lower_bound(t2+1,t2+s2+1,u[i])-t2,d[i]=lower_bound(t2+1,t2+s2+1,d[i])-t2-1;
	// for(int i=1;i<=n;i++) printf("%d %d %d %d\n",l[i],u[i],r[i],d[i]);
	for(int i=1;i<=n;i++) a[l[i]].eb(u[i],d[i],i),a[r[i]+1].eb(u[i],d[i],-i);
	int ans=1;
	for(int i=1;i<=s1;i++)
	{
		for(auto [l,r,id]:a[i]) update(1,1,s2,l,r,id);
		while(maxn[1])
		{
			vis[maxn[1]]=1; ans++;
			// printf("%d\n",maxn[1]);
			update(1,1,s2,u[maxn[1]],d[maxn[1]],0);
		}
	}
	cout<<ans<<endl;
	return 0;
}