#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 10007;
const int N = 100100;
ll a[N];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i] * a[n - 1 - i];
	printf("%lld\n", ans % MOD);

	return 0;
}