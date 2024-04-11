#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int N = 2e5 + 5;

typedef long long LL;

LL x[N], ans , a , b;
int n , m , k , j;

map<LL,LL>dp;

map<LL,LL>::iterator it;

int main(void) {
	scanf("%d" , &n);
	for(int i = 1;i <= n;++ i) scanf("%lld", &x[i]);
	dp[x[1] - 1] = 0; x[n + 1] = 1;
	for(int i = 1;i < n;++ i) {
		while(1) {
			it = dp.lower_bound(x[i + 1]);
			if(it == dp.end()) break;
			a = it -> first , b = it ->second;
			dp.erase(a);
			dp[x[i + 1] - 1] = max(dp[x[i + 1] - 1] , i * (a - a % x[i + 1] - x[i + 1]) + b);
			dp[a % x[i + 1]] = max(dp[a % x[i + 1]] , i * (a - a % x[i + 1]) + b);
		}
	}
	for(it = dp.begin();it != dp.end();++ it) {
		ans = max(ans , dp[it -> first] + (it -> first) * n);
	}
	cout << ans;
}