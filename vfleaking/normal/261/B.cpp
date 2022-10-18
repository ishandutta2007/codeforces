#include <iostream>
#include <iomanip>
#include <numeric>
using namespace std;

const int MaxN = 50;
const int MaxP = 50;

int main()
{
	int n;
	static int a[MaxN + 1];
	int p;

	static double f[MaxP + 1][MaxN + 1];
	static double comb[MaxN + 1][MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> p;

	for (int i = 0; i <= n; i++)
	{
		comb[i][0] = 1;
		for (int j = 1; j <= n; j++)
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
	}

	if (accumulate(a + 1, a + n + 1, 0) <= p)
	{
		cout << n << endl;
		return 0;
	}

	double res = 0.0;
	for (int v = 1; v <= n; v++)
	{
		for (int i = 0; i <= p; i++)
			for (int j = 0; j <= n; j++)
				f[i][j] = 0;

		f[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (i == v)
				continue;
			for (int j = p; j >= a[i]; j--)
				for (int k = 1; k <= n; k++)
					f[j][k] += f[j - a[i]][k - 1];
		}


		for (int j = 1; j < n; j++)
		{
			double t = 0.0;
			for (int i = max(p - a[v] + 1, 0); i <= p; i++)
				t += f[i][j];
			res += j * t / (comb[n][j] * (n - j));
		}
	}
	cout << fixed << setprecision(7) << res << endl;

	return 0;
}