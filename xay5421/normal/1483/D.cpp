// author: xay5421
// created: Sun Mar 21 22:18:55 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
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
const int N=605;
const LL INF=0X3F3F3F3F3F3F3F3FLL;
int n,m,Q;
LL f[N][N],g[N][N],h[N][N];
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(f,63,sizeof(f));
	rd(n),rd(m);
	rep(i,1,m){
		int k1,k2,k3;
		rd(k1),rd(k2),rd(k3);
		f[k1][k2]=k3,f[k2][k1]=k3;
	}
	rd(Q);
	rep(i,1,Q){
		int k1,k2,k3;
		rd(k1),rd(k2),rd(k3);
		h[k1][k2]=-k3,h[k2][k1]=-k3;
	}
	memcpy(g,f,sizeof(g));
	rep(k,1,n)rep(i,1,n)if(i!=k)rep(j,1,n)if(j!=k&&j!=i)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	rep(k,1,n){
		rep(i,1,n)rep(j,1,n)h[i][j]=min({h[i][j],h[i][k]+g[k][j],g[i][k]+h[k][j]});
	}
	int ans=0;
	rep(i,1,n)rep(j,i+1,n)if(f[i][j]+h[i][j]<=0)++ans;
	pt(ans,'\n');
	return 0;
}