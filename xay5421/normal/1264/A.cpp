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

const int N=400005;

int t,n,ans1,ans2,ans3,a[N];

signed main(){
	rd(t);
	while(t--){
		ans1=ans2=ans3=0;
		rd(n);
		rep(i,1,n)rd(a[i]);
		if(n<6){
			puts("0 0 0");
			continue;
		}
		int i=1,j=1;
		while(j<=n&&a[j]==a[i])++j;
		if((j-1)*2>n){
			puts("0 0 0");
			continue;
		}
		ans1=j-i;
		i=j,++j;
		while(j<=n&&(j-i<=ans1||a[j]==a[j-1]))++j;
		if((j-1)*2>n){
			puts("0 0 0");
			continue;
		}
		ans2=j-i;
		while(1){
			i=j,++j;
			while(j<=n&&(j-1-ans1-ans2<=ans1||a[j]==a[j-1]))++j;
			if((j-1)*2>n){
				break;
			}
			ans3+=j-i;
		}
		if(ans3==0){
			puts("0 0 0");
			continue;
		}
		pt(ans1,' '),pt(ans2,' '),pt(ans3,'\n');
	}
	return 0;
}