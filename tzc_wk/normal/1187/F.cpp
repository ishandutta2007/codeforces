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
const int MAXN=2e5;
const int MOD=1e9+7;
const int INV2=MOD+1>>1;
int n,l[MAXN+5],r[MAXN+5],iv[MAXN+5],p[MAXN+5];
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&l[i]);
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	for(int i=0;i<=n;i++) iv[i]=qpow(r[i]-l[i]+1,MOD-2);
	int sum=0;
	for(int i=0;i<n;i++){
		if(max(l[i],l[i+1])<=min(r[i],r[i+1])){
			int len=min(r[i],r[i+1])-max(l[i],l[i+1])+1;
			p[i+1]=1ll*len*iv[i]%MOD*iv[i+1]%MOD;
			p[i+1]=(1-p[i+1]+MOD)%MOD;
		} else p[i+1]=1;
	}
	for(int i=1;i<=n;i++) sum=(sum+p[i])%MOD;
	for(int i=1;i<n;i++){
		int pl=1-p[i]+MOD,pr=1-p[i+1]+MOD;
		int lmx=max(l[i-1],max(l[i],l[i+1]));
		int rmn=min(r[i-1],min(r[i],r[i+1]));
		int p_bth=(lmx>rmn)?0:(1ll*(rmn-lmx+1)*iv[i-1]%MOD*iv[i]%MOD*iv[i+1]%MOD);
		int tt=(1ll-pl-pr+p_bth+MOD+MOD)%MOD;
//		printf("%d\n",tt);
		sum=(sum+2ll*tt)%MOD;
	}
	for(int i=1,s=0;i<=n;i++) sum=(sum+1ll*s*p[i])%MOD,s=(s+p[i-1])%MOD;
	for(int i=n,s=0;i;i--) sum=(sum+1ll*s*p[i])%MOD,s=(s+p[i+1])%MOD;
	printf("%d\n",sum);
	return 0;
}