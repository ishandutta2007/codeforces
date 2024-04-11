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
const int MAXN=5e5;
int n,qu;
struct solver{
	int bel[MAXN+5],siz[MAXN*2+5],tot;
	void init(){
		for(int i=1;i<=n;i++) bel[i]=i,siz[i]=1;
		tot=n;
	}
	int hd[MAXN*2+5],nxt[MAXN*2+5],to[MAXN*2+5],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
	void merge(int x,int y){
		tot++;adde(tot,bel[x]);adde(tot,bel[y]);
		siz[x]+=siz[y];siz[y]=0;bel[y]=0;bel[x]=tot;
	}
	int dfn[MAXN*2+5],sz[MAXN*2+5],tim=0;
	void dfs(int x){
		dfn[x]=++tim;sz[x]=1;
		for(int e=hd[x];e;e=nxt[e]) dfs(to[e]),sz[x]+=sz[to[e]];
	}
} s1,s2;
struct event{int opt,x,y;} q[MAXN+5];
vector<int> clr[MAXN+5];
ll res[MAXN+5];
struct seg1{
	struct node{int l,r;ll v,lz;} s[MAXN*8+5];
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;if(l==r) return;
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	}
	void pushdown(int k){
		if(s[k].lz){
			s[k<<1].v+=s[k].lz*(s[k<<1].r-s[k<<1].l+1);
			s[k<<1].lz+=s[k].lz;
			s[k<<1|1].v+=s[k].lz*(s[k<<1|1].r-s[k<<1|1].l+1);
			s[k<<1|1].lz+=s[k].lz;
			s[k].lz=0;
		}
	}
	void modify(int k,int l,int r,int x){
		if(l<=s[k].l&&s[k].r<=r){
			s[k].v+=1ll*x*(s[k].r-s[k].l+1);s[k].lz+=x;
			return;
		} pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(r<=mid) modify(k<<1,l,r,x);
		else if(l>mid) modify(k<<1|1,l,r,x);
		else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
		s[k].v=s[k<<1].v+s[k<<1|1].v;
	}
	ll query(int k,int x){
		if(s[k].l==s[k].r) return s[k].v;
		pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(x<=mid) return query(k<<1,x);
		else return query(k<<1|1,x);
	}
} st1;
struct seg2{
	struct node{int l,r,tag;} s[MAXN*8+5];
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;if(l==r) return;
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	}
	void pushdown(int k){
		if(s[k].tag){
			s[k<<1].tag=s[k].tag;s[k<<1|1].tag=s[k].tag;
			s[k].tag=0;
		}
	}
	void modify(int k,int l,int r,int x){
		if(l<=s[k].l&&s[k].r<=r){s[k].tag=x;return;}
		pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(r<=mid) modify(k<<1,l,r,x);
		else if(l>mid) modify(k<<1|1,l,r,x);
		else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	}
	int query(int k,int x){
		if(s[k].l==s[k].r) return s[k].tag;
		pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(x<=mid) return query(k<<1,x);
		else return query(k<<1|1,x);
	}
} st2;
int main(){
	scanf("%d%d",&n,&qu);s1.init();s2.init();
	for(int i=1;i<=qu;i++){
		char opt[5];scanf("%s",opt+1);
		if(opt[1]=='U'){
			int x,y;scanf("%d%d",&x,&y);s1.merge(x,y);
			q[i].opt=1;q[i].x=x;q[i].y=y;
		} else if(opt[1]=='M'){
			int x,y;scanf("%d%d",&x,&y);s2.merge(x,y);
			q[i].opt=2;q[i].x=x;q[i].y=y;
		} else if(opt[1]=='A'){
			int x;scanf("%d",&x);
			q[i].opt=3;q[i].x=s1.bel[x];q[i].y=s1.siz[x];
		} else if(opt[1]=='Z'){
			int x;scanf("%d",&x);
			q[i].opt=4;q[i].x=s2.bel[x];
		} else{
			int x;scanf("%d",&x);
			q[i].opt=5;q[i].x=x;
		}
	}
	s1.tot++;for(int i=1;i<=n;i++) if(s1.siz[i]) s1.adde(s1.tot,s1.bel[i]);
	s2.tot++;for(int i=1;i<=n;i++) if(s2.siz[i]) s2.adde(s2.tot,s2.bel[i]);
	s1.dfs(s1.tot);s2.dfs(s2.tot);
	st1.build(1,1,s1.tot);st2.build(1,1,s2.tot);
	for(int i=1;i<=qu;i++){
		if(q[i].opt==4) st2.modify(1,s2.dfn[q[i].x],s2.dfn[q[i].x]+s2.sz[q[i].x]-1,i);
		if(q[i].opt==5){
			int tmp=st2.query(1,s2.dfn[q[i].x]);
			if(tmp) clr[tmp].pb(i);
		}
	}
	for(int i=1;i<=qu;i++){
		if(q[i].opt==3) st1.modify(1,s1.dfn[q[i].x],s1.dfn[q[i].x]+s1.sz[q[i].x]-1,q[i].y);
		if(q[i].opt==4){
			for(int j=0;j<clr[i].size();j++){
				int id=clr[i][j];
				res[id]-=st1.query(1,s1.dfn[q[id].x]);
			}
		}
		if(q[i].opt==5){
			res[i]+=st1.query(1,s1.dfn[q[i].x]);
			printf("%lld\n",res[i]);
		}
	}
	return 0;
}