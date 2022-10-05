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
const int MAXN=3000;
const int MOD=1e9+7;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,D,hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dp[MAXN+5][MAXN+5];
void dfs(int x){
	for(int i=1;i<=n+2;i++) dp[x][i]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dfs(y);
		for(int j=1;j<=n+2;j++) dp[x][j]=1ll*dp[x][j]*dp[y][j]%MOD;
	} for(int i=1;i<=n+2;i++) dp[x][i]=(dp[x][i]+dp[x][i-1])%MOD;
}
int main(){
	scanf("%d%d",&n,&D);
	for(int i=2,fa;i<=n;i++) scanf("%d",&fa),adde(fa,i);
	dfs(1);int res=0;
	for(int i=1;i<=n+2;i++){
		int up=1,dw=1;
		for(int j=1;j<=n+2;j++) if(i^j){
			up=1ll*up*(D-j+MOD)%MOD;dw=1ll*dw*(i-j+MOD)%MOD;
		} res=(res+1ll*dp[1][i]*up%MOD*qpow(dw,MOD-2))%MOD;
	} printf("%d\n",res);
	return 0;
}