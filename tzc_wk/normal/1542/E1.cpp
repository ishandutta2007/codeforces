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
const int MAXN=500;
const int MAXM=500*499/2;
int n,mod,ans=0,dp[MAXN+5][MAXM+5],sum[MAXN+5][MAXM+5];
int c[MAXN+5][MAXN+5],fac[MAXN+5];
int main(){
	scanf("%d%d",&n,&mod);dp[1][0]=1;
	for(int i=0;i<=MAXM;i++) sum[1][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i*(i-1)/2;j++){
			dp[i][j]=sum[i-1][j];
			if(j-i>=0) dp[i][j]=(dp[i][j]-sum[i-1][j-i]+mod)%mod;
//			printf("%d %d %d\n",i,j,dp[i][j]);
		} sum[i][0]=dp[i][0];
		for(int j=1;j<=MAXM;j++) sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
	}
	for(int i=(fac[0]=1)-1;i<=MAXN;i++){
		c[i][0]=1;if(i) fac[i]=1ll*fac[i-1]*i%mod;
		for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	for(int i=0;i<n;i++){
		int lim=i*(i+1)/2,s=0;
		for(int j=0;j<=i*(i-1)/2;j++){
			s=(s+1ll*lim*sum[i][j-1]%mod*dp[i][j])%mod;
			for(int k=max(0,j-i);k<j;k++){
				s=(s-1ll*(i-j+k+1)*(i-j+k+2)/2*dp[i][k]%mod*dp[i][j]%mod+mod)%mod;
			}
		} //printf("%d\n",s);
		ans=(ans+1ll*s*c[n][n-i-1]%mod*fac[n-i-1])%mod;
	}
	printf("%d\n",ans);
	return 0;
}