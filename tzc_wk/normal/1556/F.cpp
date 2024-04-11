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
const int MAXN=14;
const int MAXP=1<<14;
const int MOD=1e9+7;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,a[MAXN+5],wn[MAXN+5][MAXN+5];
int dp[MAXP+5],prd[MAXN+5][MAXP+5];
vector<pii> to[MAXP+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i^j)
		wn[i][j]=1ll*a[i]*qpow((a[i]+a[j])%MOD,MOD-2)%MOD;
	for(int i=1;i<=n;i++) for(int j=0;j<(1<<n);j++) if(~j>>(i-1)&1){
		prd[i][j]=1;
		for(int k=1;k<=n;k++) if(j>>(k-1)&1) prd[i][j]=1ll*prd[i][j]*wn[i][k]%MOD;
	}
	for(int i=0;i<(1<<n);i++){
		int rst=((1<<n)-1)^i;
		for(int j=rst;j;j=(j-1)&rst){
			int mul=1;
			for(int x=0;x<n;x++) if(j>>x&1){
				mul=1ll*mul*(1-prd[x+1][i]+MOD)%MOD;
			}
			to[i].pb(mp(j,mul));
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		memset(dp,0,sizeof(dp));dp[1<<i-1]=1;
		for(int j=1;j<(1<<n);j++) if(dp[j]){
			for(pii p:to[j]){
				int k=p.fi,mul=p.se;
				if(__builtin_popcount(k)&1) dp[j|k]=(dp[j|k]+1ll*dp[j]*mul)%MOD;
				else dp[j|k]=(dp[j|k]-1ll*dp[j]*mul%MOD+MOD)%MOD;
			}
		}
//		for(int j=0;j<(1<<n);j++) printf("%d %d\n",j,dp[j]);
//		printf("%d\n",dp[(1<<n)-1]);
		res=(res+dp[(1<<n)-1])%MOD;
	} printf("%d\n",res);
	return 0;
}