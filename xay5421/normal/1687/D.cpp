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
const int N=1000005;
int n,a[N];
int main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	rep(w,1,a[n]){
		LL l=1LL*w*w,r=l+w;
		l-=a[1],r-=a[1];
		l=max(l,0LL);
		if(l>r)continue;
		int w_=w;
		while(l<=r){
			LL l_=1LL*w_*w_,r_=l_+w_;
			LL tmp=r_-l;
			int p=upper_bound(a+1,a+n+1,tmp)-a;
			if(p<=n){
				if(p>1)r=min(r,r_-a[p-1]);
				while(1LL*w_*w_+w_<a[p]+l)++w_;
				l=max(l,1LL*w_*w_-a[p]);
			}else{
				break;
			}
		}
		if(l<=r){
			printf("%lld\n",l);
			return 0;
		}
	}
	return 0;
}