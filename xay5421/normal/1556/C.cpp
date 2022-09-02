// author: xay5421
// created: Sun Aug 29 22:52:12 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
typedef long long LL;
const int N=1005;
int n,c[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n)rd(c[i]);
	LL ans=0;
	rep(i,1,n)if(i&1){
		LL L=1,R=c[i];
		rep(j,i+1,n){
			if(j&1)L+=c[j],R+=c[j];
			else{
				L-=c[j],R-=c[j];
				if(R<0){
					ans+=R-L+1;
					break;
				}else if(L<0){
					ans+=-L;
					L=0;
				}
				if(L==0){
					++ans;
				}
			}
		}
	}
	pt(ans,'\n');
	return 0;
}