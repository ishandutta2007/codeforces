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
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int MAXP=MAXN*100;
int n,lnum=0,a[MAXN+5],b[MAXN+5],hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
struct line{
	ll k,b;
	line(ll _k=0,ll _b=INF):k(_k),b(_b){};
	ll get(int x){return 1ll*k*x+b;}
} ln[MAXN+5];
struct node{int ch[2],v;} s[MAXP+5];
int rt[MAXN+5],ncnt=0;
void insert(int &k,int l,int r,int v){
	if(!k) return k=++ncnt,s[k].v=v,void();int mid=l+r>>1;
	ll l1=ln[s[k].v].get(l),r1=ln[s[k].v].get(r),m1=ln[s[k].v].get(mid);
	ll l2=ln[v].get(l),r2=ln[v].get(r),m2=ln[v].get(mid);
	if(l1<=l2&&r1<=r2) return;
	if(l1>=l2&&r1>=r2) return s[k].v=v,void();
	if(m1>=m2){
		if(l1>=l2) insert(s[k].ch[1],mid+1,r,s[k].v),s[k].v=v;
		else insert(s[k].ch[0],l,mid,s[k].v),s[k].v=v;
	} else {
		if(l1>=l2) insert(s[k].ch[0],l,mid,v);
		else insert(s[k].ch[1],mid+1,r,v);
	}
}
ll query(int k,int l,int r,int v){
	if(!k) return INF;int mid=l+r>>1;
	return min((v<=mid)?query(s[k].ch[0],l,mid,v):query(s[k].ch[1],mid+1,r,v),ln[s[k].v].get(v));
}
int merge(int x,int y,int l,int r){
	if(!x||!y) return x+y;int mid=l+r>>1;insert(x,l,r,s[y].v);
	s[x].ch[0]=merge(s[x].ch[0],s[y].ch[0],l,mid);
	s[x].ch[1]=merge(s[x].ch[1],s[y].ch[1],mid+1,r);
	return x;
}
ll dp[MAXN+5];
void dfs(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs(y,x);rt[x]=merge(rt[x],rt[y],-1e5,1e5);
	} if((!nxt[hd[x]])&&(x^1)) dp[x]=0;
	else dp[x]=query(rt[x],-1e5,1e5,a[x]);
	ln[++lnum]=line(b[x],dp[x]);insert(rt[x],-1e5,1e5,lnum);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs(1,0);for(int i=1;i<=n;i++) printf("%lld%c",dp[i]," \n"[i==n]);
	return 0;
}