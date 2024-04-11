#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int n,m,a[N],b[N],c[N],d[N],ans[N];
signed main(){
	rd(n),rd(m);
	rep(i,1,n){
		rd(a[i]),rd(b[i]);
	}
	rep(i,1,m){
		rd(c[i]),rd(d[i]);
	}
	rep(i,1,n){
		rep(j,1,m)if(a[i]<=c[j]){
			int o=c[j]-a[i];
			ans[o]=max(ans[o],b[i]<=d[j]?d[j]-b[i]+1:0);
		}
	}
	int res=1e18;
	per(i,N-2,0){
		ans[i]=max(ans[i],ans[i+1]);
	}
	rep(i,0,N-1)res=min(res,i+ans[i]);
	pt(res,'\n');
	return 0;
}