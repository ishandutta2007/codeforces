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
const int MAXN=2e5;
const int LOG_N=18;
int n,qu,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int chd[MAXN+5],dep[MAXN+5],fa[MAXN+5][LOG_N+2];
int dfn[MAXN+5],tim=0,rid[MAXN+5],edt[MAXN+5];
void dfs0(int x,int f){
	fa[x][0]=f;rid[dfn[x]=++tim]=x;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		chd[x]++;dep[y]=dep[x]+1;dfs0(y,x);
	} edt[x]=tim;
}
int sum_chd[MAXN+5];
void dfs_chd(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		sum_chd[y]=sum_chd[x]+chd[y];
		dfs_chd(y,x);
	}
}
void lca_init(){
	dep[1]=1;dfs0(1,0);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++)
		fa[j][i]=fa[fa[j][i-1]][i-1];
}
int getlca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=LOG_N;~i;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
vector<int> pos[MAXN+5];
int stk[MAXN+5],tp=0;set<int> st;
vector<pii> qv[MAXN+5];
ll calc_sum(int u,int v,int k){//u is ancestor of v
	return (sum_chd[v]-sum_chd[u])-1ll*(k+1)*(dep[v]-dep[u]);
}
int calc_val(int u,int k){return chd[u]-1-k;}
vector<int> g[MAXN+5];
ll dp[MAXN+5],res[MAXN+5];
void insert(int x){
	if(!tp) return stk[++tp]=x,void();
	int lc=getlca(x,stk[tp]);
//	printf("LCA of %d %d is %d\n",x,stk[tp],lc);
//	printf("stack: ");
//	for(int i=1;i<=tp;i++) printf("%d%c",stk[i]," \n"[i==tp]);
	while(tp>1&&dep[stk[tp-1]]>dep[lc]){
//		printf("adde %d %d\n",stk[tp-1],lc);
		g[stk[tp-1]].pb(stk[tp]);--tp;
	}
	if(tp&&dep[stk[tp]]>dep[lc]){
//		printf("adde %d %d\n",lc,stk[tp]);
		g[lc].pb(stk[tp--]);
	}
	if(!tp||stk[tp]!=lc) stk[++tp]=lc;
	stk[++tp]=x;
}
void fin(){
	while(tp>=2){
//		printf("adde %d %d\n",stk[tp-1],stk[tp]);
		g[stk[tp-1]].pb(stk[tp]);--tp;
	} tp=0;
}
void dfs_dp(int x,int k){
	dp[x]=calc_val(x,k);st.insert(dfn[x]);
	for(int y:g[x]){
		dfs_dp(y,k);
		dp[x]+=max(dp[y]+calc_sum(x,y,k)-calc_val(y,k),0ll);
//		printf("calc_sum %d %d %d = %lld\n",x,y,k,calc_sum(x,y,k));
	} //printf("DP %d %lld\n",x,dp[x]);
}
void clr(int x){for(int y:g[x]) clr(y);g[x].clear();}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	lca_init();sum_chd[1]=chd[1];dfs_chd(1,0);scanf("%d",&qu);
//	for(int i=1;i<=n;i++) printf("chd[%d]=%d\n",i,chd[i]);
	for(int i=1;i<=n;i++) for(int j=0;j<chd[i];j++) pos[j].pb(i);
	for(int i=1,u,k;i<=qu;i++) scanf("%d%d",&u,&k),qv[k].pb(mp(u,i));
	for(int i=0;i<=MAXN;i++){
		st.clear();
		if(!pos[i].empty()){
//			printf("solving %d\n",i);
			sort(pos[i].begin(),pos[i].end(),[&](int x,int y){return dfn[x]<dfn[y];});
			if(pos[i][0]!=1) insert(1);
			for(int x:pos[i]) insert(x);
			fin();dfs_dp(1,i);
		}
		for(pii p:qv[i]){
			int u=p.fi,id=p.se;
			set<int>::iterator it=st.lower_bound(dfn[u]);
			if(it==st.end()||(*it)>edt[u]) res[id]=chd[u];
			else{
				int pt=rid[*it];
//				printf("%d %d\n",id,pt);
//				printf("%lld\n",calc_sum(fa[u][0],fa[pt][0],i));
				res[id]=chd[u]+max(0ll,dp[pt]+calc_sum(fa[u][0],fa[pt][0],i)-calc_val(u,i));
			}
		}
		clr(1);
	}
	for(int i=1;i<=qu;i++) printf("%lld\n",res[i]);
	return 0;
}
/*
11
1 2
2 3
2 4
1 5
5 6
5 7
7 8
7 9
7 10
1 11
4
1 0
1 1
5 2
11 0
*/