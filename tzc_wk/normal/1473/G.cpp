//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("branch-target-load-optimize")
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
const int MAXN=1e3;
const int MAXP=16384;
const int MAXM=2e5;
const int MAXK=5e3;
const int pr=3;
const int ipr=332748118;
const int MOD=998244353;
int n,a[MAXN+5],b[MAXN+5],dp[MAXN+5][MAXK+5];
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int fac[MAXM+5],ifac[MAXM+5];
void init_fac(int n){
	for(int i=(fac[0]=ifac[0]=ifac[1]=1)+1;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD;
}
int binom(int x,int y){
	if(x<0||y<0||x<y) return 0;
	return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;
}
int rev[MAXP+5];
void NTT(vector<int> &a,int len,int type){
	int lg=31-__builtin_clz(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		int W=qpow((type<0)?ipr:pr,(MOD-1)/i);
		for(int j=0;j<len;j+=i){
			for(int k=0,w=1;k<(i>>1);k++,w=1ll*w*W%MOD){
				int X=a[j+k],Y=1ll*a[(i>>1)+j+k]*w%MOD;
				a[j+k]=(X+Y)%MOD;a[(i>>1)+j+k]=(X-Y+MOD)%MOD;
			}
		}
	} if(!~type){
		int ivn=qpow(len,MOD-2);
		for(int i=0;i<len;i++) a[i]=1ll*a[i]*ivn%MOD;
	}
}
vector<int> conv(vector<int> a,vector<int> b){
	int LEN=1;while(LEN<a.size()+b.size()) LEN<<=1;
	a.resize(LEN,0);b.resize(LEN,0);NTT(a,LEN,1);NTT(b,LEN,1);
	for(int i=0;i<LEN;i++) a[i]=1ll*a[i]*b[i]%MOD;NTT(a,LEN,-1);
	return a;
}
int main(){
	scanf("%d",&n);init_fac(MAXM);dp[0][1]=1;
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1,s=1;i<=n;i++){
		int uk=s,uj=s+a[i]-b[i];s+=a[i]-b[i];
		vector<int> A(uk+1);
		for(int k=1;k<=uk;k++) A[k]=dp[i-1][k];
		vector<int> B,C;
		for(int j=-uk;j<=uj;j++) B.pb(binom(a[i]+b[i],b[i]+j));
		C=conv(A,B);
		for(int j=1;j<=uj;j++) dp[i][j]=C[j+uk];
//		for(int j=1;j<=uj;j++) printf("%d %d %d\n",i,j,dp[i][j]);
	} int res=0;
	for(int i=1;i<=MAXK+1;i++) res=(res+dp[n][i])%MOD;
	printf("%d\n",res);
	return 0;
}