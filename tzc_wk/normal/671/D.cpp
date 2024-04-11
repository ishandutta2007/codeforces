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
const int MAXN=3e5;
const ll INF=1e18;
int n,m,w[MAXN+5];ll dp[MAXN+5];
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
struct node{int l,r;ll mn,lz;} s[MAXN*4+5];
void pushup(int k){s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].mn=INF;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void pushdown(int k){
	if(s[k].lz){
		s[k<<1].mn+=s[k].lz;s[k<<1].lz+=s[k].lz;
		s[k<<1|1].mn+=s[k].lz;s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
}
void add(int k,int l,int r,ll x){
	if(l<=s[k].l&&s[k].r<=r){s[k].lz+=x;s[k].mn+=x;return;}
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) add(k<<1,l,r,x);else if(l>mid) add(k<<1|1,l,r,x);
	else add(k<<1,l,mid,x),add(k<<1|1,mid+1,r,x);pushup(k);
}
void modify(int k,int p,ll x){
	if(s[k].l==s[k].r){s[k].mn=x;return;}
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	(p<=mid)?modify(k<<1,p,x):modify(k<<1|1,p,x);
	pushup(k);
}
ll query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].mn;
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
}
int L[MAXN+5],R[MAXN+5],tim=0,dfn[MAXN+5];
vector<int> top[MAXN+5],bot[MAXN+5];
void dfs0(int x,int f){
	L[x]=tim+1;
	for(int id:bot[x]) dfn[id]=++tim;
	for(int e=hd[x];e;e=nxt[e]) if(f^to[e]) dfs0(to[e],x);
	R[x]=tim;
}
void dfs(int x,int f){
	ll sum=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs(y,x);sum+=dp[y];
	}
	for(int id:bot[x]) modify(1,dfn[id],w[id]+sum);
	for(int id:top[x]) modify(1,dfn[id],INF);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		if(L[y]<=R[y]) add(1,L[y],R[y],sum-dp[y]);
	}
	if(L[x]<=R[x]) dp[x]=query(1,L[x],R[x]);
	else dp[x]=INF;
//	printf("%d %lld\n",x,dp[x]);
	if(dp[x]>=INF) puts("-1"),exit(0);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d%d",&u,&v,&w[i]),bot[u].pb(i),top[v].pb(i);
	dfs0(1,0);build(1,1,m);ll ans=0;//for(int i=1;i<=m;i++) printf("%d\n",dfn[i]);
	for(int e=hd[1];e;e=nxt[e]) dfs(to[e],1),ans+=dp[to[e]];
	printf("%lld\n",ans);
	return 0;
}