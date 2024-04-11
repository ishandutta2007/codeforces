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

int main(){
	int T;
	rd(T);
	while(T--){
		int n;
		rd(n);
		vector<int>a(n);
		rep(i,0,n-1)rd(a[i]);
		sort(a.begin(),a.end());
		int f=1;
		if(n&1)f=0;
		else{
			rep(i,0,n/2-1){
				f&=a[i]<a[i+n/2];
				f&=a[i+n/2]>a[(i+1)%(n/2)];
			}
		}
		if(f){
			puts("YES");
			rep(i,0,n/2-1)printf("%d %d ",a[i],a[i+n/2]);
			puts("");
		}else{
			puts("NO");
		}
	}
	return 0;
}