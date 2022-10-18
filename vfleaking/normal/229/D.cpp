#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 5000;

int main()
{
	int n;
	static int h[MaxN + 1];

	static int f[MaxN + 1];
	static int g[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &h[i]);

	f[0] = 0, g[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i] = 0;
		for (int j = i; j > 0; j--)
		{
			f[i] += h[j];
			if (f[i] >= f[j - 1])
			{
				g[i] = g[j - 1] + i - j;
				break;
			}
		}
	}

	cout << g[n] << endl;

	return 0;
}