// author: xay5421
// created: Tue Aug 24 22:36:21 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int T;
bool vis[200005];
int main(){
	rd(T);
	while(T--){
		int a,b;
		rd(a),rd(b);
		rep(i,0,a+b+1)vis[i]=0;
		int n=a+b;
		rep(x,0,(n+1)/2)if(x<=a){
			int y=a-x;
			if(y<=n/2)vis[(n+1)/2-x+y]=1;
		}
		rep(x,0,n/2)if(x<=a){
			int y=a-x;
			if(y<=(n+1)/2)vis[n/2-x+y]=1;
		}
		int cnt=0;
		rep(i,0,a+b+1)if(vis[i])++cnt;
		pt(cnt,'\n');
		rep(i,0,a+b+1)if(vis[i])pt(i,' ');
		puts("");
	}
	return 0;
}