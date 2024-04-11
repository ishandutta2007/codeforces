//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
#include<algorithm>
#define int long long
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

const int N=100005;

int n,a[4],b[4],q[N];

void solve(int i){
	b[0]=a[0],b[1]=a[1],b[2]=a[2],b[3]=a[3];
	for(int _=1;_<=n;++_){
		if(b[i])q[_]=i,--b[i];else return;
		if(_==n)break;
		if(i>0&&b[i-1])--i;else
		if(i<3&&b[i+1])++i;else return;
	}
	puts("YES");
	for(int i=1;i<=n;++i)pt(q[i],' ');
	std::exit(0);
}

signed main(){
	rd(a[0]),rd(a[1]),rd(a[2]),rd(a[3]);
	n=a[0]+a[1]+a[2]+a[3];
	solve(0);
	solve(1);
	solve(2);
	solve(3);
	puts("NO");
	return 0;
}