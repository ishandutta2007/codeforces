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
const int MAXN=50;
const int MOD=1e9+7;
const int INV2=5e8+4;
int n,d[MAXN+5],s2[MAXN+5],s3[MAXN+5];
int dp[MAXN+5][MAXN+5],f[MAXN+5][MAXN+5][MAXN+5];
int fac[MAXN+5],ifac[MAXN+5];
void init_fac(int n){
	for(int i=(fac[0]=ifac[0]=ifac[1]=1)+1;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD,fac[i]=1ll*fac[i-1]*i%MOD;
}
int binom(int x,int y){return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;}
int main(){
	scanf("%d",&n);init_fac(n);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);f[0][0][0]=1;
	for(int i=1;i<=n;i++) s2[i]=s2[i-1]+(d[i]^3),s3[i]=s3[i-1]+(d[i]^2);
//	for(int i=1;i<=n;i++) printf("%d %d\n",s2[i],s3[i]);
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int k=0;k<=n;k++){
		if(!i&&!j&&!k) continue;
		if(!i&&!j) for(int l=3;l<=k;l++)
			f[i][j][k]=(f[i][j][k]+1ll*f[i][j][k-l]*binom(k-1,l-1)%MOD*fac[l-1]%MOD*INV2%MOD)%MOD;
		else if(!i) f[i][j][k]=(((j-2>=0)?(1ll*(j-1)*f[i][j-2][k]):0ll)+((k-1>=0)?1ll*k*f[i][j][k-1]:0ll))%MOD;
		else f[i][j][k]=(1ll*f[i-1][j-1][k]*j+1ll*f[i-1][j+1][k-1]*k)%MOD;
//		printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
	} dp[d[1]+1][d[1]]=1;int ans=0;
	for(int i=d[1]+2;i<=n;i++) for(int j=1;j<i;j++) for(int k=1;k<i-j;k++)
		dp[i][j]=(dp[i][j]+1ll*dp[i-j][k]*f[j][s2[i-j]-s2[i-j-k]][s3[i-j]-s3[i-j-k]])%MOD;
//	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) printf("%d %d %d\n",i,j,dp[i][j]);
	for(int i=1;i<=n;i++) ans=(ans+1ll*dp[n][i]*f[0][s2[n]-s2[n-i]][s3[n]-s3[n-i]])%MOD;
	return 0&printf("%d\n",ans);
}