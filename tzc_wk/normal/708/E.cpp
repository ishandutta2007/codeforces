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
const int MAXN=1.5e3;
const int MAXK=1e5;
const int MOD=1e9+7;
int n,m,a,b,k,p,fac[MAXK+5],ifac[MAXK+5];
void init_fac(int n){
	fac[0]=ifac[0]=ifac[1]=1;
	for(int i=2;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i]*ifac[i-1]%MOD;
}
int d[MAXN+5],sd[MAXN+5],ss[MAXN+5];
int dp[MAXN+5][MAXN+5],sdp[MAXN+5][MAXN+5];
int binom(int x,int y){return 1ll*fac[x]*ifac[x-y]%MOD*ifac[y]%MOD;}
int qpow(int x,int e=MOD-2){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&k);
	p=1ll*a*qpow(b)%MOD;init_fac(k);
	if(p==1){
		if(k<=m) d[k]=1;
	}
	else{
		int ivp=1ll*p*qpow(MOD+1-p)%MOD,pw=1;
		for(int i=1;i<=k;i++) pw=1ll*pw*(MOD+1-p)%MOD;
		for(int i=0;i<=m;i++) d[i]=1ll*binom(k,i)*pw%MOD,pw=1ll*pw*ivp%MOD;
	}
	sd[0]=d[0];for(int i=1;i<=m;i++) sd[i]=(sd[i-1]+d[i])%MOD;
	dp[0][m]=1;sdp[0][m]=1;
	for(int i=1;i<=n;i++){
		memset(ss,0,sizeof(ss));
		for(int j=1;j<=m;j++) ss[j]=(ss[j-1]+1ll*d[j]*sdp[i-1][j])%MOD;
		for(int j=1;j<=m;j++){
			dp[i][j]=1ll*d[m-j]*(1ll*(sdp[i-1][m]-sdp[i-1][m-j]+MOD)*sd[j-1]%MOD-ss[j-1]+MOD)%MOD;
//			printf("%d %d %d\n",i,j,dp[i][j]);
		}
		for(int j=1;j<=m;j++) sdp[i][j]=(sdp[i][j-1]+dp[i][j])%MOD;
	} printf("%d\n",sdp[n][m]);
	return 0;
}