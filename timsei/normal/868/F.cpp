#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define int long long

const int N = 100005;
const int K = 25;

int dp[N][K] , n , a[N] , state[N] , k , L , R , ans , f[N][K];

int get(int x , int y) {
	while(R < y) ans += state[a[++ R]] ++;
	while(R > y) ans -= -- state[a[R --]];
	while(L > x) ans += state[a[-- L]] ++;
	while(L < x) ans -= -- state[a[L ++]];
	return ans;
}

void solve(int k , int l , int r, int al , int ar) {
	if(l > r) return;
	int mid = (l + r) >> 1;
	dp[mid][k] = 1e18;
	for(int i = al;i <= min(ar , mid - 1);i ++) {
		if(dp[mid][k] >= dp[i][k - 1] + get(i + 1 , mid)) {
			dp[mid][k] = dp[i][k - 1] + get(i + 1 , mid);
			f[mid][k] = i;
		}
	}
	solve(k , l , mid - 1 , al , f[mid][k]);
	solve(k , mid + 1 , r , f[mid][k] , ar); 
}

main(void) {
	scanf("%lld%lld",&n,&k);
	for(int i = 1;i <= n;i ++) scanf("%lld",&a[i]);
	L = 1 , R = 0;
	for(int i = 1;i <= n;i ++) dp[i][0] = get(1 , i);
	for(int i = 1;i <= k;i ++) {
		solve(i , 1 , n , i , n - 1);
	}
	printf("%lld\n" , dp[n][k - 1]);
}