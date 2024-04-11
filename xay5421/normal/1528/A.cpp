// author: xay5421
// created: Mon May 24 22:30:32 2021
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
int T,n,L[N],R[N],f[N][2];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs1(int k1,int k2){
	f[k1][0]=f[k1][1]=0;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dfs1(to[i],k1);
		f[k1][0]+=max(f[to[i]][0]+abs(L[to[i]]-L[k1]),f[to[i]][1]+abs(R[to[i]]-L[k1]));
		f[k1][1]+=max(f[to[i]][0]+abs(L[to[i]]-R[k1]),f[to[i]][1]+abs(R[to[i]]-R[k1]));
	}
}
signed main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(L[i]),rd(R[i]),lnk[i]=0;
		pp=0;
		rep(i,1,n-1){
			int k1,k2;
			rd(k1),rd(k2);
			ae(k1,k2),ae(k2,k1);
		}
		dfs1(1,0);
		pt(max(f[1][0],f[1][1]),'\n');
	}
	return 0;
}