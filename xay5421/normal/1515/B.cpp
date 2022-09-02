// author: xay5421
// created: Sun May  2 22:55:34 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int T;
bool issqr(int x){
	int y=sqrt(x);
	while(1LL*y*y<x)++y;
	while(1LL*y*y>x)--y;
	return 1LL*y*y==x;
}
int main(){
	rd(T);
	while(T--){
		int n;
		rd(n);
		if((n%2==0&&issqr(n/2))||(n%4==0&&issqr(n/4)))puts("YES");else puts("NO");
	}
	return 0;
}