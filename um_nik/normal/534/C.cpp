#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int N = (int)2e5 + 300;
int n;
ll a[N];
ll x;
ll sum;

int main()
{
	scanf("%d%I64d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
		sum += a[i];
	}

	for (int i = 0; i < n; i++)
	{
		ll ans = 0;
		sum -= a[i];
		if (sum + 1 < x)
			ans += (x - (sum + 1));
		sum += a[i];
		n += a[i] - 1;
		if (n > x)
			ans += n - x;
		n -= a[i] - 1;
		printf("%I64d ", ans);
	}
	printf("\n");

	return 0;
}