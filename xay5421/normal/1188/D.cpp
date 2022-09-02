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
const int N=200005;
int n,id[N],new_id[N],sum[N],f[2][N];
LL a[N];
inline void umin(int&x,int y){if(y<x)x=y;}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n)rd(a[i]);
	swap(a[n],*max_element(a+1,a+n+1));
	rep(i,1,n)a[i]=a[n]-a[i];
	rep(i,1,n)id[i]=i;
	memset(f[0],63,sizeof(f[0]));
	f[0][n]=0;
	rep(bit,0,60){
		memset(f[~bit&1],63,sizeof(f[~bit&1]));
		int l=0,r=n;
		rep(i,1,n)if(~a[id[i]]>>bit&1)new_id[++l]=id[i];
		per(i,n,1)if(a[id[i]]>>bit&1)new_id[r--]=id[i];
		
		rep(i,1,n){
			sum[i]=sum[i-1]+(a[id[i]]>>bit&1);
		}
		
		
		rep(i,0,n){
			int l1=sum[i],l0=i-l1;
			int r1=sum[n]-sum[i],r0=(n-i)-r1;
			// choose 0
			umin(f[~bit&1][l0+r0+l1],f[bit&1][i]+l1+r0);
			
			// choose 1
			umin(f[~bit&1][l0],f[bit&1][i]+l0+r1);
		}
		
		rep(i,1,n)id[i]=new_id[i];
		
		/*D("f[%d]:",bit+1);
		rep(i,0,n){
			D("%d ",f[~bit&1][i]);
		}
		D("\n");*/
	}
	printf("%d\n",f[1][n]);
	return 0;
}