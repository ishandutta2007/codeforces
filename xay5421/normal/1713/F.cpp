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
const int N=1<<20;
int n,a[N];
int main(){
	rd(n);
	int m=1;
	while(m<n)m<<=1;
	rep(i,0,n-1){
		rd(a[i]);
	}
	reverse(a,a+m);
	for(int i=1;i<m;i<<=1)for(int j=0;j<m;j+=i<<1)for(int k=0;k<i;++k){
		a[i+j+k]^=a[j+k];
	}
	for(int i=1;i<m;i<<=1)for(int j=0;j<m;j+=i<<1)for(int k=0;k<i;++k){
		a[j+k]^=a[i+j+k];
	}
	rep(i,n,m-1)a[i]=0;
	for(int i=1;i<m;i<<=1)for(int j=0;j<m;j+=i<<1)for(int k=0;k<i;++k){
		a[j+k]^=a[i+j+k];
	}
	reverse(a,a+n);
	rep(i,0,n-1)printf("%d ",a[i]);
	return 0;
}