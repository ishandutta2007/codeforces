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
const int MAXN=100;
const int MOD=1e9+7;
int qpow(int x,int e){
	if(e<0) e+=MOD-1;int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int fac[MAXN+5],ifac[MAXN+5];
void init_fac(int n){
	fac[0]=ifac[0]=ifac[1]=1;
	for(int i=2;i<=n;i++) ifac[i]=1ll*(MOD-MOD/i)*ifac[MOD%i]%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD;
}
int binom(int x,int y){return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;}
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dp[MAXN+5][MAXN+5][2],siz[MAXN+5],tmp[MAXN+5][2];
int f[MAXN+5],g[MAXN+5];
void dfs(int x,int f){
	dp[x][1][0]=dp[x][1][1]=siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;dfs(y,x);memset(tmp,0,sizeof(tmp));
		for(int i=1;i<=siz[x];i++) for(int j=1;j<=siz[y];j++){
			tmp[i+j][0]=(tmp[i+j][0]+1ll*dp[x][i][0]*dp[y][j][1])%MOD;
			tmp[i+j][1]=(tmp[i+j][1]+1ll*dp[x][i][1]*dp[y][j][1])%MOD;
			tmp[i+j-1][0]=(tmp[i+j-1][0]+1ll*dp[x][i][0]*dp[y][j][0])%MOD;
			tmp[i+j-1][1]=(tmp[i+j-1][1]+1ll*dp[x][i][1]*dp[y][j][0]+1ll*dp[x][i][0]*dp[y][j][1])%MOD;
		} siz[x]+=siz[y];
		for(int i=1;i<=siz[x];i++) dp[x][i][0]=tmp[i][0],dp[x][i][1]=tmp[i][1];
	}
//	for(int i=1;i<=siz[x];i++) printf("%d %d %d %d\n",x,i,dp[x][i][0],dp[x][i][1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs(1,0);init_fac(n);
	for(int i=1;i<=n;i++) f[n-i]=1ll*dp[1][i][1]*qpow(n,i-2)%MOD;
	for(int i=0;i<n;i++) for(int j=i;j<n;j++){
		if((j-i)&1) g[i]=(g[i]-1ll*f[j]*binom(j,i)%MOD+MOD)%MOD;
		else g[i]=(g[i]+1ll*f[j]*binom(j,i))%MOD;
	}
	for(int i=0;i<n;i++) printf("%d%c",g[i],(i==n-1)?'\n':' ');
	return 0;
}