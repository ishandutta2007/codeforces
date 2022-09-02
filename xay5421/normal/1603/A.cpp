// author: xay5421
// created: Sat Oct 30 22:35:34 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int T,n,a[N];
int main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		bool err=0;
		rep(i,1,n){
			if(i<=1000){
				bool flg=0;
				rep(j,1,i){
					if(a[i]%(j+1)!=0){
						flg=1;
					}
				}
				if(!flg){
					err=1;
				}
			}
		}
		puts(err?"NO":"YES");
	}
	return 0;
}