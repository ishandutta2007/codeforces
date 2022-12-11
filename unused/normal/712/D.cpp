#include <stdio.h>
#include <algorithm>
using namespace std;

int dp1[210000], dp2[210000];
constexpr int MOD = (int)1e9 + 7;

int main()
{
	int a,b,k,t;
	scanf("%d%d%d%d",&a,&b,&k,&t);
	k = k * 2 + 1;

	dp1[0] = 1;
	int *d1 = dp1, *d2 = dp2;

	for (int i = 0; i < t; i++)
	{
		d2[0] = d1[0];
		for (int j = 1; j < k; j++)
		{
			d2[j] = (d2[j-1] + d1[j]) % MOD;
		}
		for (int j = k; j <= 200100; j++)
		{
			d2[j] = ((d2[j-1] + d1[j] - d1[j-k]) % MOD + MOD) % MOD;
		}
		swap(d1, d2);
	}

	int ans = 0;
	int sum = 0;
	bool flip = false;

	if (a > b)
	{
		flip = true;
		swap(a, b);
		a++;
	}

	int diff = b - a + 1;
	for (int i = diff; i <= 200100; i++)
	{
		sum = (sum + d1[i-diff]) % MOD;
		ans = (ans + (long long)d1[i] * sum) % MOD;
	}

	if (flip)
	{
		int total = 1;
		for (int i = 0; i < 2 * t; i++) total = (long long)total * k % MOD;
		ans = (total - ans + MOD) % MOD;
	}

	printf("%d", ans);
}