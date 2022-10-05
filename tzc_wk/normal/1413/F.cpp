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
const int MAXN=5e5;
int n,qu,hd[MAXN+5],to[MAXN*2+5],val[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
namespace getdia{
	int dep1[MAXN+5],dep2[MAXN+5],rt1=1,rt2=1;
	void dfs1(int x,int f){
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			dep1[y]=dep1[x]+1;dfs1(y,x);
		}
	}
	void dfs2(int x,int f){
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			dep2[y]=dep2[x]+1;dfs2(y,x);
		}
	}
	void finddia(){
		dfs1(1,0);for(int i=1;i<=n;i++) if(dep1[i]>dep1[rt1]) rt1=i;
		dfs2(rt1,0);for(int i=1;i<=n;i++) if(dep2[i]>dep2[rt2]) rt2=i;
	}
}
struct solver{
	int rt,dfn[MAXN+5],edt[MAXN+5],tim=0,rid[MAXN+5];
	int par[MAXN+5],dw[MAXN+5],dep[MAXN+5];
	void dfs(int x,int f){
		dfn[x]=++tim;rid[tim]=x;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=val[e];if(y==f) continue;
			dw[e+1>>1]=y;par[y]=par[x]^z;dep[y]=dep[x]+1;dfs(y,x);
		} edt[x]=tim;
	}
	struct node{int l,r,mx[2],flp;} s[MAXN*4+5];
	void pushup(int k){
		s[k].mx[0]=max(s[k<<1].mx[0],s[k<<1|1].mx[0]);
		s[k].mx[1]=max(s[k<<1].mx[1],s[k<<1|1].mx[1]);
	}
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;if(l==r){s[k].mx[par[rid[l]]]=dep[rid[l]];return;}
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
	}
	void pushdown(int k){
		if(s[k].flp){
			swap(s[k<<1].mx[0],s[k<<1].mx[1]);s[k<<1].flp^=1;
			swap(s[k<<1|1].mx[0],s[k<<1|1].mx[1]);s[k<<1|1].flp^=1;
			s[k].flp=0;
		}
	}
	void modify(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			s[k].flp^=1;swap(s[k].mx[0],s[k].mx[1]);return;
		} pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(r<=mid) modify(k<<1,l,r);
		else if(l>mid) modify(k<<1|1,l,r);
		else modify(k<<1,l,mid),modify(k<<1|1,mid+1,r);
		pushup(k);
	}
	int query(){return s[1].mx[0];}
	void init(){dfs(rt,0);build(1,1,n);}
	void toggle(int x){modify(1,dfn[dw[x]],edt[dw[x]]);}
} t[2];
int main(){
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d",&u,&v,&w),adde(u,v,w),adde(v,u,w);
	getdia::finddia();t[0].rt=getdia::rt1;t[1].rt=getdia::rt2;t[0].init();t[1].init();
	int qu;scanf("%d",&qu);
	while(qu--){
		int x;scanf("%d",&x);t[0].toggle(x);t[1].toggle(x);
		printf("%d\n",max(t[0].query(),t[1].query()));
	}
	return 0;
}