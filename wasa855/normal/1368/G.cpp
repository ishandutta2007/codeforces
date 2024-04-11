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
#define N 200005
string s[N];
vector<int> G[N];
int n,m,dfn[N],siz[N],dfs_cnt;
inline int getid(int x,int y) {return (x-1)*m+y;}
void dfs(int u)
{
	siz[u]=1,dfn[u]=++dfs_cnt;
	for(int v:G[u]) dfs(v),siz[u]+=siz[v];
}
struct Query{int opt,pos,l,r;};
Query q[N*2]; int cnt;
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int cnt[N*8],len[N*8];
	void pushup(int u,int l,int r)
	{
		assert(cnt[u]>=0);
		if(cnt[u]) len[u]=r-l+1;
		else len[u]=len[ls]+len[rs];
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			cnt[u]+=v; pushup(u,l,r);
			return ;
		}
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
		pushup(u,l,r);
	
	}
	int qry() {return len[1];}
}smt;
bool cmp(Query x,Query y) {return x.pos<y.pos;}
int dgr[N];
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string t; cin>>t;
		s[i]=" "+t;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		if(i+2<=n&&s[i+1][j]=='U'&&s[i+2][j]=='D') G[getid(i,j)].pb(getid(i+2,j));
		if(i-2>=1&&s[i-1][j]=='D'&&s[i-2][j]=='U') G[getid(i,j)].pb(getid(i-2,j));
		if(j+2<=m&&s[i][j+1]=='L'&&s[i][j+2]=='R') G[getid(i,j)].pb(getid(i,j+2));
		if(j-2>=1&&s[i][j-1]=='R'&&s[i][j-2]=='L') G[getid(i,j)].pb(getid(i,j-2));
	}
	// for(int i=1;i<=n*m;i++) for(int j:G[i]) printf("%d %d\n",i,j);
	for(int i=1;i<=n*m;i++) sort(G[i].begin(),G[i].end());
	for(int i=1;i<=n*m;i++) for(int j:G[i]) dgr[j]++;
	for(int i=1;i<=n*m;i++) if(!dgr[i]) dfs(i);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		if(s[i][j]=='U')
		{
			int u=getid(i,j),v=getid(i+1,j);
			if((i+j)&1) swap(u,v);
			q[++cnt]=(Query){1,dfn[u],dfn[v],dfn[v]+siz[v]-1};
			q[++cnt]=(Query){-1,dfn[u]+siz[u],dfn[v],dfn[v]+siz[v]-1};
		}
		if(s[i][j]=='L')
		{
			int u=getid(i,j),v=getid(i,j+1);
			if((i+j)&1) swap(u,v);
			q[++cnt]=(Query){1,dfn[u],dfn[v],dfn[v]+siz[v]-1};
			q[++cnt]=(Query){-1,dfn[u]+siz[u],dfn[v],dfn[v]+siz[v]-1};
		}
	}
	sort(q+1,q+cnt+1,cmp);
	// for(int i=1;i<=cnt;i++) printf("%d %d %d %d\n",q[i].opt,q[i].pos,q[i].l,q[i].r);
	// return 0;
	int cur=1; ll ans=0;
	for(int i=1;i<=n*m;i++)
	{
		while(cur<=cnt&&q[cur].pos==i) smt.update(1,1,n*m,q[cur].l,q[cur].r,q[cur].opt),cur++;
		ans+=smt.qry();
	}
	cout<<ans<<endl;
	return 0;
}