#include<cstdio>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;

int main() {
	int n;
	long long ans, sum[2], tmp;
	sum[0] = sum[1] = ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		tmp = 1 + sum[i % 2];
		ans = (ans + tmp) % MOD;
		sum[1 - i % 2] = (sum[1 - i % 2] + tmp) % MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}