// author: xay5421
// created: Sun Feb 28 21:59:06 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=105;
int T,n,u,v,a[N];
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(u),rd(v);
		rep(i,1,n)rd(a[i]);
		LL ans=1e18;
		rep(i,1,n-1){
			if(abs(a[i+1]-a[i])>1){
				ans=min(ans,0LL);
			}
		}
		rep(i,1,n-1){
			if(a[i]==a[i+1]){
				ans=min({ans,u+v,v+v});
			}
		}
		rep(i,1,n-1){
			if(abs(a[i]-a[i+1])==1){
				ans=min(ans,min(u,v));
			}
		}
		pt(ans,'\n');
	}
	return 0;
}