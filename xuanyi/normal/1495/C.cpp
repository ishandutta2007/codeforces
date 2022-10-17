// author: xay5421
// created: Wed Mar 10 21:51:46 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=505;
int T,n,m,a[N][N];
int main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,n){
			string s;
			cin>>s;
			s=" "+s;
			rep(j,1,m)if(s[j]=='X')a[i][j]=1;else a[i][j]=0;
		}
		for(int i=1;i+2<=n;i+=3){
			rep(j,1,m)a[i][j]=1;
			bool f=0;
			rep(j,1,m)if(a[i+1][j]||a[i+2][j]){
				a[i+1][j]=a[i+2][j]=1,f=1;break;
			}
			if(!f)a[i+1][1]=a[i+2][1]=1;
		}
		if(n%3==0){
			rep(j,1,m)if(a[n][j])a[n-1][j]=1;
		}else if(n%3==1){
			rep(j,1,m)a[n][j]=1;
		}else{
			rep(j,1,m)a[n-1][j]=1;
		}
		rep(i,1,n){
			rep(j,1,m)putchar(a[i][j]?'X':'.');
			puts("");
		}
	}
	return 0;
}