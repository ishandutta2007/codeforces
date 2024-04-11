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
int a[N],rev[N],n,Q,m;
struct Node{int p,v;};
Node min(Node x,Node y) {return x.v<y.v?x:y;}
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int tag[N*4];
	Node t[N*4];
	void upd(int u,int v) {tag[u]+=v,t[u].v+=v;}
	void pushup(int u) {t[u]=min(t[ls],t[rs]);}
	void build(int u,int l,int r)
	{
		if(l==r) {t[u].p=l; return ;}
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
	void pushdown(int u)
	{
		upd(ls,tag[u]),upd(rs,tag[u]);
		tag[u]=0;
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		// if(u==1) printf("upd : %d %d %d\n",L,R,v);
		if(L<=l&&r<=R) return upd(u,v);
		pushdown(u);
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
		pushup(u);
		// printf("%d %d : %d %d\n",l,r,t[u].p,t[u].v);
	}
	Node query(int u,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			// printf("qry %d %d %d %d : %d %d\n",l,r,L,R,t[u].p,t[u].v);
			return t[u];
		}
		pushdown(u);
		Node ans={0,inf};
		if(mid>=L) ans=min(ans,query(ls,l,mid,L,R));
		if(mid<R) ans=min(ans,query(rs,mid+1,r,L,R));
		// printf("qry %d %d %d %d : %d %d\n",l,r,L,R,ans.p,ans.v);
		return ans;
	}
}smt;
int sgn(int x) {return x<=n?-1:(x==n+1?0:1);}
int sL,sR,pos[N];
void del(int p)
{
	smt.update(1,1,m*2,p,m*2,-sgn(a[p]));
	smt.update(1,1,m*2,p+m,m*2,-sgn(a[p]));
}
void ins(int p)
{
	smt.update(1,1,m*2,p,m*2,sgn(a[p]));
	smt.update(1,1,m*2,p+m,m*2,sgn(a[p]));
}
int Mod(int x,int y) {return ((x%y)+y)%y;}
int dis(int x,int y)
{
	if(x>y) swap(x,y);
	return Mod(rev[y]-rev[x],m);
}
int getpos(int x)
{
	if(x==n+1) return 0;
	if(x<=n) return Mod(rev[n+1]-rev[x],m);
	else return Mod(rev[x]-rev[n+1],m);
}
int inq[N];
void link(int u)
{
	if(u==0) return ;
	if(inq[u]) return ;
	inq[u]=1;
	if(u<=n) sR+=dis(u,u+1);
	else if(u<m) sL+=dis(u,u+1);
}
void cut(int u)
{
	if(u==0) return ;
	if(!inq[u]) return ;
	inq[u]=0;
	if(u<=n) sR-=dis(u,u+1);
	else if(u<m) sL-=dis(u,u+1);
}
signed main()
{
	cin>>n>>Q; m=n*2+1;
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=m;i++) rev[a[i]]=i;
	smt.build(1,1,m*2);
	for(int i=1;i<=m;i++) ins(i);
	for(int i=1;i<=m;i++) pos[i]=getpos(i);
	// for(int i=1;i<=m;i++) printf("%d%c",::pos[i]," \n"[i==m]);
	for(int i=1;i<m;i++) link(i);
	while(Q--)
	{
		int x=read(),y=read();
		del(x),del(y);
		// printf("- %d\n",sL);
		cut(a[x]),cut(a[x]-1),cut(a[y]),cut(a[y]-1);
		// printf("* %d\n",sL);
		swap(a[x],a[y]),swap(rev[a[x]],rev[a[y]]);
		ins(x),ins(y);
		// pos[a[x]]=getpos(a[x]),pos[a[y]]=getpos(a[y]);
		link(a[x]),link(a[x]-1),link(a[y]),link(a[y]-1);
		// for(int i=1;i<=m;i++) printf("%d%c",a[i]," \n"[i==m]);
		int pos=rev[n+1];
		{
			// auto [_p3,C]=smt.query(1,1,m*2,7,7);
			// printf("*** %d %d\n",_p3,C);
			auto [_p1,A]=smt.query(1,1,m*2,pos,pos);
			auto [_p2,B]=smt.query(1,1,m*2,pos,pos+m-1);
			// printf("%d %d - %d %d\n",_p1,A,_p2,B);
			if(B<A)
			{
				auto [p,v]=smt.query(1,1,m*2,1,m);
				// printf("*** %d %d\n",p,v);
				printf("%d\n",p%m);
				continue;
			}
		}
		// for(int i=1;i<=m;i++) printf("%d%c",::pos[i]," \n"[i==m]);
		// printf("%d %d\n",sR,dis(1,n+1));
		if(sL!=dis(n+1,m)) {printf("%d\n",pos-1); continue;}
		if(sR!=dis(1,n+1)) {printf("%d\n",pos%m); continue;}
		printf("-1\n");
	}
	return 0;
}