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
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
const int LOG_N=19;
const int MOD=1e9+7;
int qpow(int x,int e=MOD-2){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int pr[MAXN/5+5],vis[MAXN+5],phi[MAXN+5],mu[MAXN+5],prcnt=0;
void sieve(int n){
	phi[1]=mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){pr[++prcnt]=i;phi[i]=i-1;mu[i]=-1;}
		for(int j=1;j<=prcnt&&i*pr[j]<=n;j++){
			vis[i*pr[j]]=1;
			if(i%pr[j]==0){phi[i*pr[j]]=phi[i]*pr[j];break;}
			else phi[i*pr[j]]=phi[i]*phi[pr[j]],mu[i*pr[j]]=-mu[i];
		}
	}
}
int n,a[MAXN+5],pos[MAXN+5],f[MAXN+5],res[MAXN+5];
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int seq[MAXN*2+5],dfn[MAXN+5],tim=0,tim_dfn=0,dep[MAXN+5],bgt[MAXN+5];
pii st[MAXN*2+5][LOG_N+2];
void dfs(int x,int f){
	bgt[x]=++tim_dfn;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x);seq[++tim]=x;
	} seq[++tim]=x;dfn[x]=tim;
}
pii querymn(int l,int r){
	int k=31-__builtin_clz(r-l+1);
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int getlca(int x,int y){
	if(dfn[x]>dfn[y]) x^=y^=x^=y;
	return querymn(dfn[x],dfn[y]).se;
}
int pt[MAXN+5],pcnt=0,stk[MAXN+5],tp=0;
bool in[MAXN+5];vector<pii> g[MAXN+5];
void adde_vir(int u,int v){/*printf("%d %d\n",u,v);*/g[u].pb(mp(v,dep[v]-dep[u]));}
void insert(int x){
//	printf("insert %d\n",x);
	if(!tp){stk[++tp]=x;return;}
	int lca=getlca(x,stk[tp]);
	while(tp>=2&&dep[lca]<dep[stk[tp-1]]){adde_vir(stk[tp-1],stk[tp]);tp--;}
	if(tp&&dep[lca]<dep[stk[tp]]) adde_vir(lca,stk[tp--]);
	if(!tp||stk[tp]!=lca) stk[++tp]=lca;
	stk[++tp]=x;
}
void fin(){
	while(tp>=2) adde_vir(stk[tp-1],stk[tp]),tp--;
	tp=0;
}
int ret=0,dp[MAXN+5],dis[MAXN+5];
void dfs_vir(int x){
	dp[x]=0;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i].fi,z=g[x][i].se;
		dis[y]=dis[x]+z;dfs_vir(y);
		ret=(ret-2ll*dp[x]*dp[y]%MOD*dis[x]%MOD+MOD)%MOD;
		dp[x]=(dp[x]+dp[y])%MOD;
	} if(in[x]){
		ret=(ret-1ll*dp[x]*phi[a[x]]%MOD*dis[x]%MOD+MOD)%MOD;
		dp[x]=(dp[x]+phi[a[x]])%MOD;
		ret=(ret-1ll*dp[x]*phi[a[x]]%MOD*dis[x]%MOD+MOD)%MOD;
	}
}
void clear(int x){
	dp[x]=dis[x]=0;
	for(int i=0;i<g[x].size();i++) clear(g[x][i].fi);
	while(g[x].size()) g[x].pop_back();
}
int solve(int x){
//	printf("solve %d\n",x);
	pcnt=0;
	for(int i=x;i<=n;i+=x) pt[++pcnt]=pos[i],in[pos[i]]=1;
	sort(pt+1,pt+pcnt+1,[](int x,int y){return bgt[x]<bgt[y];});
	if(!in[1]) insert(1);for(int i=1;i<=pcnt;i++) insert(pt[i]);fin();
	ret=0;dfs_vir(1);int s1=0,s2=0;
	for(int i=1;i<=pcnt;i++){
		s1=(s1+1ll*phi[a[pt[i]]]*dis[pt[i]])%MOD;
		s2=(s2+phi[a[pt[i]]])%MOD;
	} //printf("%d %d\n",s1,s2);
	ret=(ret+1ll*s1*s2)%MOD;ret=ret*2%MOD;clear(1);
	for(int i=x;i<=n;i+=x) in[pos[i]]=0;
	return ret;
}
int main(){
	scanf("%d",&n);sieve(n);
//	for(int i=1;i<=n;i++) printf("%d %d\n",phi[i],mu[i]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs(1,0);for(int i=1;i<=n<<1;i++) st[i][0]=mp(dep[seq[i]],seq[i]);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n<<1;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
//	for(int i=1;i<=2*n;i++) printf("%d ",seq[i]);printf("\n");
//	for(int i=1;i<=n;i++) printf("%d ",dfn[i]);printf("\n");
//	for(int i=1;i<=n;i++) printf("%d ",bgt[i]);printf("\n");
	for(int i=1;i<=n;i++) f[i]=solve(i);
//	for(int i=1;i<=n;i++) printf("%d\n",f[i]);
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i){
		if(mu[j/i]==1) res[i]=(res[i]+f[j])%MOD;
		else if(mu[j/i]==-1) res[i]=(res[i]-f[j]+MOD)%MOD;
	} int ans=0;
	for(int i=1;i<=n;i++) ans=(ans+1ll*res[i]*i%MOD*qpow(phi[i]))%MOD;
	ans=1ll*ans*qpow(n)%MOD;ans=1ll*ans*qpow(n-1)%MOD;
	printf("%d\n",ans);
	return 0;
}