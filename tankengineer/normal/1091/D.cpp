#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 998244353;
int n;

int main() {
	scanf("%d", &n);
	int ans = 0, fac = 1, sum = 0;
	for (int i = n; i > 0; --i) {
		fac = (long long)fac * i % MOD;
		if (i > 1) {
			sum = (sum + fac) % MOD;
		}
	}
	ans = (((long long)n * fac % MOD - sum) % MOD + MOD) % MOD;
	printf("%d\n", ans);
	return 0;
}