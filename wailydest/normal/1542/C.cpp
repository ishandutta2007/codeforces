#include <cstdio>

long long gcd(long long a, long long b) 
{
	while (a && b) {
		if (a > b) a %= b;
		else b %= a;
	}
	return a + b;
}

int t;
long long n;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		long long k = 1, ans = 0;
		for (int i = 2; k <= n; ++i) {
			long long l = k / gcd(k, i) * i;
			ans += (n / k - n / l) * i;
			ans %= 1000000007;
			k = l;
		}
		printf("%lld\n", ans);
	}
	return 0;
}