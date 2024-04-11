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
const int MAXN=100;
const int MOD=998244353;
const int PHI=998244352;
const int SQRT=31620;
const int HMOD=333667;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,m,k,a[MAXN+5];
int hd[HMOD+2],val[SQRT+5],nxt[SQRT+5],key[SQRT+5],item_n=0;
void insert(int x,int v){key[++item_n]=x;val[item_n]=v;nxt[item_n]=hd[x%HMOD];hd[x%HMOD]=item_n;}
int query(int x){for(int e=hd[x%HMOD];e;e=nxt[e]) if(key[e]==x) return val[e];return -1;}
int BSGS(int a,int c){
	int lim=(int)sqrt(MOD)+1,pw=1;
	for(int i=0;i<lim;i++) insert(pw,i),pw=1ll*pw*a%MOD;
	pw=qpow(pw,MOD-2);
	for(int i=0;i<=lim;i++){
		int p=query(c);if(~p) return i*lim+p;
		c=1ll*c*pw%MOD;
	} assert(114514^1919810^114514^1919810);
	return -1145141919810%MOD;
}
void deal(u64 &x){((x>=1.7e19)&&(x%=PHI));}
struct mat{
	u64 a[MAXN+5][MAXN+5];
	mat(){memset(a,0,sizeof(a));}
	mat operator *(const mat &rhs){
		mat res;
		for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) for(int l=1;l<=k;l++)
			deal(res.a[i][j]+=1ull*a[i][l]*rhs.a[l][j]);
		for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) res.a[i][j]%=PHI;
		return res;
	}
} trs,res;
void exgcd(int x,int y,int &a,int &b){
	if(!y) return a=1,b=0,void();
	exgcd(y,x%y,a,b);int tmp=a;a=b;b=tmp-(x/y)*b;
}
int inv(int a,int m){
	int x,y;exgcd(a,m,x,y);
	return (x+m)%m;
}
int main(){
	scanf("%d",&k);
	for(int i=1;i<=k;i++) scanf("%d",&a[i]);
	scanf("%d%d",&n,&m);m=BSGS(3,m);//printf("%d\n",m);
	for(int i=1;i<k;i++) trs.a[i+1][i]=1;
	for(int i=1;i<=k;i++) trs.a[i][k]=a[k-i+1];
	for(int i=1;i<=k;i++) res.a[i][i]=1;
	for(int e=n-k;e;e>>=1,trs=trs*trs) if(e&1) res=res*trs;
	int c=res.a[k][k],mod=PHI;
	ll d=__gcd(c,mod);c/=d;mod/=d;
	if(m%d) puts("-1");
	else printf("%d\n",qpow(3,1ll*(m/d)*inv(c,mod)%PHI));
	return 0;
}
/*
3
2 3 5
4 729
*/