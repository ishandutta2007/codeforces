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
const int MAXN=16;
const int MAXP=65536;
const int MAXC=192;
const u64 BS=17;
const int INV2=499122177;
const int MOD=998244353;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,k,c,fac[MAXP+5],ifac[MAXP+5],inv[MAXP+5],a[MAXP+5];
void init_fac(int n){
	for(int i=(fac[0]=ifac[0]=inv[0]=inv[1]=1)+1;i<=n;i++) inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
}
int b[MAXC+5][MAXN+5],idcnt,cnt[MAXC+5],bel[MAXP+5];
map<u64,int> id;
void FWTxor(int *a,int len,int type){
	for(int i=2;i<=len;i<<=1)
		for(int j=0;j<len;j+=i)
			for(int k=0;k<(i>>1);k++){
				int X=a[j+k],Y=a[(i>>1)+j+k];
				a[j+k]=1ll*type*(X+Y)%MOD;
				a[(i>>1)+j+k]=1ll*type*(X-Y+MOD)%MOD;
			}
}
void getln(int *a,int *b,int len){
	b[0]=0;
	for(int i=1;i<=len;i++){
		b[i]=1ll*a[i]*i%MOD;
		for(int j=1;j<i;j++) b[i]=(b[i]-1ll*j*b[j]%MOD*a[i-j]%MOD+MOD)%MOD;
		b[i]=1ll*b[i]*inv[i]%MOD;
	}
}
int tmp[MAXN+5][MAXP+5],res[MAXP+5];
void getexp(int *a,int *b,int len){
	b[0]=1;
	for(int i=1;i<=len;i++){
		b[i]=0;
		for(int j=1;j<=i;j++) b[i]=(b[i]+1ll*b[i-j]*j%MOD*a[j])%MOD;
		b[i]=1ll*b[i]*inv[i]%MOD;
	}
}
void calc_hash(){
	for(int i=k;i<(1<<c);i++){
		u64 pw=1,hs=0;
		for(int j=1;j<=k;j++){
			pw=pw*BS;hs+=(i^(i-j))*pw;
		} if(!id[hs]){
			id[hs]=++idcnt;
			for(int j=1;j<=k;j++) b[idcnt][j]=i^(i-j);
		} bel[i]=id[hs];
//		printf("%llu\n",hs);
	} for(int i=1;i<=n;i++) cnt[bel[a[i]]]++;
}
int lnb[MAXP+5][MAXN+5],tt[MAXP+5][MAXN+5];
void init_ln(){
	for(int i=0;i<(1<<k);i++){
		static int pl[MAXN+5]={0};
		memset(pl,0,sizeof(pl));pl[0]=1;
		for(int j=1;j<=k;j++) pl[j]=((i>>(j-1)&1)?ifac[j]:(MOD-ifac[j]));
//		printf("f=");for(int j=0;j<=k;j++) printf("%d%c",pl[j]," \n"[j==k]);
		getln(pl,lnb[i],k);
//		printf("ln=");for(int j=0;j<=k;j++) printf("%d%c",lnb[i][j]," \n"[j==k]);
	}
}
void calc_num(){
	for(int i=1;i<=idcnt;i++){
		memset(tmp,0,sizeof(tmp));
		for(int j=1;j<=k;j++) tmp[j][b[i][j]]=1;
		for(int j=1;j<=k;j++) FWTxor(tmp[j],1<<c,1);
//		printf("dealing %d\n",i);
//		for(int j=1;j<=k;j++) for(int l=0;l<(1<<c);l++)
//			printf("%d%c",tmp[j][l]," \n"[l==((1<<c)-1)]);
		for(int j=0;j<(1<<c);j++){
			int msk=0;
			for(int l=1;l<=k;l++)
				if(tmp[l][j]==1) msk|=(1<<l-1);
			for(int l=1;l<=k;l++) tt[j][l]=(tt[j][l]+1ll*lnb[msk][l]*cnt[i])%MOD;
//			printf("%d %d %d\n",i,j,msk);
		} //printf("%d\n",cnt[i]);
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&c);int sm=0;init_fac(MAXP);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sm^=a[i];
	calc_hash();init_ln();calc_num();
	for(int i=0;i<(1<<c);i++){
		static int pl[MAXN+5]={0};
		memset(pl,0,sizeof(pl));
		getexp(tt[i],pl,k);
		res[i]=pl[k];
//		for(int j=0;j<=k;j++) printf("%d%c",tt[i][j]," \n"[j==k]);
//		for(int j=0;j<=k;j++) printf("%d%c",pl[j]," \n"[j==k]);
//		printf("%d\n",res[i]);
	} FWTxor(res,1<<c,INV2);
//	for(int i=0;i<(1<<c);i++) printf("%d%c",res[i]," \n"[i==((1<<c)-1)]);
	int coef=1ll*fac[k]*qpow(qpow(n,MOD-2),k)%MOD;
	for(int i=0;i<(1<<c);i++) printf("%d%c",1ll*coef*res[sm^i]%MOD," \n"[i==((1<<c)-1)]);
	return 0;
}