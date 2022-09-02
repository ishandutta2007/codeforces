// author: xay5421
// created: Tue Jun  1 08:50:41 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
const int N=1000005;
int n,m,K,a[N],b[N],p[N];
int s,t,f[2][(1<<20)+5];
void input(int&x){
	x=0;
	rep(i,0,K-1){
		int c;
		while(!isdigit(c=getchar()));
		if(c=='1')x|=1<<i;
	}
}
int main(){
	/*freopen("option.in","r",stdin);
	freopen("option.out","w",stdout);*/
	rd(n),rd(m),rd(K);
	input(s),input(t);
	rep(i,1,n)rd(a[i]),rd(b[i]);
	rep(i,1,K)p[i]=i;
	memset(f[0],63,sizeof(f[0]));
	memset(f[1],192,sizeof(f[1]));
	f[0][s]=f[1][t]=n+1;
	per(i,n,1){
		swap(p[a[i]],p[b[i]]);
		int x=0,y=0;
		rep(j,1,K){
			if(s>>(j-1)&1)x|=1<<(p[j]-1);
			if(t>>(j-1)&1)y|=1<<(p[j]-1);
		}
		umin(f[0][x],i);
		umax(f[1][y],i);
	}
	int w=K-__builtin_popcount(s)-__builtin_popcount(t);
	int ans=-1,ansl=-1,ansr=-1;
	per(i,(1<<K)-1,0){
		rep(j,0,K-1)if(~i>>j&1){
			umin(f[0][i],f[0][i^(1<<j)]);
			umax(f[1][i],f[1][i^(1<<j)]);
		}
		if(f[1][i]-f[0][i]>=m){
			int now=__builtin_popcount(i)*2+w;
			if(ans<now){
				ans=now;
				ansl=f[0][i],ansr=f[1][i]-1;
			}
		}
	}
	printf("%d\n%d %d\n",ans,ansl,ansr);
	return 0;
}