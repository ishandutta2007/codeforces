// author: xay5421
// created: Sat Dec 19 17:41:15 2020
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
const int N=105,INF=0X3F3F3F3F;
int n;
struct ff{
	int a,b;
	bool operator<(const ff&k)const{
		return b<k.b;
	}
}A[N];
int f[2][N][N*N];
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(f,192,sizeof(f));
	rd(n);
	rep(i,1,n)rd(A[i].a),rd(A[i].b);
	sort(A+1,A+1+n);
	f[0][0][0]=0;
	int allv=0;
	rep(i,1,n){
		allv+=A[i].b;
		memcpy(f[i&1],f[(i-1)&1],sizeof(f[i&1]));
		rep(j,1,i){
			rep(k,A[i].b,allv){
				int x=f[(i-1)&1][j-1][k-A[i].b];
				if(x!=~INF){
					f[i&1][j][k]=max(f[i&1][j][k],x+A[i].a);
				}
			}
		}
	}
	double ans=0;
	rep(i,1,n){
		rep(j,0,allv)ans=max(ans,min(1.*f[n&1][i][j],j+(allv-j)/2.));
		printf("%.20f ",ans);
	}
	return 0;
}