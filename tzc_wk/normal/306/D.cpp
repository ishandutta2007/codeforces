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
const int MAXN=100;
const double Pi=acos(-1);
const double EPS=1e-6;
int n;
double len[MAXN+5];
struct point{
	double x,y;
	point(double _x=0,double _y=0):x(_x),y(_y){}
	point operator +(const point &rhs) const{return point(x+rhs.x,y+rhs.y);}
	point operator -(const point &rhs) const{return point(x-rhs.x,y-rhs.y);}
	point operator *(const double &rhs) const{return point(x*rhs,y*rhs);}
	point operator /(const double &rhs) const{return point(x/rhs,y/rhs);}
	double operator ~() const{return sqrt(x*x+y*y);}
} p[MAXN+5];
int main(){
	srand(time(0));scanf("%d",&n);
	if(n<=4) return puts("No solution")&0;
	double ang=2*Pi/n;
	while(1){
		for(int i=1;i<n;i++) len[i]=600+i*0.1;
		random_shuffle(len+1,len+n);
		p[1]=point(0,0);p[2]=point(len[1],0);
		for(int i=3;i<=n;i++){
			point dif=p[i-1]-p[i-2];
			point coe=point(cos(ang),sin(ang));
			point nw=point(dif.x*coe.x-dif.y*coe.y,dif.x*coe.y+dif.y*coe.x);
			nw=nw*(len[i-1]/len[i-2]);
			if(i^n) p[i]=p[i-1]+nw;
			else{
				double k1=nw.y/nw.x;
				double b=p[i-1].y-k1*p[i-1].x;
				double k2=tan(Pi/n*(n-2));
				p[i].x=b/(k2-k1);p[i].y=k2*p[i].x;
			}
		} bool flg=(~(p[1]-p[n])<1000+EPS);
		for(int i=1;i<n;i++) flg&=(fabs((~(p[1]-p[n]))-len[i])>EPS);
		if(flg) break;
	}
	for(int i=1;i<=n;i++) printf("%.10lf %.10lf\n",p[i].x,p[i].y);
	return 0;
}