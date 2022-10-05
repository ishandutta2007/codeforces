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
const int MAXN=1e6;
const int MOD=1e9+7;
int fac[MAXN*2+5],ifac[MAXN*2+5];
void init_fac(int n){
	for(int i=(fac[0]=ifac[0]=ifac[1]=1)+1;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD;
}
int binom(int x,int y){return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;}
int numway(int n,int s){if(!n) return 0;return binom(s+n-1,n-1);}
int pr[MAXN>>3],prcnt=0,vis[MAXN+5],mnp[MAXN+5];
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]) pr[++prcnt]=i,mnp[i]=i;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;mnp[pr[j]*i]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
}
int dp[11][11];
pii fc[11];int fcnt=0;
int main(){
	sieve(MAXN);init_fac(MAXN*2);
	int qu;scanf("%d",&qu);
	while(qu--){
		int n,r;fcnt=0;scanf("%d%d",&r,&n);
		while(n^1){
			int p=mnp[n],cnt=0;
			while(n%p==0) n/=p,++cnt;
			fc[++fcnt]=mp(p,cnt);
		} memset(dp,0,sizeof(dp));dp[0][0]=1;
		for(int i=1;i<=fcnt;i++) for(int j=0;j<i;j++){
			dp[i][j]=(dp[i][j]+1ll*dp[i-1][j]*numway(r,fc[i].se))%MOD;
			dp[i][j+1]=(dp[i][j+1]+1ll*dp[i-1][j]*(numway(r+1,fc[i].se)-numway(r,fc[i].se)+MOD))%MOD;
		} int res=0;
		for(int i=0;i<=fcnt;i++) res=(res+1ll*dp[fcnt][i]*(1<<i))%MOD;
		printf("%d\n",res);
	}
	return 0;
}