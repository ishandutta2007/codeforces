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
#define N 35005
int f[55][N],a[N],las[N],vis[N],nxt[N],n,k;
int tmp[N];
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int tag1[N*4],tag2[N*4];
	//  add       chkmax
	void build(int u,int l,int r)
	{
		tag1[u]=0,tag2[u]=-inf;
		if(l==r) return ;
		build(ls,l,mid),build(rs,mid+1,r);
	}
	void upd1(int u,int v) {tag1[u]+=v,tag2[u]-=v;}
	void upd2(int u,int v) {tag2[u]=max(tag2[u],v);}
	void pushdown(int u)
	{
		upd1(ls,tag1[u]),upd1(rs,tag1[u]),tag1[u]=0;
		upd2(ls,tag2[u]),upd2(rs,tag2[u]),tag2[u]=-inf;
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R) return upd1(u,v);
		pushdown(u);
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
	}
	void fix(int u,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R) return upd2(u,v);
		pushdown(u);
		if(mid>=L) fix(ls,l,mid,L,R,v);
		if(mid<R) fix(rs,mid+1,r,L,R,v);
	}
	void getans(int u,int l,int r)
	{
		if(l==r) {tmp[l]=tag2[u]; return ;}
		pushdown(u);
		getans(ls,l,mid),getans(rs,mid+1,r);
	}
}smt;
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) las[i]=vis[a[i]],nxt[vis[a[i]]]=i,vis[a[i]]=i;
	for(int i=1;i<=n;i++) f[0][i]=-inf;
	smt.build(1,1,n);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++) if(las[j]==0) smt.update(1,1,n,j,n,1);
		for(int j=0;j<n;j++)
		{
			if(j!=0)
			{
				smt.update(1,1,n,j,n,-1);
				if(nxt[j]) smt.update(1,1,n,nxt[j],n,1);
			}
			smt.fix(1,1,n,j+1,n,f[i-1][j]);
		}
		smt.getans(1,1,n);
		for(int j=1;j<=n;j++) f[i][j]=tmp[j];
	}
	cout<<f[k][n]+1<<endl;
	return 0;
}