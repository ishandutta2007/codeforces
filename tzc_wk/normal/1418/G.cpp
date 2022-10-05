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
const int MAXN=5e5;
const u32 BS=311;
const u64 MOD=2305843009213693951;//M_{61} is a prime
int n,a[MAXN+5],buc[MAXN+5];u64 pw[MAXN+5],hs[MAXN+5],v[3];
u64 Rand(){return ((1ll*rand()&1)<<60)|((1ll*rand())<<45)|((1ll*rand())<<30)|rand()<<15|rand();}
u64 getmul(__int128_t x,__int128_t y){return x*y%MOD;}
int main(){
	srand(189758783);scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	v[1]=Rand();v[2]=Rand();
	for(int i=(pw[0]=1);i<=n;i++) pw[i]=getmul(pw[i-1],BS);
	for(int i=1;i<=n;i++){
		hs[i]=hs[i-1];hs[i]=(0ll+hs[i]-getmul(v[buc[a[i]]],pw[a[i]])+MOD)%MOD;
		buc[a[i]]=(buc[a[i]]+1)%3;hs[i]=(0ll+hs[i]+getmul(v[buc[a[i]]],pw[a[i]]))%MOD;
//		printf("%llu\n",hs[i]);
	} map<u64,int> cnt;memset(buc,0,sizeof(buc));cnt[0]++;
	ll res=0;
	for(int i=1,j=1;i<=n;i++){
		buc[a[i]]++;
		while(buc[a[i]]>3) cnt[hs[j-1]]--,buc[a[j++]]--;
		res+=cnt[hs[i]];cnt[hs[i]]++;
//		printf("%d %d\n",i,j);
	} printf("%lld\n",res);
	return 0;
}