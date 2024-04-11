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
const int MAXN=1e5;
const int MAXV=2e6;
const int MAXE=1e7;
int n,m,ncnt;
struct graph{
	int hd[MAXV+5],nxt[MAXE+5],to[MAXE+5],ec=0;
	graph(){memset(hd,0,sizeof(hd));memset(nxt,0,sizeof(nxt));memset(to,0,sizeof(to));}
	void adde(int u,int v){/*eprintf("%d %d\n",u,v);*/to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
} g,t;
int fa[MAXN+5],siz[MAXN+5],dep[MAXN+5],wson[MAXN+5];
int dfn[MAXN+5],top[MAXN+5],tim=0;
void dfs1(int x=1,int f=0){
	fa[x]=f;siz[x]=1;
	for(int e=t.hd[x];e;e=t.nxt[e]){
		int y=t.to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs1(y,x);siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]]) wson[x]=y;
	}
}
void dfs2(int x=1,int tp=1){
	top[x]=tp;dfn[x]=++tim;if(wson[x]) dfs2(wson[x],tp);
	for(int e=t.hd[x];e;e=t.nxt[e]) if(t.to[e]!=wson[x]&&t.to[e]!=fa[x])
		dfs2(t.to[e],t.to[e]);
}
struct node{int l,r;vector<int> v;} s[MAXN*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
int in[MAXN*4+5],out[MAXN*4+5];
void connect(int k,int l,int r,int id){
	if(l<=s[k].l&&s[k].r<=r) return s[k].v.pb(id),void();
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) connect(k<<1,l,r,id);
	else if(l>mid) connect(k<<1|1,l,r,id);
	else connect(k<<1,l,mid,id),connect(k<<1|1,mid+1,r,id);
}
void jumpath(int id,int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]]) x^=y^=x^=y;
		connect(1,dfn[top[x]],dfn[x],id);x=fa[top[x]];
	} if(dep[x]<dep[y]) x^=y^=x^=y;
	if(x^y) connect(1,dfn[y]+1,dfn[x],id);
}
void iterate(int k){
	in[k]=++ncnt;out[k]=++ncnt;
	for(int i=0;i<s[k].v.size();i++){
		int id=s[k].v[i];
		if(id<=m) id+=m;else id-=m;
		if(i==0) g.adde(in[k],ncnt+i+1);
		else g.adde(ncnt+i,ncnt+i+1);
		g.adde(ncnt+i+1,id);
		if(i==(int)(s[k].v.size())-1) g.adde(out[k],ncnt+s[k].v.size()+i+1);
		else g.adde(ncnt+s[k].v.size()+i+2,ncnt+s[k].v.size()+i+1);
		g.adde(ncnt+s[k].v.size()+i+1,id);
	} int tmp=ncnt;ncnt+=s[k].v.size()<<1;
	if(s[k].l^s[k].r) iterate(k<<1),iterate(k<<1|1);
	for(int i=0;i<s[k].v.size();i++){
		int id=s[k].v[i];//printf("%d ",id);
		if(i) g.adde(id,tmp+s[k].v.size()+i);
		if(i!=(int)(s[k].v.size())-1) g.adde(id,tmp+i+2);
		if(k^1) g.adde(id,out[k>>1]);
		if(s[k].l^s[k].r) g.adde(id,in[k<<1]),g.adde(id,in[k<<1|1]);
	} //printf("\n");
	if(k^1) g.adde(out[k],out[k>>1]);
	if(s[k].l^s[k].r) g.adde(in[k],in[k<<1]),g.adde(in[k],in[k<<1|1]);
}
namespace SCC{
	int dfn[MAXV+5],low[MAXV+5],tim=0,stk[MAXV+5],top=0;
	int cmp=0,bel[MAXV+5];bool in[MAXV+5];
	void tarjan(int x){
		dfn[x]=low[x]=++tim;stk[++top]=x;in[x]=1;
		for(int e=g.hd[x];e;e=g.nxt[e]){
			int y=g.to[e];
			if(!dfn[y]) tarjan(y),chkmin(low[x],low[y]);
			else if(in[y]) chkmin(low[x],dfn[y]);
		}
		if(low[x]==dfn[x]){
			cmp++;int o;
			do {bel[o=stk[top--]]=cmp;in[o]=0;} while(o^x);
		}
	}
	void work(){
		for(int i=1;i<=ncnt;i++) if(!dfn[i]) tarjan(i);
	}
}
int main(){
	scanf("%d",&n);build(1,2,n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),t.adde(u,v),t.adde(v,u);
	scanf("%d",&m);ncnt=m<<1;dfs1();dfs2();
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);jumpath(i,u,v);
		scanf("%d%d",&u,&v);jumpath(i+m,u,v);
	} iterate(1);SCC::work();
	for(int i=1;i<=m;i++){
//		printf("%d %d\n",SCC::bel[i],SCC::bel[i+m]);
		if(SCC::bel[i]==SCC::bel[i+m]) return puts("NO"),0;
	} puts("YES");
	for(int i=1;i<=m;i++){
		if(SCC::bel[i]<SCC::bel[i+m]) printf("1\n");
		else printf("2\n");
	}
	return 0;
}