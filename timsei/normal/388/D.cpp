#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int mod = 1e9 + 7;

#define int long long

int dp[N][N][2] ,  n , m , A[N] , k , len;

int dfs(int pos , int lim , int x) {
	if(!pos) return 1;
	if(dp[pos][x][lim] != -1) {
		return dp[pos][x][lim];
	}
	int &res = dp[pos][x][lim];
	res = 0;
	int up = (lim) ? A[pos] : 1;
//	cerr << pos << " "<< lim <<" "<< x << " "<< up << endl;
	if(up == 1) {
		res += dfs(pos - 1 , lim && (1 == up) , x + 1);
//		cerr << res << endl;
		res %= mod;
		if(res >= mod) res -= mod;
	}
	if(!x) {
		res += dfs(pos - 1 , lim && (up == 0) , x);
//		cerr << res << endl;
		res %= mod;
		return res;
	}
	for(int i = 0;i <= up;++ i) {
		res = (res + dfs(pos - 1 , lim && (i == up) , x) % mod * ((1ll << (x - 1)) % mod)) % mod;
	}
	return res;
}

main(void) {
	cin >> k;
	memset(dp , -1 , sizeof(dp));
	while(k) {
		A[++ len] = k % 2;
		k /= 2;
	}
	cout << dfs(len , 1 , 0) << endl;
}