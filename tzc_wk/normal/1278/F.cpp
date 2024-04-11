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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXK=1e7+1;
const int MOD=998244353;
int n,m,k;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int fac[MAXK+5],ifac[MAXK+5],f[MAXK+5],inv[MAXK+5];
void init_fac(int n){
	for(int i=(fac[0]=ifac[0]=inv[0]=inv[1]=1)+1;i<=n;i++) inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
}
int pwk[MAXK+5],pr[MAXK/10+5],prcnt=0;
bitset<MAXK+5> vis;
void sieve(int n){
	pwk[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]) pwk[i]=qpow(i,k);
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;pwk[pr[j]*i]=1ll*pwk[pr[j]]*pwk[i]%MOD;
			if(i%pr[j]==0) break;
		}
	}
}
int main(){
	init_fac(MAXK);int res=0;
	scanf("%d%d%d",&n,&m,&k);sieve(k+1);
	int ivm=qpow(m,MOD-2),pw=qpow(ivm,k+1);
	for(int l=k+1,cur=1;l>=2;l--){
		int t=1ll*cur*pw%MOD;
//		printf("%d\n",cur);
		if((k+1-l)&1) f[l-1]=(1ll*m*(f[l]-t+MOD)%MOD-f[l]+MOD)%MOD;
		else f[l-1]=(1ll*m*(f[l]+t)%MOD-f[l]+MOD)%MOD;
		cur=1ll*cur*(n-l+1+MOD)%MOD*inv[k+2-l]%MOD;
	}
	for(int l=1,cur=n;l<=k;l++){
		res=(res+1ll*f[l]*pwk[l]%MOD*cur)%MOD;
		cur=1ll*cur*(n-l)%MOD*inv[l+1]%MOD;
	} printf("%d\n",res);
	return 0;
}