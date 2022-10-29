#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL P = 1e9+7;
const int N = 105;

int n, k;
LL m;
LL C[N][N], D[N], E[N], dp[N][N*N];

LL pw(LL x, LL n){
	LL res=1;
	for(;n;n>>=1,x=x*x%P) if(n&1) res=res*x%P;
	return res;
}

int main(){
	cin>>n>>m>>k;
	
	rep(i,0,n) rep(j,0,i) C[i][j] = j ? (C[i-1][j-1] + C[i-1][j]) % P : 1;
	rep(j,0,n) D[j] = pw(C[n][j], m/n), E[j] = D[j] * C[n][j] % P;
	
	dp[0][0] = 1;
	rep(i,1,n)rep(j,0,k)
		rep(x,max(0,j-n),j)
			(dp[i][j] += dp[i-1][x] * (i>m%n ? D[j-x] : E[j-x]) ) %= P;
	cout<<dp[n][k]<<endl;
	return 0;
}