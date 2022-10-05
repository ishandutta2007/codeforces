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
const int MAXN=1e6;
const int MOD=1e9+7;
int n,pw[MAXN+5],ret[MAXN+5];
struct data{
	int sum0,sum1,sum2;
	data(){sum0=sum1=sum2=0;}
	data(int x){sum0=1;sum1=x;sum2=1ll*x*x%MOD;}
	data(int _sum0,int _sum1,int _sum2):sum0(_sum0),sum1(_sum1),sum2(_sum2){}
	data operator +(const data &rhs){
		return data(
		sum0+rhs.sum0,
		(1ll*sum1*pw[rhs.sum0]+1ll*pw[sum0]*rhs.sum1)%MOD,
		(1ll*sum2*pw[rhs.sum0]%MOD+2ll*sum1*rhs.sum1+1ll*pw[sum0]*rhs.sum2)%MOD);
	}
} f[MAXN+5];
int main(){
	scanf("%d",&n);pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=2ll*pw[i-1]%MOD;
	for(int i=1,x;i<=n;i++) scanf("%d",&x),f[x]=f[x]+data(x);
	int cur=1;
	for(int i=0;i<=5;i++){
		for(int j=MAXN-1;~j;j--){
			if((j/cur)%10!=9) f[j]=f[j]+f[j+cur];
		}
		cur=cur*10;
	}
	for(int i=0;i<MAXN;i++) ret[i]=f[i].sum2;
	cur=1;
	for(int i=0;i<=5;i++){
		for(int j=0;j<MAXN;j++){
			if((j/cur)%10!=9) ret[j]=(ret[j]-ret[j+cur]+MOD)%MOD;
		}
		cur=cur*10;
	} ll ans=0;
	for(int j=0;j<MAXN;j++) ans^=1ll*j*ret[j];
	printf("%lld\n",ans);
	return 0;
}