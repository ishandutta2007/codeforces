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
int T,n,K,a[N];
LL sum[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(K);
		rep(i,1,n)rd(a[i]),sum[i]=sum[i-1]+a[i];
		LL ret=0;
		rep(i,1,n){
			if(i+K-1<=n){
				ret=max(ret,sum[i+K-1]-sum[i-1]+1LL*K*(K-1)/2);
			}else{
				ret=max(ret,sum[n]-sum[i-1]+1LL*(K-1)*(n-i+1)-1LL*n*(n-1)/2);
			}
		}
		printf("%lld\n",ret);
	}
	return 0;
}