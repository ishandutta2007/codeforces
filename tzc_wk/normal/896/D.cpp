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
const int MAXD=100;
int n,p,l,r,tmp,phi;
int pr[MAXD+2],prcnt=0;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%p) if(e&1) ret=1ll*ret*x%p;
	return ret;
}
int fac[MAXN+5],ifac[MAXN+5];
int num[MAXN+5][MAXD+5];//the exponent of p[j] in i!
int binom(int x,int y){
	if(x<y||x<0||y<0) return 0;
	int mul=1ll*fac[x]*ifac[y]%p*ifac[x-y]%p;
	for(int i=1;i<=prcnt;i++){
		mul=1ll*mul*qpow(pr[i],num[x][i]-num[y][i]-num[x-y][i])%p;
	} return mul;
}
int main(){
	scanf("%d%d%d%d",&n,&p,&l,&r);tmp=phi=p;
	for(int i=2;i*i<=p;i++) if(tmp%i==0){
		phi=phi/i*(i-1);pr[++prcnt]=i;
		while(tmp%i==0) tmp/=i;
	} if(tmp>1) phi=phi/tmp*(tmp-1),pr[++prcnt]=tmp;
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++){
		int cur=i;
		for(int j=1;j<=prcnt;j++) num[i][j]=num[i-1][j];
		for(int j=1;j<=prcnt;j++) while(cur%pr[j]==0) num[i][j]++,cur/=pr[j];
		fac[i]=1ll*fac[i-1]*cur%p;ifac[i]=qpow(fac[i],phi-1);
	} int ans=0;
	for(int i=0;i<=n-l;i++){
		int numways=(0ll+binom(n-i,(n-i-l)>>1)-binom(n-i,(n-i-r-1)>>1)+p)%p;
		ans=(ans+1ll*numways*binom(n,i))%p;
	} printf("%d\n",ans);
	return 0;
}