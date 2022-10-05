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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
const int LOG_N=18;
const int INF=0x3f3f3f3f;
int n,m,qu,qn,hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int siz[MAXN+5],wson[MAXN+5],dep[MAXN+5],fa[MAXN+5][LOG_N+2];
int top[MAXN+5],dfn[MAXN+5],tim=0,edt[MAXN+5];
void dfs1(int x){
	siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dep[y]=dep[x]+1;
		dfs1(y);siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]]) wson[x]=y;
	}
}
void dfs2(int x,int tp){
	top[x]=tp;dfn[x]=++tim;if(wson[x]) dfs2(wson[x],tp);
	for(int e=hd[x];e;e=nxt[e]) if(to[e]!=fa[x][0]&&to[e]!=wson[x])
		dfs2(to[e],to[e]);
	edt[x]=tim;
}
int getlca(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]][0];
	} if(dep[x]<dep[y]) swap(x,y);
	return y;
}
struct node{int l,r,val,lz;} s[MAXN*4+5];
void pushup(int k){s[k].val=min(s[k<<1].val,s[k<<1|1].val);}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].lz=INF;if(l==r) return s[k].val=INF,void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void pushdown(int k){
	if(s[k].lz!=INF){
		chkmin(s[k<<1].val,s[k].lz);chkmin(s[k<<1|1].val,s[k].lz);
		chkmin(s[k<<1].lz,s[k].lz);chkmin(s[k<<1|1].lz,s[k].lz);
		s[k].lz=INF;
	}
}
void modify(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r){
		chkmin(s[k].val,x);chkmin(s[k].lz,x);
		return;
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	pushup(k);
}
int query(int k,int x){
	if(s[k].l==s[k].r) return s[k].val;pushdown(k);
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(x<=mid) return query(k<<1,x);
	else return query(k<<1|1,x);
}
void jumpath(int x,int y,int v){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		modify(1,dfn[top[x]],dfn[x],v);
		x=fa[top[x]][0];
	} if(dep[x]<dep[y]) swap(x,y);
	modify(1,dfn[y],dfn[x],v);
}
int get_kanc(int x,int k){
	for(int i=LOG_N;~i;i--) if(k>>i&1) x=fa[x][i];
	return x;
}
int nt[MAXN+5][LOG_N+2],cnt[MAXN+5],ans[MAXN+5],mark[MAXN+5];
int step(int x,int d){
	if(dep[x]<=d) return 0;
	if(dep[nt[x][LOG_N]]>d) return -1;int cnt=0;
	for(int i=LOG_N;~i;i--) if(dep[nt[x][i]]>d) x=nt[x][i],cnt|=(1<<i);
	return cnt+(dep[x]>d);
}
int get_kstp(int x,int k){
	for(int i=LOG_N;~i;i--) if(k>>i&1) x=nt[x][i];
	return x;
}
vector<int> pts[MAXN+5];
struct qry{
	int x,y,t,id;
	bool operator <(const qry &rhs) const{
		return x<rhs.x;
	}
} q[MAXN*4+5];
void add_rec(int x1,int x2,int y1,int y2,int id){
//	printf("%d %d %d %d %d\n",x1,x2,y1,y2,id);
	q[++qn]={x2,y2,1,id};q[++qn]={x1-1,y2,-1,id};
	q[++qn]={x2,y1-1,-1,id};q[++qn]={x1-1,y1-1,1,id};
}
struct fenwick{
	int t[MAXN+5];
	void add(int x,int v){for(int i=x;i<=n;i+=(i&(-i))) t[i]+=v;}
	int query(int x){int ret=0;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
} tr;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++) scanf("%d",&fa[i][0]),adde(fa[i][0],i);
	dfs1(1);dfs2(1,1);build(1,1,n);
	for(int i=1;i<=n;i++) modify(1,dfn[i],dfn[i],dep[i]);
	scanf("%d",&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		pts[dfn[x]].pb(dfn[y]);pts[dfn[y]].pb(dfn[x]);
//		printf("(%d %d)\n",dfn[x],dfn[y]);
		jumpath(x,y,dep[getlca(x,y)]);
	}
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	for(int i=1;i<=n;i++) nt[i][0]=get_kanc(i,dep[i]-query(1,dfn[i]));
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++) nt[j][i]=nt[nt[j][i-1]][i-1];
	scanf("%d",&qu);
	for(int i=1;i<=qu;i++){
		int x,y,l;scanf("%d%d",&x,&y);l=getlca(x,y);
		int sx=step(x,dep[l]),sy=step(y,dep[l]);
		if(!~sx||!~sy) ans[i]=-1;
		else{
			ans[i]=sx+sy;
			if(sx!=0&&sy!=0){
				int ax=get_kstp(x,sx-1);
				int ay=get_kstp(y,sy-1);
				add_rec(dfn[ax],edt[ax],dfn[ay],edt[ay],i);
			}
		}
	}
//	for(int i=1;i<=qu;i++) printf("%d\n",ans[i]);
	sort(q+1,q+qn+1);int cur=1;
	for(int i=1;i<=qn;i++){
		while(cur<=q[i].x){
			for(int y:pts[cur]) tr.add(y,1);
			cur++;
		} cnt[q[i].id]+=q[i].t*tr.query(q[i].y);
//		printf("%d %d %d\n",q[i].x,q[i].y,tr.query(q[i].y));
	}
	for(int i=1;i<=qu;i++) printf("%d\n",ans[i]-(cnt[i]>0));
	return 0;
}