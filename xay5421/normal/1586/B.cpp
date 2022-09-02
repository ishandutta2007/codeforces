// author: xay5421
// created: Sun Oct 17 19:09:50 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int T,n,m,a[N],b[N],c[N];
bool vis[N];
int main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		fill(vis+1,vis+1+n,0);
		rep(i,1,m){
			rd(a[i]),rd(b[i]),rd(c[i]);
			vis[b[i]]=1;
		}
		int root=-1;
		rep(i,1,n)if(!vis[i]){
			root=i;
			break;
		}
		rep(i,1,n)if(i!=root){
			printf("%d %d\n",i,root);
		}
	}
	return 0;
}