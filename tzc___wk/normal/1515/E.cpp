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
const int MAXN=4e2;
int n,mod,pw[MAXN+5],dp[MAXN+5][MAXN+5],fac[MAXN+5],ifac[MAXN+5];
int binom(int n,int k){return 1ll*fac[n]*ifac[k]%mod*ifac[n-k]%mod;}
int main(){
	scanf("%d%d",&n,&mod);pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%mod;
	for(int i=(fac[0]=ifac[0]=ifac[1]=1)+1;i<=n;i++) ifac[i]=1ll*ifac[mod%i]*(mod-mod/i)%mod;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod,ifac[i]=1ll*ifac[i-1]*ifac[i]%mod;
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=2;k<i;k++) if(j>=i-k)
				dp[i][j]=(dp[i][j]+1ll*dp[k-1][j-(i-k)]*pw[i-k-1]%mod*binom(j,i-k)%mod)%mod;
		} dp[i][i]=pw[i-1];
	} int ans=0;
	for(int i=1;i<=n;i++) ans=(ans+dp[n][i])%mod;
	printf("%d\n",ans);
	return 0;
}