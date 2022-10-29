#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 1e5+10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
LL a[N],b[N],dp[N][2];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,n)scanf("%d",b+i);
	rep(i,1,n){
		dp[i][0] = max(dp[i-1][0],dp[i-1][1]+a[i]);
		dp[i][1] = max(dp[i-1][1],dp[i-1][0]+b[i]);
	}
	printf("%lld\n",max(dp[n][0],dp[n][1]));
	return 0;
}