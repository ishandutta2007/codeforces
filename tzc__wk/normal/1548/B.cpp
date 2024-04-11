//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int MAXN=2e5;
const int LOG_N=18;
int n;ll a[MAXN+5],b[MAXN+5];
ll g[MAXN+5][LOG_N+2];
ll mygcd(ll x,ll y){return (!y)?x:mygcd(y,x%y);}
ll query(int l,int r){
	if(l>r) return 2;int k=31-__builtin_clz(r-l+1);
	return mygcd(g[l][k],g[r-(1<<k)+1][k]);
}
void solve(){
	scanf("%d",&n);int res=1;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<n;i++) b[i]=abs(a[i+1]-a[i]);
	for(int i=1;i<n;i++) g[i][0]=b[i];
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<n;j++)
		g[j][i]=mygcd(g[j][i-1],g[j+(1<<i-1)][i-1]);
	for(int i=1,j=1;i<n;i++){
		while(j<n&&query(i,j)>1) j++;
		chkmax(res,j-i+1);
	} printf("%d\n",res);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}