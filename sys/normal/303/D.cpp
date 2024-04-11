#include <bits/stdc++.h>
using namespace std;

int n, x;
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x % n;
	while (y)
	{
		if (y & 1) ans = ans * now % n;
		now = now * now % n;
		y >>= 1;
	}
	return ans;
}
bool check(int y)
{
	if (y % n == 0) return false;
	int maxi = sqrt(n);
	for (int i = 2; i <= maxi; i++)
		if ((n - 1) % i == 0 && (fast_pow(y, i) == 1 || fast_pow(y, (n - 1) / i) == 1)) return false;
	return true;
}
bool is_prime(int x)
{
	int maxi = sqrt(x);
	for (int i = 2; i <= maxi; i++)
		if (x % i == 0) return false;
	return true;
}
int main()
{
	scanf("%d%d", &n, &x);
	n++;
	if (!is_prime(n)) return puts("-1"), 0;
	for (int i = x - 1; i >= 2; i--)
		if (check(i))
			return printf("%d\n", i), 0;
	return puts("-1"), 0;
}