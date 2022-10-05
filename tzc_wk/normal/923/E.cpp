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
const int MAXN=1e5;
const int MAXP=1<<18;
const int MOD=998244353;
const int pr=3;
const int ipr=(MOD+1)/3;
int n,f[MAXN+5],g[MAXN+5],h[MAXN+5];ll m;
int fac[MAXN+5],ifac[MAXN+5];
void init_fac(int n){
	for(int i=(fac[0]=ifac[0]=ifac[1]=1)+1;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD;
}
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int rev[MAXP+5];
void NTT(vector<int> &a,int len,int type){
	int lg=31-__builtin_clz(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		int W=qpow((type<0)?ipr:pr,(MOD-1)/i);
		for(int j=0;j<len;j+=i){
			for(int k=0,w=1;k<(i>>1);k++,w=1ll*w*W%MOD){
				int X=a[j+k],Y=1ll*a[(i>>1)+j+k]*w%MOD;
				a[j+k]=(X+Y)%MOD;a[(i>>1)+j+k]=(X-Y+MOD)%MOD;
			}
		}
	}
	if(type==-1){
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
	scanf("%d%lld",&n,&m);m%=(MOD-1);init_fac(n);
	for(int i=0;i<=n;i++) scanf("%d",&f[i]);
	vector<int> A(n+1),B(n+1);
	for(int i=0;i<=n;i++) A[i]=ifac[i],B[n-i]=1ll*fac[i]*f[i]%MOD;
	vector<int> C=conv(A,B);
	for(int i=0;i<=n;i++){
		g[i]=1ll*ifac[i]*C[n-i]%MOD;
		g[i]=1ll*g[i]*qpow(qpow(i+1,MOD-2),m)%MOD;
	} iota(A.begin(),A.end(),0);iota(B.begin(),B.end(),0);
	for(int i=0;i<=n;i++){
		if(~i&1) A[i]=ifac[i];else A[i]=MOD-ifac[i];
		B[n-i]=1ll*fac[i]*g[i]%MOD;
	} C=conv(A,B);
	for(int i=0;i<=n;i++) printf("%d ",1ll*C[n-i]*ifac[i]%MOD);
	return 0;
}