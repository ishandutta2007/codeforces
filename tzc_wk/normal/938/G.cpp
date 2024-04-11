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
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
const int MAXB=30;
const int TOT=(1<<30)-1;
int n,m,qu,eid,pret[MAXN*2+5];
struct edge{int u,v,w;} e[MAXN*2+5];
pii qry[MAXN+5];map<int,int> ed[MAXN+5];
struct node{int l,r;vector<int> v;} s[MAXN*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r){s[k].v.pb(x);return;}
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
}
struct lbase{
	int a[MAXB+5];
	void init(){memset(a,0,sizeof(a));}
	lbae(){init();}
	void ins(int x){
		for(int i=MAXB;~i;i--) if(x>>i&1){
			if(!a[i]){a[i]=x;return;}
			else x^=a[i];
		}
	}
	int query(int x){
		for(int i=MAXB;~i;i--) if((x^a[i])>x) x^=a[i];
		return x;
	}
} cur;
int fa[MAXN+5],w[MAXN+5],dep[MAXN+5];stack<pair<pii,int> > stk;
int find(int x){return (!fa[x])?x:find(fa[x]);}
int getw(int x){return (!fa[x])?0:getw(fa[x])^w[x];}
void merge(int x,int y,int z){
	if(find(x)==find(y)){
		cur.ins(getw(x)^getw(y)^z);
		return;
	} z^=getw(x)^getw(y);x=find(x);y=find(y);
	if(dep[x]<dep[y]) x^=y^=x^=y;
	stk.push(mp(mp(x,y),(dep[x]==dep[y])));
	fa[y]=x;w[y]=z;dep[x]+=(dep[x]==dep[y]);
}
void undo(){
	pair<pii,int> p=stk.top();stk.pop();
	int x=p.fi.fi,y=p.fi.se,is=p.se;
	fa[y]=0;w[y]=0;dep[x]-=is;
}
void iterate(int k){
	int tmp=stk.size();lbase tmpl=cur;
	for(int i=0;i<s[k].v.size();i++){
		int id=s[k].v[i];
		merge(e[id].u,e[id].v,e[id].w);
	}
	if(s[k].l==s[k].r){
		if(qry[s[k].l].fi)
			printf("%d\n",TOT^cur.query(TOT^
			getw(qry[s[k].l].fi)^getw(qry[s[k].l].se)));
	} else iterate(k<<1),iterate(k<<1|1);
	cur=tmpl;while(stk.size()>tmp) undo();
}
int main(){
	scanf("%d%d",&n,&m);eid=m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		ed[e[i].u][e[i].v]=ed[e[i].v][e[i].u]=i;
	} scanf("%d",&qu);build(1,0,qu);
	for(int i=1;i<=qu;i++){
		int opt;scanf("%d",&opt);
		if(opt==1){
			eid++;scanf("%d%d%d",&e[eid].u,&e[eid].v,&e[eid].w);
			pret[eid]=i;ed[e[eid].u][e[eid].v]=ed[e[eid].v][e[eid].u]=eid;
		} else if(opt==2){
			int x,y,id;scanf("%d%d",&x,&y);id=ed[x][y];
			modify(1,pret[id],i-1,id);pret[id]=-1;
		} else{
			scanf("%d%d",&qry[i].fi,&qry[i].se);
		}
	}
	for(int i=1;i<=eid;i++) if(~pret[i]) modify(1,pret[i],qu,i);
	iterate(1);
	return 0;
}