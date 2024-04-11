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
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
typedef long double ld;
const ld Pi=acos(-1);
const int MAXN=1e5;
int n;
struct point{
	ld x,y;int id;
	point(ld _x=0,ld _y=0):x(_x),y(_y){}
	point operator +(const point &rhs) const{return point(x+rhs.x,y+rhs.y);}
	point operator -(const point &rhs) const{return point(x-rhs.x,y-rhs.y);}
	point operator *(const ld &rhs) const{return point(x*rhs,y*rhs);}
	point operator /(const ld &rhs) const{return point(x/rhs,y/rhs);}
	ld operator |(const point &rhs){return x*rhs.y-y*rhs.x;}
	ld operator ^(const point &rhs){return x*rhs.x+y*rhs.y;}
	ld operator ~() const{return sqrt(x*x+y*y);}
	ld operator !() const{return atan2(y,x);}
} p[MAXN+5];
ld cmp(point lhs,point rhs){return !lhs<!rhs;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%Lf%Lf",&p[i].x,&p[i].y),p[i].id=i;
	sort(p+1,p+n+1,cmp);ld mn=2*Pi;int ps=-1;
	for(int i=1;i<n;i++) if(mn>(!p[i+1]-!p[i])) mn=(!p[i+1]-!p[i]),ps=i;
	if(mn>(!p[1]+2*Pi-!p[n])) ps=n;
	printf("%d %d\n",p[ps].id,p[ps%n+1].id);
	return 0;
}