#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=200005;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int T,n,a[N];
LL sum[N];
int main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		sort(a+1,a+n+1);
		rep(i,1,n){
			sum[i]=sum[i-1]+a[i];
		}
		if(1LL*a[1]*(n-2)+sum[n]>0||1LL*a[n]*(n-2)+sum[n]<0){
			puts("INF");
			continue;
		}
		LL ans=~INFLL;
		rep(i,1,n-1){
			LL t=-a[i];
			LL cur=-1LL*t*t*(n-1);
			cur+=1LL*(a[1]+t)*(sum[n-1]-sum[i]+(n-1-i)*t);
			cur+=1LL*(a[n]+t)*(sum[i]+i*t);
			ans=max(ans,cur);
		}
		printf("%lld\n",ans);
	}
	return 0;
}