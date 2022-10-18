#include <iostream>
#include <cstdio>
using namespace std;

const int Mod = 1000000007;

const int MaxN = 1000000;

int main()
{
	int n;
	static int a[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	static int f[1 << 20];
	for (int i = 0; i < n; i++)
		f[a[i]]++;
	for (int j = 20 - 1; j >= 0; j--)
		for (int sta = (1 << 20) - 1; sta >= 0; sta--)
			if ((sta & (1 << j)) == 0)
				f[sta] += f[sta ^ 1 << j];

	static int prePow2[MaxN + 1];
	prePow2[0] = 1;
	for (int x = 1; x <= n; x++)
		prePow2[x] = (prePow2[x - 1] * 2) % Mod;

	int res = 0;
	for (int sta = 0; sta < (1 << 20); sta++)
	{
		int c = 0;
		for (int i = 0; i < 20; i++)
			c += sta >> i & 1;
		if (c % 2 == 0)
			res = (res + prePow2[f[sta]] - 1) % Mod;
		else
			res = (res + Mod - prePow2[f[sta]] + 1) % Mod;
	}
	cout << res << endl;

	return 0;
}