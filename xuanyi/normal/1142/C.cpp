//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}

const int N=200005;

int n;

struct po{
	int x,y;
	bool operator<(const po&b)const{return x^b.x?x<b.x:y>b.y;}
	bool operator==(const po&b)const{return x==b.x&&y==b.y;}
}p[N],q[N],st[N];

double get(po x,po y){
//	return 1.0*(y.y-x.y)/(x.x-y.x)*x.x+x.y;
	return 1.0*(y.y-x.y)/(x.x-y.x);
}

signed main(){
	rd(n);
	bool yis0=1;
	rep(i,1,n)rd(p[i].x),rd(p[i].y),yis0&=p[i].y==0;
	std::sort(p+1,p+1+n);
	n=std::unique(p+1,p+1+n)-p-1;
	if(yis0){pt(n-1,'\n');return 0;}
	rep(i,1,n){
		q[i].x=-p[i].x;
		q[i].y=p[i].y-1ll*p[i].x*p[i].x;
	}
	std::sort(q+1,q+1+n);q[0].x=-0x3f3f3f3f; 
	int top=0;
	rep(i,1,n)if(q[i].x!=q[i-1].x){
		while(top>1&&get(st[top-1],q[i])<=get(st[top-1],st[top])){
			--top;
		}
		st[++top]=q[i];
	}
	pt(top-1,'\n');
	return 0;
}