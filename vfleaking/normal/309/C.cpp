#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 1000000;
const int MaxB = 30;

int main()
{
	int n, m;
	static int a[MaxN];
	static int bcnt[MaxB + 1];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
	{
		int b;
		scanf("%d", &b);
		bcnt[b]++;
	}

	int res = 0;
	for (int b = 0, k = 0; b <= MaxB; b++)
	{
		for (int i = 0; i < n && k <= b; i++)
			if (a[i] >> b & 1)
			{
				a[i] ^= 1 << b;
				int rest = 1 << b;
				while (k <= b && rest >= (1 << k))
				{
					if (bcnt[k] == 0)
						k++;
					else
					{
						int cur = min(bcnt[k], rest >> k);
						res += cur;
						bcnt[k] -= cur;
						rest -= cur << k;
					}
				}
			}
	}

	cout << res << endl;

	return 0;
}