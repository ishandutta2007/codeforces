// author: xay5421
// created: Sun Nov 14 14:04:23 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int T,n,a[N],b[N];
int main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		rep(i,1,n)rd(b[i]);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		bool err=0;
		rep(i,1,n){
			if(a[i]+1!=b[i]&&a[i]!=b[i])err=1;
		}
		puts(err?"NO":"YES");
	}
	return 0;
}