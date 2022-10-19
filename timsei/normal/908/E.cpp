#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map> 
using namespace std;

const int N = 1005;
const int mod = 1e9 + 7;

map<long long , int>Map;

int n , m , x , y;
long long a[N] , bel[N] , dp[N][N] , ans;
char s[N];

int main(void) {
	scanf("%d%d" , &m , &n);
	for(int i = 1;i <= n;++ i) {
		scanf("%s" , s + 1);
		for(int j = 1;j <= m;++ j) a[j] = a[j] * 2 + s[j] - '0';
	}
	for(int i = 1;i <= m;++ i) ++ Map[a[i]];
	bel[0] = 1;
	for(int i = 1;i <= m;++ i) {
		dp[i][1] = 1; bel[i] = 1;
		for(int j = 2;j <= i;++ j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % mod;
			bel[i] += dp[i][j];
			bel[i] %= mod;
		}
	}
	ans = 1;
	for(map<long long ,int>::iterator it = Map.begin();it != Map.end();++ it) ans = ans * bel[(it -> second)] % mod;
	cout << ans;
}