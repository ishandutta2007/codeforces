#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int N = 200200;
int n;
int ans;
ll k;
ll a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &k);
	for (int i = 0; i <= n; i++)
		scanf("%lld", &a[i]);
	ll curVal = 0;
	int id = 0;
	while(id <= n)
	{
		if (curVal & 1) break;
		curVal /= 2;
		curVal += a[id];
		id++;
	}
	ll y = 0;
	for (int i = n; i >= id; i--)
	{
		y = (y * 2) + a[i];
		if (abs(y) > 3 * k)
		{
			printf("0\n");
			return 0;
		}
	}
	y = (y * 2) + curVal;
	for (int i = id - 1; i >= 0; i--)
	{
		if (abs(y) > 3 * k) break;
		ll x = a[i] - y;
//		printf("%d %lld\n", i, x);
		if (-k <= x && x <= k && (i != n || x != 0))
			ans++;
		y *= 2;
	}
	printf("%d\n", ans);

	return 0;
}