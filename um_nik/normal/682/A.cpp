#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll a[2][5];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < 2; i++)
	{
		int x;
		scanf("%d", &x);
		for (int j = 1; j <= x; j++)
			a[i][j % 5]++;
	}
	ll ans = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if ((i + j) % 5 == 0)
				ans += a[0][i] * a[1][j];
	printf("%lld\n", ans);

	return 0;
}