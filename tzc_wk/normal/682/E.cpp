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
const int MAXN=5000;
int n;
struct point{
	int x,y;
	point(int _x=0,int _y=0):x(_x),y(_y){}
	point operator +(const point &rhs) const{return point(x+rhs.x,y+rhs.y);}
	point operator -(const point &rhs) const{return point(x-rhs.x,y-rhs.y);}
	ll operator |(const point &rhs) const{return 1ll*x*rhs.y-1ll*y*rhs.x;}
	ll operator ^(const point &rhs) const{return 1ll*x*rhs.x+1ll*y*rhs.y;}
} p[MAXN+5];
int stk[MAXN+5],tp=0;
bool cmp(point a,point b){return (a.x<b.x||(a.x==b.x&&a.y<b.y));}
ll mx=0;point A,B,C;
int getnxt(int x){return (x==tp)?1:(x+1);}
ll area(point a,point b,point c){return abs((b-a)|(c-a));}
int main(){
	scanf("%d%*d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp);stk[++tp]=1;
	for(int i=2;i<=n;i++){
		while(tp>1&&((p[stk[tp-1]]-p[stk[tp]])|(p[i]-p[stk[tp]]))>=0) tp--;
		stk[++tp]=i;
	} int tmp=tp;
	for(int i=n-1;i;i--){
		while(tp>tmp&&((p[stk[tp-1]]-p[stk[tp]])|(p[i]-p[stk[tp]]))>=0) tp--;
		stk[++tp]=i;
	} --tp;
	for(int i=1;i<=tp;i++){
		for(int j=getnxt(i),k=j;j^i;j=getnxt(j)){
			while(getnxt(k)!=i&&area(p[stk[i]],p[stk[j]],p[stk[k]])<area(p[stk[i]],p[stk[j]],p[stk[k+1]]))
				k=getnxt(k);
			if(area(p[stk[i]],p[stk[j]],p[stk[k]])>mx){
				mx=area(p[stk[i]],p[stk[j]],p[stk[k]]);
				A=p[stk[i]];B=p[stk[j]];C=p[stk[k]];
			}
		} 
	}
	printf("%d %d\n%d %d\n%d %d\n",
	A.x+B.x-C.x,A.y+B.y-C.y,
	A.x-B.x+C.x,A.y-B.y+C.y,
	-A.x+B.x+C.x,-A.y+B.y+C.y);
	return 0;
}