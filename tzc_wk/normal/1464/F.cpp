#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
const int LOG_N=19;
int n,qu,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dfn_eu[MAXN+5],tim_eu=0,dep[MAXN+5],dfn[MAXN+5],ed[MAXN+5],tim=0;
int fa[MAXN+5][LOG_N+2];
pii st[MAXN*2+5][LOG_N+2];
void dfs(int x,int f){
	fa[x][0]=f;dfn[x]=++tim;
	st[dfn_eu[x]=++tim_eu][0]=mp(dep[x],x);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x);
		st[dfn_eu[x]=++tim_eu][0]=mp(dep[x],x);
	} ed[x]=tim;
}
pii query_st(int l,int r){
	int k=31-__builtin_clz(r-l+1);
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int getlca(int x,int y){
	x=dfn_eu[x];y=dfn_eu[y];if(x>y) swap(x,y);
	return query_st(x,y).se;
}
int get_kanc(int x,int k){
	for(int i=LOG_N;~i;i--) if(k>>i&1) x=fa[x][i];
	return max(x,1);
}
int getdist(int x,int y){return dep[x]+dep[y]-(dep[getlca(x,y)]<<1);}
void st_init(){
	dfs(1,0);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n*2;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
}
struct fenwick_tree{
	int t[MAXN+5];
	void add(int x,int v){for(int i=x;i<=n;i+=(i&(-i))) t[i]+=v;}
	int query(int x){int ret=0;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
	int query_range(int l,int r){return query(r)-query(l-1);}
} t;
int cnt_pth=0;
int qry_sub(int x){return t.query_range(dfn[x],ed[x]);}
void add_pth(int u,int v,int x){
	t.add(dfn[u],x);t.add(dfn[v],x);
	t.add(dfn[getlca(u,v)],-x);
}
multiset<pii> lca;
struct dat{
	int u,v;
	dat(int _u=0,int _v=0):u(_u),v(_v){}
	dat operator +(const dat &rhs){
		if(!u) return rhs;
		if(!rhs.u) return *this;
		vector<pair<int,pii> > dists;
		dists.pb(mp(getdist(u,rhs.u),mp(u,rhs.u)));
		dists.pb(mp(getdist(u,rhs.v),mp(u,rhs.v)));
		dists.pb(mp(getdist(v,rhs.u),mp(v,rhs.u)));
		dists.pb(mp(getdist(v,rhs.v),mp(v,rhs.v)));
		dists.pb(mp(getdist(u,v),mp(u,v)));
		dists.pb(mp(getdist(rhs.u,rhs.v),mp(rhs.u,rhs.v)));
		sort(dists.begin(),dists.end());
		return dat(dists[5].se.fi,dists[5].se.se);
	}
};
struct node{int l,r;dat v;} s[MAXN*4+5];
void pushup(int k){s[k].v=s[k<<1].v+s[k<<1|1].v;}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,int p,dat v){
	if(s[k].l==s[k].r) return s[k].v=v,void();
	int mid=s[k].l+s[k].r>>1;
	(p<=mid)?modify(k<<1,p,v):modify(k<<1|1,p,v);
	pushup(k);
}
dat query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].v;
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
int cnt[MAXN+5],pth_cnt=0;
void ins_pth(int u,int v){
	pth_cnt++;add_pth(u,v,1);int lc=getlca(u,v);
	cnt[lc]++;lca.insert(mp(dep[lc],lc));
	if(cnt[lc]==1) modify(1,dfn[lc],dat(lc,lc));
}
void del_pth(int u,int v){
	pth_cnt--;add_pth(u,v,-1);int lc=getlca(u,v);
	cnt[lc]--;lca.erase(lca.find(mp(dep[lc],lc)));
	if(cnt[lc]==0) modify(1,dfn[lc],dat(0,0));
}
bool check(int d){
	pii pp=*lca.rbegin();
	int u=get_kanc(pp.se,d),v=get_kanc(u,d);
	if(qry_sub(v)!=pth_cnt) return 0;
	dat dt=query(1,dfn[v],ed[v]);
	if(max(getdist(u,dt.u),getdist(u,dt.v))>d) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	st_init();build(1,1,n);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int u,v;scanf("%d%d",&u,&v);
			ins_pth(u,v);
		} else if(opt==2){
			int u,v;scanf("%d%d",&u,&v);
			del_pth(u,v);
		} else {
			int d;scanf("%d",&d);
			printf("%s\n",(check(d))?"Yes":"No");
		}
	}
	return 0;
}