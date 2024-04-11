// author: xay5421
// created: Mon Dec  7 01:19:21 2020
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
int T,n,a[N],b[N];
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]),b[i]=0;
		int tt=0;
		vector<pair<int,int> >v;
		for(int i=1,j;i<=n;i=j){
			j=i+1;
			while(j<=n&&a[j]!=a[j-1])++j;
			v.EB(i,j-1);
			++tt;
		}
		int sum=0;
		for(auto x:v)++b[a[x.X]],++b[a[x.Y]],sum+=2;
		int mx=max_element(b+1,b+1+n)-b;
		if((b[mx]-2)*2<=sum-2){
			pt(tt-1,'\n');
		}else{
			int ans=tt-1+((b[mx]-2)*2-(sum-2))/2;
			rep(i,1,n)b[i]=0;
			sum=0;
			rep(i,1,n)++b[a[i]],++b[a[i]],sum+=2;
			int mx=max_element(b+1,b+1+n)-b;
			if((b[mx]-2)*2<=sum-2){
				pt(ans,'\n');
			}else{
				puts("-1");
			}
		}
	}
	return 0;
}