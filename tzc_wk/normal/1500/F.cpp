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
const int MAXN=1e6;
int n;ll C,w[MAXN+5],can[MAXN+5],d[MAXN+5],s[MAXN+5],l,r;
set<ll> st;int flg;ll dlt;
ll gettrs(ll x){return flg?(dlt-x):(dlt+x);}
ll getori(ll x){return flg?(dlt-x):(x-dlt);}
int main(){
	scanf("%d%lld",&n,&C);l=0;r=C;
	for(int i=1;i<=n-2;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n-2;i++){
		ll L=getori(0),R=getori(w[i]);if(L>R) L^=R^=L^=R;
		chkmax(l,L);chkmin(r,R);
		while(!st.empty()&&(*st.begin())<L) st.erase(st.begin());
		while(!st.empty()&&(*st.rbegin())>R) st.erase(st.find(*st.rbegin()));
		if(l>r&&st.empty()) return puts("NO"),0;
		if(st.find(getori(w[i]))!=st.end()||(l<=getori(w[i])&&getori(w[i])<=r)){
			st.clear();l=0;r=can[i]=w[i];flg=dlt=0;continue;
		} if(l<=r) can[i]=gettrs(l);else can[i]=gettrs(*st.begin());
		flg^=1;dlt=w[i]-dlt;st.insert(getori(w[i]));
	} if(l<=r) d[n-1]=gettrs(l);else d[n-1]=gettrs(*st.begin());
	for(int i=n-2;i;i--){
		if(can[i]==w[i]) d[i]=w[i];
		else if(d[i+1]==w[i]) d[i]=can[i];
		else d[i]=w[i]-d[i+1];
	} ll t=1;
//	for(int i=1;i<=n-1;i++) printf("%lld%c",d[i]," \n"[i==n-1]);
	for(int i=n-2;i;i--){
		if(abs(d[i])+abs(d[i+1])!=w[i]) t=-t;
		d[i]=t*d[i];
	} ll mn=1e18;puts("YES");
	for(int i=1;i<=n;i++) s[i]=s[i-1]+d[i-1],chkmin(mn,s[i]);
	for(int i=1;i<=n;i++) printf("%lld%c",s[i]-mn," \n"[i==n]);
	return 0;
}