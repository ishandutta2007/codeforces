//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int MAXN=5e4;
const int MAXM=5e4;
const int MAXV=5e5;
const int MAXE=2e6;
int n,m,mx,ncnt=0;
struct edge{int u,v,c,t;} e[MAXM+5];
vector<int> g[MAXN+5];
vector<pii> col[MAXN+5];
int hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],ec=0;
int _hd[MAXV+5],_ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dfn[MAXV+5],low[MAXV+5],stk[MAXV+5],tp=0;
int bel[MAXV+5],cmp=0,tim=0;bool vis[MAXV+5];
void tarjan(int x){
	dfn[x]=low[x]=++tim;stk[++tp]=x;vis[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(!dfn[y]) tarjan(y),chkmin(low[x],low[y]);
		else if(vis[y]) chkmin(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		int o;cmp++;do{
			o=stk[tp--];bel[o]=cmp;vis[o]=0;
		} while(o^x);
	}
}
bool check(int mid){
	for(int i=1;i<=ncnt;i++) hd[i]=_hd[i];ec=_ec;
	memset(dfn,0,sizeof(dfn));memset(low,0,sizeof(low));tim=cmp=tp=0;
	for(int i=1;i<=m;i++) if(e[i].t>mid) adde(i,i+m);
	for(int i=1;i<=ncnt;i++) (!dfn[i]&&(tarjan(i),0));
	for(int i=1;i<=m;i++) if(bel[i]==bel[i+m]) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].c,&e[i].t);
		chkmax(mx,e[i].t);g[e[i].u].pb(i);g[e[i].v].pb(i);
		col[e[i].u].pb(mp(e[i].c,i));col[e[i].v].pb(mp(e[i].c,i));
	} ncnt=m<<1;
	for(int i=1;i<=n;i++) sort(col[i].begin(),col[i].end());
	for(int i=1;i<=n;i++){
		vector<int> pre(g[i].size()),suf(g[i].size());
		for(int j=0;j<pre.size();j++) pre[j]=++ncnt;
		for(int j=0;j<suf.size();j++) suf[j]=++ncnt;
		for(int j=1;j<pre.size();j++) adde(pre[j-1],pre[j]);
		for(int j=1;j<suf.size();j++) adde(suf[j],suf[j-1]);
		for(int j=0;j<pre.size();j++) adde(g[i][j],pre[j]);
		for(int j=0;j<suf.size();j++) adde(suf[j],g[i][j]+m);
		for(int j=1;j<pre.size();j++) adde(pre[j-1],g[i][j]+m),adde(g[i][j],suf[j-1]);
	}
	for(int i=1;i<=n;i++){
		for(int l=0,r;l<col[i].size();l=r){
			r=l;while(r<col[i].size()&&col[i][r].fi==col[i][l].fi) ++r;
			vector<int> pre(r-l),suf(r-l);
			for(int j=0;j<pre.size();j++) pre[j]=++ncnt;
			for(int j=0;j<suf.size();j++) suf[j]=++ncnt;
			for(int j=1;j<pre.size();j++) adde(pre[j-1],pre[j]);
			for(int j=1;j<suf.size();j++) adde(suf[j],suf[j-1]);
			for(int j=0;j<pre.size();j++) adde(pre[j],col[i][j+l].se);
			for(int j=0;j<suf.size();j++) adde(col[i][j+l].se+m,suf[j]);
			for(int j=1;j<pre.size();j++) adde(col[i][j-1+l].se+m,pre[j]),adde(suf[j],col[i][j-1+l].se);
		}
	}
	for(int i=1;i<=ncnt;i++) _hd[i]=hd[i];_ec=ec;
	int l=0,r=mx,p=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) p=mid,r=mid-1;
		else l=mid+1;
	} if(!~p) puts("No");
	else{
		printf("Yes\n%d ",p);check(p);vector<int> vec;
		for(int i=1;i<=m;i++) if(bel[i]<bel[i+m]) vec.pb(i);
		printf("%d\n",vec.size());for(int x:vec) printf("%d ",x);
	}
	return 0;
}