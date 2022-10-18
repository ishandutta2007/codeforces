#include <iostream>
#include <cstdio>
using namespace std;

const int Mod = 1000000007;

const int MaxN = 1000;
const int MaxV = 10000;
const int MaxU = MaxV * 2;

inline void addF(int *f, const int &v)
{
	static int g[MaxU + 1];
	for (int k = -MaxV; k <= MaxV; k++)
	{
		g[MaxV + k] = 0;
		if (k - v >= -MaxV)
			g[MaxV + k] += f[MaxV + k - v];
		if (k + v <= MaxV)
			g[MaxV + k] += f[MaxV + k + v];
		if (g[MaxV + k] >= Mod)
			g[MaxV + k] -= Mod;
	}
	for (int k = 0; k <= MaxU; k++)
		f[k] = g[k];
}

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int res = 0;

	static int f[MaxV * 2 + 1];
	f[MaxV] = 0;
	for (int le = n; le >= 1; le--)
	{
		f[MaxV]++;
		if (f[MaxV] >= Mod)
			f[MaxV] -= Mod;

		addF(f, a[le]);

		res += f[MaxV];
		if (res >= Mod)
			res -= Mod;
	}

	cout << res << endl;

	return 0;
}