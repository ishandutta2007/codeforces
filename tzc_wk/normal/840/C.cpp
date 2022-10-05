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
const int MAXN=300;
const int MOD=1e9+7;
int n,a[MAXN+5],f[MAXN+5];
bool issqr(ll x){int _sqrt=sqrt(x);return (1ll*_sqrt*_sqrt==x);}
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
void merge(int x,int y){x=find(x);y=find(y);if(x^y) f[x]=y;}
int siz[MAXN+5],b[MAXN+5],bn=0;
int dp[MAXN+5][MAXN+5],fac[MAXN+5],ifac[MAXN+5];
void init_fac(int n){
	fac[0]=ifac[0]=ifac[1]=1;
	for(int i=2;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	for(int i=1;i<=n;i++) ifac[i]=1ll*ifac[i]*ifac[i-1]%MOD;
}
int binom(int x,int y){
	if(x<0||y<0||x<y) return 0;
	return 1ll*fac[x]*ifac[x-y]%MOD*ifac[y]%MOD;
}
int main(){
	scanf("%d",&n);init_fac(n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(issqr(1ll*a[i]*a[j]))
		merge(i,j);
	for(int i=1;i<=n;i++) siz[find(i)]++;
	for(int i=1;i<=n;i++) if(find(i)==i) b[++bn]=siz[i];
	dp[0][0]=1;
	for(int i=1;i<=bn;i++) for(int j=1;j<=n;j++) for(int k=1;k<=min(j,b[i]);k++){
		dp[i][j]=(dp[i][j]+1ll*dp[i-1][j-k]*binom(b[i]-1,k-1)%MOD*ifac[k]%MOD)%MOD;
	} int ans=0,mul=1;for(int i=1;i<=bn;i++) mul=1ll*mul*fac[b[i]]%MOD;
	for(int i=bn;i<=n;i++){
		if((n-i)&1) ans=(ans-1ll*dp[bn][i]*fac[i]%MOD*mul%MOD+MOD)%MOD;
		else ans=(ans+1ll*dp[bn][i]*fac[i]%MOD*mul%MOD)%MOD;
	} printf("%d\n",ans);
	return 0;
}