#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int P = 998244353, N = 2005;
 
char a[N];
int n, pw2[N], cnt[N], dp[N][N];
 
void madd(int &x,int y){x+=y;if(x>=P)x-=P;}
 
int main(){
	scanf("%s",a+1);
	n = strlen(a+1);
	rep(i,1,n) cnt[i]=cnt[i-1]+(a[i]=='?');
	pw2[0] = 1;
	rep(i,1,n) madd(pw2[i],pw2[i-1]<<1);
	rep(d,1,n) rep(l,1,n-d){
		int r = l+d;
		if(a[l]!='(') madd(dp[l][r], dp[l+1][r]);
		if(a[r]!=')') madd(dp[l][r], dp[l][r-1]);
		if(a[l]!='(' && a[r]!=')') madd(dp[l][r], P-dp[l+1][r-1]);
		if(a[l]!=')' && a[r]!='(') madd(dp[l][r], dp[l+1][r-1]), madd(dp[l][r], pw2[cnt[r-1]-cnt[l]]);
	}
	printf("%d\n",dp[1][n]);
	return 0;
}