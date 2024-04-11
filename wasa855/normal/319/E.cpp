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
struct Opt
{
	int op,x,y;
};
Opt q[N];
int t[N],n,m,cnt;
int fa[N],l[N],r[N];
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
int L[N],R[N];
void merge(int u,int v)
{
	// printf("^ %d %d\n",u,v);
	u=find(u),v=find(v);
	if(u==v) return ;
	fa[u]=v,L[v]=min(L[u],L[v]),R[v]=max(R[u],R[v]);
}
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	vector<int> t[N*4];
	void query(int u,int l,int r,int pos,int id)
	{
		for(int i:t[u]) merge(i,id);
		if(l==r) return ;
		if(!t[u].empty()) t[u].resize(1);
		if(pos<=mid) query(ls,l,mid,pos,id);
		else query(rs,mid+1,r,pos,id);
	}
	void insert(int u,int l,int r,int L,int R,int id)
	{
		if(L>R) return ;
		if(L<=l&&r<=R)
		{
			// printf("** %d %d %d %d\n",u,l,r,id);
			t[u].pb(id);
			return ;
		}
		if(mid>=L) insert(ls,l,mid,L,R,id);
		if(mid<R) insert(rs,mid+1,r,L,R,id);
	}
}smt;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		q[i].op=read(),q[i].x=read(),q[i].y=read();
		if(q[i].op==1) t[++m]=q[i].x,t[++m]=q[i].y;
		if(q[i].op==1) t[++m]=q[i].x+1,t[++m]=q[i].y-1;
	}
	sort(t+1,t+m+1), m=unique(t+1,t+m+1)-t-1;
	for(int i=1;i<=n;i++) if(q[i].op==1) q[i].x=lower_bound(t+1,t+m+1,q[i].x)-t,q[i].y=lower_bound(t+1,t+m+1,q[i].y)-t;
	// for(int i=1;i<=n;i++) printf("%d %d\n",q[i].x,q[i].y);
	for(int i=1;i<=n;i++) fa[i]=i;
	int cur=0; cnt=n;
	for(int i=1;i<=n;i++)
	{
		if(q[i].op==1)
		{
			cur++,L[cur]=l[cur]=q[i].x,R[cur]=r[cur]=q[i].y;
			smt.query(1,1,m,q[i].x,cur);
			smt.query(1,1,m,q[i].y,cur);
			smt.insert(1,1,m,q[i].x+1,q[i].y-1,find(cur));
		}
		else
		{
			int u=find(q[i].x),v=find(q[i].y);
			if(u==v) puts("YES");
			else if((L[v]<L[u]&&L[u]<R[v])||(L[v]<R[u]&&R[u]<R[v])) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}