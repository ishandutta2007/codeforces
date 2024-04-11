#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n;
long long k, a[N];

long long abs(long long a) 
{
	if (a < 0) return -a;
	return a;
}

long long mod(long long a, long long b) 
{
	a %= b;
	if (a < 0) a += b;
	return a;
}

long long gcd(long long a, long long b) 
{
	a = abs(a);
	b = abs(b);
	while (a && b) {
		if (a > b) a = mod(a, b);
		else b = mod(b, a);
	}
	return a + b;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &k);
		for (int i = 0; i < n; ++i) scanf("%lld", a + i);
		std::sort(a, a + n);
		long long g = 0;
		for (int i = 1; i < n; ++i) g = gcd(g, a[i] - a[i - 1]);
		if (mod(a[0], g) == mod(k, g)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}