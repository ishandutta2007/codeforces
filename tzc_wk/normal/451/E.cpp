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
const int MAXN=20;
const int MOD=1e9+7;
int n,inv[MAXN+5];
ll s,f[MAXN+5];
int binom(ll n,int m){
	if(n<0||n<m) return 0;int res=1;
	for(int i=1;i<=m;i++) res=1ll*res*((n+1-i)%MOD)%MOD*inv[i]%MOD;
	return res;
}
int main(){
	scanf("%d%lld",&n,&s);int res=0;
	for(int i=1;i<=n;i++) scanf("%lld",&f[i]);
	for(int i=(inv[0]=inv[1]=1)+1;i<=n;i++) inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=0;i<(1<<n);i++){
		ll sum=0;
		for(int j=1;j<=n;j++) if(i>>(j-1)&1) sum+=f[j]+1;
		if(__builtin_parity(i)) res=(res-binom(s-sum+n-1,n-1)+MOD)%MOD;
		else res=(res+binom(s-sum+n-1,n-1))%MOD;
	} printf("%d\n",res);
	return 0;
}