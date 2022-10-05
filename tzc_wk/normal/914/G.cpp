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
#define bitcnt __builtin_popcount
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
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXM=17;
const int MAXN=1<<17;
const int MOD=1e9+7;
int n,a[MAXM+5][MAXN+5],b[MAXN+5],c[MAXN+5],d[MAXM+5][MAXN+5],e[MAXN+5];
int fib[MAXN+5];
void FWTor(int *a,int len,int type){
	for(int i=2;i<=len;i<<=1)
		for(int j=0;j<len;j+=i)
			for(int k=0;k<(i>>1);k++)
				a[(i>>1)+j+k]=(a[(i>>1)+j+k]+1ll*type*a[j+k])%MOD;
}
void FWTand(int *a,int len,int type){
	for(int i=2;i<=len;i<<=1)
		for(int j=0;j<len;j+=i)
			for(int k=0;k<(i>>1);k++)
				a[j+k]=(a[j+k]+1ll*type*a[(i>>1)+j+k])%MOD;
}
void FWTxor(int *a,int len,int type){
	for(int i=2;i<=len;i<<=1)
		for(int j=0;j<len;j+=i)
			for(int k=0;k<(i>>1);k++){
				int X=a[j+k],Y=a[(i>>1)+j+k];
				a[j+k]=1ll*type*(X+Y)%MOD;
				a[(i>>1)+j+k]=1ll*type*(X-Y+MOD)%MOD;
			}
}
int main(){
	fib[1]=fib[2]=1;scanf("%d",&n);
	for(int i=3;i<1<<17;i++) fib[i]=(fib[i-1]+fib[i-2])%MOD;
	for(int i=1,x;i<=n;i++) scanf("%d",&x),b[x]++;
	for(int i=0;i<1<<17;i++) a[bitcnt(i)][i]=c[i]=b[i];
	for(int i=0;i<=17;i++) FWTor(a[i],1<<17,1);
	FWTxor(c,1<<17,1);
	for(int i=0;i<1<<17;i++) c[i]=1ll*c[i]*c[i]%MOD;
	FWTxor(c,1<<17,(MOD+1)>>1);
//	debug(1);
	for(int i=0;i<=17;i++) for(int j=0;j<=i;j++) for(int k=0;k<1<<17;k++)
		d[i][k]=(d[i][k]+1ll*a[j][k]*a[i-j][k])%MOD;
	for(int i=0;i<=17;i++) FWTor(d[i],1<<17,MOD-1);
	for(int i=0;i<1<<17;i++){
		b[i]=1ll*b[i]*fib[i]%MOD;
		c[i]=1ll*c[i]*fib[i]%MOD;
		e[i]=1ll*d[bitcnt(i)][i]*fib[i]%MOD;
//		printf("%d %d %d\n",b[i],c[i],e[i]);
	} FWTand(b,1<<17,1);FWTand(c,1<<17,1);FWTand(e,1<<17,1);
	for(int i=0;i<1<<17;i++) b[i]=1ll*b[i]*c[i]%MOD*e[i]%MOD;
	FWTand(b,1<<17,MOD-1);int ans=0;
	for(int i=1;i<1<<17;i<<=1) ans=(ans+b[i])%MOD;
	printf("%d\n",ans);
	return 0;
}