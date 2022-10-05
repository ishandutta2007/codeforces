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
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
const int MAXM=3e5;
const int MAXQ=5e5;
const int LOG_N=19;
int n,m,qu,p[MAXN+5],val[MAXN*2+5];
struct qry{int opt,x;} q[MAXQ+5];
struct edge{
	int u,v,t;
	bool operator <(const edge &rhs){return t>rhs.t;}
} e[MAXM+5];
int f[MAXN*2+5],nc,hd[MAXN*2+5],nxt[MAXN*2+5],to[MAXN*2+5],ec=0;
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int fa[MAXN*2+5][LOG_N+2],bgt[MAXN*2+5],edt[MAXN*2+5],rid[MAXN*2+5],tim=0;
void dfs(int x,int f){
	fa[x][0]=f;rid[bgt[x]=++tim]=x;
	for(int e=hd[x];e;e=nxt[e]) dfs(to[e],x);
	edt[x]=tim;
}
struct node{int l,r;pii val;} s[MAXN*8+5];
pii merge(pii x,pii y){
	pii ret;ret.fi=max(x.fi,y.fi);
	if(ret.fi==x.fi) ret.se=x.se;
	if(ret.fi==y.fi) ret.se=y.se;
	return ret;
}
void pushup(int k){s[k].val=merge(s[k<<1].val,s[k<<1|1].val);}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return s[k].val.fi=-1,s[k].val.se=l,void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void modify(int k,int x,int v){
	if(s[k].l==s[k].r) return s[k].val.fi=v,void();int mid=s[k].l+s[k].r>>1;
	(x<=mid)?modify(k<<1,x,v):modify(k<<1|1,x,v);pushup(k);
}
pii query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].val;int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);else if(l>mid) return query(k<<1|1,l,r);
	else return merge(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
}
int main(){
	scanf("%d%d%d",&n,&m,&qu);for(int i=1;i<=n;i++) scanf("%d",&p[i]);nc=n;
	for(int i=1;i<=m;i++) scanf("%d%d",&e[i].u,&e[i].v),e[i].t=qu+1;
	for(int i=1;i<=qu;i++){
		scanf("%d%d",&q[i].opt,&q[i].x);
		if(q[i].opt==2) e[q[i].x].t=i;
	} sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int fu=find(e[i].u),fv=find(e[i].v);if(fu==fv) continue;++nc;
		adde(nc,fu);adde(nc,fv);f[nc]=f[fu]=f[fv]=nc;val[nc]=e[i].t;
	} ++nc;for(int i=1;i<nc;i++) if(find(i)==i) adde(nc,i);
	dfs(nc,0);for(int i=1;i<=LOG_N;i++) for(int j=1;j<=nc;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	build(1,1,nc);for(int i=1;i<=n;i++) modify(1,bgt[i],p[i]);
	for(int i=1;i<=qu;i++) if(q[i].opt==1){
		int cur=q[i].x;
		for(int j=LOG_N;~j;j--){
			if(!fa[cur][j]) continue;
			if(val[fa[cur][j]]>i) cur=fa[cur][j];
		} pii p=query(1,bgt[cur],edt[cur]);
		printf("%d\n",p.fi);modify(1,p.se,0);
	}
	return 0;
}