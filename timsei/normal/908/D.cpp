#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstdlib>
using namespace std;

#define int long long

const int N = 2e3 + 5;
const int mod = 1e9 + 7;

int n , m , x , y , pa , pb , all;

#define d(x) (x % mod)

int Pow(int x , int y) {
	if(x == 0) return 0;
	if(y == 1) return d(x);
	int it = Pow(x , y >> 1);
	it = d(it * it);
	if(y & 1) it = d(it * x);
	return it;
}

#define inv(x) Pow(x , mod - 2)
#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])
#define lowbit(x) (x & (-x))

int dp[N][N] , ans;

main(void) {
	scanf("%d%d%d" , &n , &pa , &pb);
	all = pa + pb;
	pa = d(pa * Pow(all , mod - 2)); pb = d(pb * Pow(all , mod - 2));
	int con = inv(pb) * pa % mod;
	dp[1][0] = 1;
	for(register int i = 1;i <= n;++ i) {
		for(register int j = 0;j <= n;++ j) {
			dp[i][j] %= mod;
			if(i + j >= n) {
				ans += ((i + j) + con) * dp[i][j] % mod;
				ans = d(ans);
			}
			
			else dp[i + 1][j] += dp[i][j] * pa % mod , dp[i][i + j] += dp[i][j] * pb % mod;
		}
	}
	printf("%lld\n" , ans);
}