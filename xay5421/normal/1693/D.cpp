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
const int N=200005,INF=0X3F3F3F3F;
int n,a[N],f[N],dp1[N],dp2[N];
int calc(int i){
	if(i>n)return 0;
	int x=~INF,y=INF;
	if(dp1[i-1]>a[i]){
		y=min(y,a[i-1]);
	}
	if(a[i-1]>a[i]){
		y=min(y,dp2[i-1]);
	}
	if(dp2[i-1]<a[i]){
		x=max(x,a[i-1]);
	}
	if(a[i-1]<a[i]){
		x=max(x,dp1[i-1]);
	}
	if(x==~INF&&y==INF){
		return f[i]=0;
	}
	if(x==dp1[i]&&y==dp2[i])return f[i];
	dp1[i]=x,dp2[i]=y;
	return f[i]=calc(i+1)+1;
}
int main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	LL ans=0;
	per(i,n,1){
		dp1[i]=INF;
		dp2[i]=~INF;
		f[i]=calc(i+1)+1;
		ans+=f[i];
	}
	printf("%lld\n",ans);
	return 0;
}