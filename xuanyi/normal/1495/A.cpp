// author: xay5421
// created: Wed Mar 10 19:58:21 2021
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
const int N=100005;
int T,n;
signed main(){
	rd(T);
	while(T--){
		rd(n);
		vector<int>a,b;
		rep(i,1,n*2){
			int x,y;
			rd(x),rd(y);
			if(x==0)a.push_back(y);
			else b.push_back(x);
		}
		sort(a.begin(),a.end(),[&](int x,int y){return abs(x)<abs(y);});
		sort(b.begin(),b.end(),[&](int x,int y){return abs(x)<abs(y);});
		double s1=0;
		rep(i,0,n-1)s1+=sqrt(a[i]*a[i]+b[i]*b[i]);
		printf("%.20f\n",s1);
	}
	return 0;
}