#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll n, k;
	scanf("%lld%lld", &n, &k);
	ll ans = 0;
	n--;
	for (int i = 0; i < k && n > 0; i++)
	{
		ans += 2 * n - 1;
		n -= 2;
	}
	printf("%lld\n", ans);

	return 0;
}