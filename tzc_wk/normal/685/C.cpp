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
const int MAXN=1e5;
const ll INF=7e18; 
int n;ll x[MAXN+5],y[MAXN+5],z[MAXN+5],X,Y,Z;
ll down(ll x){return (x>=0)?(x>>1):(-(-x+1>>1));}//\lfloor x/2 \rfloor
ll up(ll x){return (x>=0)?(x+1>>1):(-(-x>>1));}//\lceil x/2 \rceil
bool check(ll mid){
	ll al=-INF,ar=INF,bl=-INF,br=INF;
	ll cl=-INF,cr=INF,dl=-INF,dr=INF;
	for(int i=1;i<=n;i++){
		chkmax(al,x[i]+y[i]+z[i]-mid);chkmin(ar,x[i]+y[i]+z[i]+mid);
		chkmax(bl,-x[i]+y[i]+z[i]-mid);chkmin(br,-x[i]+y[i]+z[i]+mid);
		chkmax(cl,x[i]-y[i]+z[i]-mid);chkmin(cr,x[i]-y[i]+z[i]+mid);
		chkmax(dl,x[i]+y[i]-z[i]-mid);chkmin(dr,x[i]+y[i]-z[i]+mid);
	}
	for(int r=0;r<2;r++){
		ll wl=up(al-3*r),wr=down(ar-3*r);
		ll xl=up(bl-r),xr=down(br-r);
		ll yl=up(cl-r),yr=down(cr-r);
		ll zl=up(dl-r),zr=down(dr-r);
		if(wl<=wr&&xl<=xr&&yl<=yr&&zl<=zr&&xl+yl+zl<=wr&&xr+yr+zr>=wl){
			ll a=xl,b=yl,c=zl,need=max(0ll,wl-xl-yl-zl);
			a+=min(need,xr-xl);need-=min(need,xr-xl);
			b+=min(need,yr-yl);need-=min(need,yr-yl);
			c+=min(need,zr-zl);need-=min(need,zr-zl);
			a=(a<<1|r);b=(b<<1|r);c=(c<<1|r);
			X=b+c>>1;Y=c+a>>1;Z=a+b>>1;return 1;
		}
	} return 0;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
	ll l=0,r=INF>>1,p=-1;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid)) p=mid,r=mid-1;
		else l=mid+1;
	} check(p);//printf("%lld\n",p);
	printf("%lld %lld %lld\n",X,Y,Z);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}