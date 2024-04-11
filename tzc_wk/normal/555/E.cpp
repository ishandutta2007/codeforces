//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("branch-target-load-optimize")
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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
const int LOG_N=19;
int n,m,qu,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=1;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int _hd[MAXN+5],_to[MAXN*2+5],_nxt[MAXN*2+5],_ec=0;
void _adde(int u,int v){_to[++_ec]=v;_nxt[_ec]=_hd[u];_hd[u]=_ec;}
int dfn[MAXN+5],low[MAXN+5],cut[MAXN+5],tim=0,bel[MAXN+5],cmp=0;
void tarjan(int x,int f){
	dfn[x]=low[x]=++tim;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(!dfn[y]){
			tarjan(y,x);chkmin(low[x],low[y]);
			if(low[y]>dfn[x]) cut[e>>1]=1;
		} else if(y^f) chkmin(low[x],dfn[y]);
	}
}
void redfs(int x){
	if(bel[x]) return;bel[x]=cmp;
	for(int e=hd[x];e;e=nxt[e]) if(!cut[e>>1]) redfs(to[e]);
}
int dep[MAXN+5],fa[MAXN+5][LOG_N+2];
void dfs0(int x,int f){
//	printf("%d %d %d\n",x,f,dep[x]);
	fa[x][0]=f;
	for(int e=_hd[x];e;e=_nxt[e]){
		int y=_to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs0(y,x);
	}
}
int getlca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=LOG_N;~i;i--) if(fa[x][i]^fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int cnt0[MAXN+5],cnt1[MAXN+5];
void dfs(int x){
	for(int e=_hd[x];e;e=_nxt[e]){
		int y=_to[e];if(y==fa[x][0]) continue;
		dfs(y);cnt0[x]+=cnt0[y];cnt1[x]+=cnt1[y];
	} if(cnt0[x]&&cnt1[x]) puts("No"),exit(0);
}
int main(){
	scanf("%d%d%d",&n,&m,&qu);vector<int> rts;
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
	for(int i=1;i<=n;i++) if(!bel[i]) cmp++,redfs(i);
//	for(int i=1;i<=n;i++) printf("%d\n",bel[i]);
	for(int i=1;i<=n;i++) for(int e=hd[i];e;e=nxt[e]){
		int j=to[e];if(bel[i]^bel[j]) _adde(bel[i],bel[j]);
	}
	for(int i=1;i<=cmp;i++) if(!dep[i]) dep[i]=1,dfs0(i,0),rts.pb(i);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=cmp;j++)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	while(qu--){
		int x,y;scanf("%d%d",&x,&y);x=bel[x];y=bel[y];
		int l=getlca(x,y);if(!l) return puts("No"),0;
//		printf("%d %d %d\n",x,y,l);
		cnt0[x]++;cnt0[l]--;cnt1[y]++;cnt1[l]--;
	} for(int x:rts) dfs(x);puts("Yes");
	return 0;
}
/*
5 4 3
1 2
1 3
2 4
2 5
4 5
3 2
4 1
*/