#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int N = 401;
 
int a[N], dp[N-2][N][N];
int n, m, s, f, c, r;
 
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",a+i);
	rep(s,1,n)rep(f,s,n) dp[0][s][f] = a[f] - a[s];
	rep(r,1,n-2)rep(s,1,n-r-1){
		int j = s+r;
		rep(f,s+r+1,n){
			for(; j<f && max(dp[r-1][s][j],a[f]-a[j]) > max(dp[r-1][s][j+1],a[f]-a[j+1]); ++j);
			dp[r][s][f] = max(dp[r-1][s][j],a[f]-a[j]);
		}
	}
	LL ans = 0;
	rep(i,1,m){
		scanf("%d%d%d%d",&s,&f,&c,&r);
		ans = max(ans, 1ll * dp[min(r,f-s-1)][s][f] * c);
	}
	cout<<ans<<endl;
	return 0;
}