// author: xay5421
// created: Sun Aug  1 22:41:52 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005,K=20;
int T,n,lg[N];
LL a[N],b[N],f[N][K];
LL ask(LL l,LL r){
	int x=lg[r-l+1];
	return __gcd(f[l][x],f[r-(1<<x)+1][x]);
}
bool chk(LL g){
	if(!g)return 1;
	return g>=2;
}
int main(){
	rep(i,2,N-1)lg[i]=lg[i>>1]+1;
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n){
			rd(a[i]),b[i]=abs(a[i]-a[i-1]);
			f[i][0]=b[i];
		}
		rep(j,1,K-1){
			rep(i,1,n-(1<<j)+1){
				f[i][j]=__gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
		int j=1,ans=1;
		rep(i,1,n){
			if(j<i)j=i;
			while(j<n&&chk(ask(i+1,j+1)))++j;
			ans=max(ans,j-i+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}