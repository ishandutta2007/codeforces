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
const int MAXN=5e5;
const int INF=1061109567;
int n,k,m,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=1;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dep[MAXN+5],siz[MAXN+5],wson[MAXN+5],fa[MAXN+5];
int top[MAXN+5],dfn[MAXN+5],tim=0;
bool ban[MAXN+5];int f[MAXN+5],bot[MAXN+5];
struct edge{int u,v,w;} e[MAXN+5];
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
bool merge(int x,int y){x=find(x);y=find(y);if(x^y) return f[x]=y,1;return 0;}
void dfs1(int x,int f){
	siz[x]=1;fa[x]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs1(y,x);
		bot[e>>1]=y;siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]]) wson[x]=y;
	}
}
void dfs2(int x,int tp){
	top[x]=tp;dfn[x]=++tim;if(wson[x]) dfs2(wson[x],tp);
	for(int e=hd[x];e;e=nxt[e]) if(to[e]!=fa[x]&&to[e]!=wson[x])
		dfs2(to[e],to[e]);
}
int tag[MAXN*4+5],vis[MAXN*4+5];
void modify(int k,int l,int r,int ql,int qr,int v){
	if(ql>qr||vis[k]) return;
	if(ql<=l&&r<=qr) return chkmin(tag[k],v),vis[k]=1,void();
	int mid=l+r>>1;
	if(qr<=mid) modify(k<<1,l,mid,ql,qr,v);
	else if(ql>mid) modify(k<<1|1,mid+1,r,ql,qr,v);
	else modify(k<<1,l,mid,ql,mid,v),modify(k<<1|1,mid+1,r,mid+1,qr,v);
}
int query(int k,int l,int r,int p){
	if(l==r) return tag[k];int mid=l+r>>1;
	return min((p<=mid)?query(k<<1,l,mid,p):query(k<<1|1,mid+1,r,p),tag[k]);
}
void jumpath(int u,int v,int w){
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		modify(1,1,n,dfn[top[u]],dfn[u],w);
		u=fa[top[u]];
	} if(dep[u]<dep[v]) swap(u,v);
	modify(1,1,n,dfn[v]+1,dfn[u],w);
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1,u,v;i<=k;i++){
		scanf("%d%d",&u,&v);adde(u,v);adde(v,u);
		merge(u,v);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		if(merge(e[i].u,e[i].v)) adde(e[i].u,e[i].v),adde(e[i].v,e[i].u);
	} memset(tag,63,sizeof(tag));dfs1(1,0);dfs2(1,1);
	for(int i=1;i<=m;i++) jumpath(e[i].u,e[i].v,e[i].w);
	ll res=0;
	for(int i=1;i<=k;i++){
		int val=query(1,1,n,dfn[bot[i]]);
		if(val==INF) return puts("-1"),0;
		res+=val;
	} printf("%lld\n",res);
	return 0;
}