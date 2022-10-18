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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 200005
int n,Q;
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int t[N*4],tag[N*4];
	void upd(int u,int l,int r,int v) {tag[u]+=v,t[u]+=v*(r-l+1);}
	void pushdown(int u,int l,int r) {upd(ls,l,mid,tag[u]),upd(rs,mid+1,r,tag[u]),tag[u]=0;}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L>R) return ;
		// if(l==1&&r==n) printf("^ %d %d %d\n",L,R,v);
		if(L<=l&&r<=R) return upd(u,l,r,v);
		pushdown(u,l,r);
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
		t[u]=t[ls]+t[rs];
	}
	int query(int u,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return t[u];
		pushdown(u,l,r); int ans=0;
		if(mid>=L) ans+=query(ls,l,mid,L,R);
		if(mid<R) ans+=query(rs,mid+1,r,L,R);
		return ans;
	}
}smt;
struct Driver
{
	int mx[N*4],sec[N*4],cnt[N*4],tag[N*4];
	void pushup(int u)
	{
		if(mx[ls]==mx[rs])
		{
			mx[u]=mx[ls],sec[u]=max(sec[ls],sec[rs]);
			cnt[u]=cnt[ls]+cnt[rs];
		}
		else if(mx[ls]>mx[rs])
		{
			mx[u]=mx[ls],sec[u]=max(mx[rs],sec[ls]);
			cnt[u]=cnt[ls];
		}
		else
		{
			mx[u]=mx[rs],sec[u]=max(mx[ls],sec[rs]);
			cnt[u]=cnt[rs];
		}
	}
	void upd(int u,int v)
	{
		if(v<mx[u]) mx[u]=v,tag[u]=v;
	}
	void pushdown(int u)
	{
		if(tag[u]==inf) return ;
		upd(ls,tag[u]),upd(rs,tag[u]);
		tag[u]=inf;
	}
	void build(int u,int l,int r)
	{
		tag[u]=inf;
		if(l==r) {mx[u]=l,cnt[u]=1; return ;}
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L>R||v>=mx[u]) return ;
		if(L<=l&&r<=R&&v>sec[u])
		{
			smt.update(1,1,n,v+1,mx[u],-cnt[u]);
			upd(u,v); return ;
		}
		pushdown(u);
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
		pushup(u);
	}
	void fix(int u,int l,int r,int pos,int v)
	{
		if(l==r)
		{
			if(v>mx[u]) smt.update(1,1,n,mx[u]+1,v,1);
			else smt.update(1,1,n,v+1,mx[u],-1);
			mx[u]=v; return ;
		}
		pushdown(u);
		if(pos<=mid) fix(ls,l,mid,pos,v);
		else fix(rs,mid+1,r,pos,v);
		pushup(u);
	}
	#undef mid
}smt2;
signed main()
{
	cin>>n>>Q;
	smt2.build(1,1,n);
	smt.update(1,1,n,1,n,1);
	while(Q--)
	{
		int op=read();
		if(op==1)
		{
			int p=read(),v=read();
			smt2.fix(1,1,n,p,v);
			smt2.update(1,1,n,1,p-1,p-1);
		}
		else
		{
			int l=read(),r=read();
			printf("%lld\n",smt.query(1,1,n,l,r));
		}
		// cout<<"--\n";
	}
	return 0;
}