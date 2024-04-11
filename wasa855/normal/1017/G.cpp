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
#define N 100005
struct Node{int sum,val;};
Node merge(Node x,Node y)
{
	int s=x.sum+y.sum,v=max(y.val,x.val+y.sum);
	return (Node){s,v};
}
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	Node t[N*4]; int tag[N*4];
	void fix(int u,int l,int r) {tag[u]=1,t[u]=(Node){-(r-l+1),-(r-l+1)};}
	void pushdown(int u,int l,int r)
	{
		if(!tag[u]) return ;
		fix(ls,l,mid),fix(rs,mid+1,r);
		tag[u]=0;
	}
	void updrange(int u,int l,int r,int L,int R)
	{
		if(L>R) return ;
		if(L<=l&&r<=R) return fix(u,l,r);
		pushdown(u,l,r);
		if(mid>=L) updrange(ls,l,mid,L,R);
		if(mid<R) updrange(rs,mid+1,r,L,R);
		t[u]=merge(t[ls],t[rs]);
	}
	void update(int u,int l,int r,int pos,int v)
	{
		if(l==r)
		{
			t[u]=(Node){v,v};
			return ;
		}
		pushdown(u,l,r);
		if(pos<=mid) update(ls,l,mid,pos,v);
		else update(rs,mid+1,r,pos,v);
		t[u]=merge(t[ls],t[rs]);
	}
	void updnode(int u,int l,int r,int pos)
	{
		if(l==r)
		{
			t[u].sum++,t[u].val++;
			// printf("^ %d %d - %d\n",u,pos,t[u].val);
			return ;
		}
		pushdown(u,l,r);
		if(pos<=mid) updnode(ls,l,mid,pos);
		else updnode(rs,mid+1,r,pos);
		t[u]=merge(t[ls],t[rs]);
		// printf("* %d %d %d - %d %d\n",u,l,r,t[u].sum,t[u].val);
	}
	Node query(int u,int l,int r,int L,int R)
	{
		// printf("^ %d %d %d - %d %d * %d %d\n",u,l,r,L,R,t[u].sum,t[u].val);
		if(L<=l&&r<=R) return t[u];
		pushdown(u,l,r);
		if(mid>=L&&mid<R) return merge(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
		else if(mid>=L) return query(ls,l,mid,L,R);
		else return query(rs,mid+1,r,L,R);
	}
	#undef mid
}smt;
vector<int> G[N];
int fa[N],dep[N],siz[N],son[N],top[N],dfn[N],dfscnt,n,Q;
void dfs1(int u,int f)
{
	dep[u]=dep[f]+1,siz[u]=1;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs1(v,u),siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp,dfn[u]=++dfscnt;
	if(!son[u]) return ;
	dfs2(son[u],tp);
	for(int v:G[u])
	{
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
Node qry(int x)
{
	Node ans=(Node){0,-inf};
	// printf("^ %d",x);
	while(x)
	{
		Node res=smt.query(1,1,n,dfn[top[x]],dfn[x]);
		ans=merge(res,ans),x=fa[top[x]];
	}
	// printf(" - %d %d\n",ans.sum,ans.val);
	return ans;
}
signed main()
{
	cin>>n>>Q;
	for(int i=2;i<=n;i++) fa[i]=read(),G[fa[i]].pb(i);
	dfs1(1,0),dfs2(1,1);
	smt.fix(1,1,n);
	while(Q--)
	{
		int op=read(),x=read();
		if(op==1) smt.updnode(1,1,n,dfn[x]);
		else if(op==2)
		{
			if(x==1) smt.fix(1,1,n);
			else
			{
				Node r=qry(fa[x]);
				smt.updrange(1,1,n,dfn[x],dfn[x]+siz[x]-1);
				if(r.val>=0) smt.update(1,1,n,dfn[x],-r.val-1);
			}
		}
		else
		{
			Node r=qry(x);
			if(r.val>=0) printf("black\n");
			else printf("white\n");
		}
	}
	return 0;
}