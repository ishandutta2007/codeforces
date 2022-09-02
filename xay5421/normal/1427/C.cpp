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
const int N=100005;
int r,n,x[N],y[N],t[N],f[N];
signed main(){
	memset(f,192,sizeof(f));
	f[0]=0,x[0]=1,y[0]=1,t[0]=0;
	rd(r),rd(n);
	rep(i,1,n){
		rd(t[i]),rd(x[i]),rd(y[i]);
	}
	rep(i,1,n){
		rep(j,max(i-2000,0LL),i-1){
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]){
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
	pt(*max_element(f,f+1+n),'\n');
	return 0;
}