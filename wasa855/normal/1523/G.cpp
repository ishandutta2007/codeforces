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
inline int lowbit(int x) {return x&(-x);}
#define N 100005
int rt[N],ans[N],len[N],n,m;
int l[N],r[N];
struct Node{int l,r,t;};
Node a[N];
struct SMT
{
	int ls[N*300],rs[N*300],t[N*300],cnt;
	int New() {t[++cnt]=inf; return cnt;}
	void init(int n) {for(int i=1;i<=n;i++) rt[i]=New();}
	#define mid ((l+r)/2)
	void update(int &u,int l,int r,int pos,int v)
	{
		if(!u) u=New();
		t[u]=min(t[u],v);
		if(l==r) return ;
		if(pos<=mid) update(ls[u],l,mid,pos,v);
		else update(rs[u],mid+1,r,pos,v);
	}
	int query(int u,int l,int r,int L,int R)
	{
		if(!u) return inf;
		if(L<=l&&r<=R) return t[u];
		int ans=inf;
		if(mid>=L) ans=min(ans,query(ls[u],l,mid,L,R));
		if(mid<R) ans=min(ans,query(rs[u],mid+1,r,L,R));
		return ans;
	}
	#undef mid
}smt;
void ins(int l,int r,int t)
{
	for(int i=r;i<=n;i+=lowbit(i)) smt.update(rt[i],1,n,l,t);
}
int query(int l,int r)
{
	int ans=inf;
	for(int i=r;i>=1;i-=lowbit(i)) ans=min(ans,smt.query(rt[i],1,n,l,r));
	return ans;
}
int _ans=0;
void solve(int l,int r)
{
	if(l>r) return ;
	int res=query(l,r);
	if(res==inf) return ;
	_ans+=len[res];
	// printf("%d %d - %d ^ %d\n",l,r,res,_ans);
	solve(l,::l[res]-1),solve(::r[res]+1,r);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) a[i].l=read(),a[i].r=read(),a[i].t=i,len[i]=a[i].r-a[i].l+1,l[i]=a[i].l,r[i]=a[i].r;
	sort(a+1,a+m+1,[&](Node x,Node y){return x.r-x.l>y.r-y.l;});
	int cur=1;
	for(int i=n;i>=1;i--)
	{
		while(cur<=m&&a[cur].r-a[cur].l+1==i) ins(a[cur].l,a[cur].r,a[cur].t),cur++;
		// printf("--- %d\n",i);
		_ans=0,solve(1,n);
		ans[i]=_ans;
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}