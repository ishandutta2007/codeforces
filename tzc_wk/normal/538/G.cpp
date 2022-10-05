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
const int MAXN=2e5;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,l;
struct data{
	ll t,x,y,p,q;
	bool operator <(const data &rhs){
		return q<rhs.q;
	}
} a[MAXN+5];
int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i].t,&a[i].x,&a[i].y);
		if((a[i].t+a[i].x+a[i].y)&1ll) return puts("NO"),0;
		a[i].p=a[i].t/l;a[i].q=a[i].t%l;
		ll tmpx=a[i].x,tmpy=a[i].y;
		a[i].x=(tmpx+tmpy+a[i].t)>>1;
		a[i].y=(tmpy-tmpx+a[i].t)>>1;
	} a[++n].p=-1;a[n].q=l;sort(a+1,a+n+1);
	ll xd=0,xu=INF,yd=0,yu=INF;
	for(int i=1;i<=n;i++){
		ll difp=a[i].p-a[i-1].p,difq=a[i].q-a[i-1].q;
		if(difp==0){
			if(a[i].x-a[i-1].x<0||a[i].x-a[i-1].x-difq>0) return puts("NO"),0;
			if(a[i].y-a[i-1].y<0||a[i].y-a[i-1].y-difq>0) return puts("NO"),0;
		} else if(difp>0){
			chkmax(xd,(ll)ceil(1.0l*(a[i].x-a[i-1].x-difq)/difp));
			chkmin(xu,(ll)floor(1.0l*(a[i].x-a[i-1].x)/difp));
			chkmax(yd,(ll)ceil(1.0l*(a[i].y-a[i-1].y-difq)/difp));
			chkmin(yu,(ll)floor(1.0l*(a[i].y-a[i-1].y)/difp));
		} else{
			difp=-difp;
			chkmax(xd,(ll)ceil(1.0l*(a[i-1].x-a[i].x)/difp));
			chkmin(xu,(ll)floor(1.0l*(a[i-1].x-a[i].x+difq)/difp));
			chkmax(yd,(ll)ceil(1.0l*(a[i-1].y-a[i].y)/difp));
			chkmin(yu,(ll)floor(1.0l*(a[i-1].y-a[i].y+difq)/difp));
		}
	} if(xd>xu||yd>yu) return puts("NO"),0;
	ll vx=xd,vy=yd;
	for(int i=1;i<=n;i++){
		ll stpx=(a[i].x-a[i].p*vx)-(a[i-1].x-a[i-1].p*vx);
		ll stpy=(a[i].y-a[i].p*vy)-(a[i-1].y-a[i-1].p*vy);
		int curx=0,cury=0,stp=a[i].q-a[i-1].q;
		while(stp--){
			if(curx<stpx){
				++curx;
				if(cury<stpy) ++cury,putchar('U');
				else putchar('R');
			} else {
				if(cury<stpy) ++cury,putchar('L');
				else putchar('D');
			}
		}
	} putchar('\n');
	return 0;
}