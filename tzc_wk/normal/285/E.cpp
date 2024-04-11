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
const int MAXN=1000;
const int MOD=1e9+7;
int n,m,dp[MAXN+5][MAXN+5][2][2];
int fac[MAXN+5],ifac[MAXN+5];
void add(int &x,int y){x+=y;if(x>=MOD) x-=MOD;}
int binom(int x,int y){return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;}
int main(){
	scanf("%d%d",&n,&m);dp[1][1][0][1]=dp[1][0][0][0]=1;
	fac[0]=1;ifac[0]=ifac[1]=1;
	for(int i=2;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD;
	for(int i=2;i<=n;i++) for(int j=0;j<=i;j++){
		if(j){
			add(dp[i][j][0][0],dp[i-1][j-1][0][0]);
			add(dp[i][j][1][0],dp[i-1][j-1][0][1]);
			add(dp[i][j][0][1],dp[i-1][j-1][0][0]);
			add(dp[i][j][0][1],dp[i-1][j-1][1][0]);
			add(dp[i][j][1][1],dp[i-1][j-1][0][1]);
			add(dp[i][j][1][1],dp[i-1][j-1][1][1]);
		}
		add(dp[i][j][0][0],dp[i-1][j][0][0]);
		add(dp[i][j][0][0],dp[i-1][j][1][0]);
		add(dp[i][j][1][0],dp[i-1][j][0][1]);
		add(dp[i][j][1][0],dp[i-1][j][1][1]);
	} int ans=0;
	for(int i=m;i<=n;i++){
		int ways=1ll*(dp[n][i][0][0]+dp[n][i][1][0])*fac[n-i]%MOD;
		if((i-m)&1) ans=(ans-1ll*ways*binom(i,m)%MOD+MOD)%MOD;
		else ans=(ans+1ll*ways*binom(i,m))%MOD;
	} printf("%d\n",ans);
	return 0;
}