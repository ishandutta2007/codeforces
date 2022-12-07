#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define fi first
#define se second
#define PB push_back
#define uint unsigned
#define int long long
using namespace std;
const int M=5000005;
const int N=100005;
struct edge{
	int to,next,v,id;
}e[N*2];
int head[N],tot,n,Q,wmx;
void add(int x,int y,int v,int id){
	e[++tot]=(edge){y,head[x],v,id};
	head[x]=tot;
}
int vis[N],sz[N];
int mxv,mxrt;
void dfs(int x,int fa,int n){
	sz[x]=1; int mx=0;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]&&e[i].to!=fa){
			dfs(e[i].to,x,n);
			sz[x]+=sz[e[i].to];
			mx=max(mx,sz[e[i].to]);
		}
	mx=max(mx,n-sz[x]);
	if (mx<mxv) mxv=mx,mxrt=x;
}
struct info{
	int id,dfn,ed;
};
int dfn[N],pos[N],V[N];
int ed[N],col[N],cnt[N];
vector<info> vec[N];
ll dep[N];
void get_d(int x,int fa,int bel,int rt,int fae){
	dfn[x]=++*dfn;
	pos[*dfn]=x;
	col[x]=bel;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			dep[e[i].to]=dep[x]+e[i].v;
			get_d(e[i].to,x,bel,rt,e[i].id);
		}
	ed[x]=*dfn;
	vec[fae].PB((info){rt,dfn[x],ed[x]});
}
ll tg[M];
pll mn1[M],mn2[M];
int ls[M],rs[M];
int rt[N],nd;
void pushup(int k){
	mn1[k]=mn1[ls[k]];
	mn2[k]=mn2[ls[k]];
	pll tmp=mn1[rs[k]];
	if (tmp>mn1[k]) swap(mn1[k],tmp);
	if (tmp.se!=mn1[k].se&&tmp>mn2[k]) swap(mn2[k],tmp);
	tmp=mn2[rs[k]];
	if (tmp.se!=mn1[k].se&&tmp>mn2[k]) swap(mn2[k],tmp);
}
void addi(int k,int v){
	mn1[k].fi+=v;
	if (mn2[k].se!=-1)
		mn2[k].fi+=v;
	tg[k]+=v;
}
void pushdown(int k){
	if (!tg[k]) return;
	addi(ls[k],tg[k]);
	addi(rs[k],tg[k]);
	tg[k]=0;
}
void build(int &k,int l,int r){
	k=++nd;
	if (l==r){
		mn1[k]=pll(dep[pos[l]],col[pos[l]]);
		mn2[k]=pll(0,-1);
		return;
	}
	int mid=(l+r)/2;
	build(ls[k],l,mid);
	build(rs[k],mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int x,int y,int v){
	//printf("%d %d %d %d %d %d\n",k,l,r,x,y,v);
	if (l==x&&r==y)
		return addi(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(ls[k],l,mid,x,y,v);
	else if (x>mid) change(rs[k],mid+1,r,x,y,v);
	else{
		change(ls[k],l,mid,x,mid,v);
		change(rs[k],mid+1,r,mid+1,y,v);
	}
	pushup(k);
}
set<pll> S;
void build_tree(int x){
	dfn[0]=1; dfn[x]=1; pos[1]=x;
	col[x]=0; dep[x]=0;
	for (int i=head[x];i;i=e[i].next)
	 	if (!vis[e[i].to]){
	 		dep[e[i].to]=dep[x]+e[i].v;
	 		get_d(e[i].to,x,e[i].to,x,e[i].id);
	 	}
	 build(rt[x],1,*dfn);
	 S.insert(pll(-mn1[rt[x]].fi-mn2[rt[x]].fi,x));
	 cnt[x]=*dfn;
}
void divide(int x,int n){
	if (n==1) return;
	mxv=1<<30;
	dfs(x,0,n);
	vis[x=mxrt]=1;
	build_tree(x);
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to])
			divide(e[i].to,sz[e[i].to]>sz[x]?n-sz[x]:sz[e[i].to]);
}
void change(info x,int v){
	int id=x.id;
	S.erase(pll(-mn1[rt[id]].fi-mn2[rt[id]].fi,id));
	change(rt[id],1,cnt[id],x.dfn,x.ed,v);
	S.insert(pll(-mn1[rt[id]].fi-mn2[rt[id]].fi,id));
}
signed main(){
	scanf("%lld%lld%lld",&n,&Q,&wmx);
	For(i,1,n-1){
		int x,y,v;
		scanf("%lld%lld%lld",&x,&y,&v);
		add(x,y,v,i);
		add(y,x,v,i);
		V[i]=v;
	}
	divide(1,n);
	int las=0;
	while (Q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		x=(x+las)%(n-1)+1;
		y=(y+las)%wmx;
		//printf("%d %d %d\n",x,V[x],y);
		int del=y-V[x]; V[x]=y;
		For(i,0,vec[x].size()-1)
			change(vec[x][i],del);
		printf("%lld\n",las=-(S.begin()->fi));
	}
}