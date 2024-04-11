#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int T,n,a[N],X,dp[N][3];
long long sum[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		rd(X);
		rep(i,1,n){
			a[i]-=X;
		}
		dp[1][0]=0,dp[1][1]=1;
		rep(i,2,n){
			dp[i][0]=dp[i][1]=dp[i][2]=0;
			dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
			dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
			if(a[i-1]+a[i]>=0){
				dp[i][2]=max(dp[i][2],dp[i-1][1]+1);
			}
			if(i>=3&&a[i-1]+a[i]>=0&&a[i-2]+a[i-1]+a[i]>=0){
				dp[i][2]=max(dp[i][2],dp[i-1][2]+1);
			}
		}
		printf("%d\n",max({dp[n][0],dp[n][1],dp[n][2]}));
	}
	return 0;
}