#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int MOD = 998244353;
const int N = 1005;
 
int n, k, ans=0, a[N], dp[N][N];
 
int modadd(int x, int y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}
 
int main(){
	cin>>n>>k;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	rep(x,1,(a[n]-a[1])/(k-1)){
		int prev = 0;
		rep(i,0,n) dp[i][0] = 1;
		rep(i,1,n){
			while(a[prev+1]+x<=a[i])++prev;
			rep(j,1,min(i,k)) dp[i][j] = modadd(dp[i-1][j], dp[prev][j-1]);
		}
		ans = modadd(ans, dp[n][k]); 
	}
	cout<<ans<<endl;
	return 0;
}