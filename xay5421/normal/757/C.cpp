//by xay5421 2449670833@qq.com
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
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
const int N=1000005,P=1000000007;
int n,m;
std::vector<int>a[N];
signed main(){
	rd(n),rd(m);
	rep(i,1,n){
		int foo;rd(foo);
		while(foo--){
			int x;rd(x);
			a[x].push_back(i);
		}
	}
	int ans=1,t=1;
	std::sort(a+1,a+1+m);
	rep(i,2,m){
		if(a[i]==a[i-1]){
			++t;
			ans=1ll*ans*t%P;
		}else t=1;
	}
	pt(ans,'\n');
	return 0;
}