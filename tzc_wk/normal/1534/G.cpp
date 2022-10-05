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
//coded after reading csy's code
const int MAXN=8e5;
int n;
struct dat{
	ll s,x,y;
	bool operator <(const dat &rhs) const{
		return s<rhs.s;
	}
} a[MAXN+5];
priority_queue<ll> L;
priority_queue<ll,vector<ll>,greater<ll> > R;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].s=a[i].x+a[i].y;
	} sort(a+1,a+n+1);ll sum=0,res=0;
	L.push(a[1].x);R.push(a[1].x);
	for(int i=2;i<=n;i++){
		sum+=a[i].s-a[i-1].s;
		ll l0=L.top(),r0=R.top()+sum;
		if(a[i].x<l0){//the breakpoint is to the left of the segment with slope 0
			L.pop();R.push(l0-sum);L.push(a[i].x);L.push(a[i].x);
			res+=abs(l0-a[i].x);
		} else if(a[i].x>r0){
			R.pop();L.push(r0);R.push(a[i].x-sum);R.push(a[i].x-sum);
			res+=abs(r0-a[i].x);
		} else L.push(a[i].x),R.push(a[i].x-sum);
	} printf("%lld\n",res);
	return 0;
}