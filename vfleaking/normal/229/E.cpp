#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxN = 1000;
const int MaxM = 1000;
const int MaxLenV = 1000;

int main()
{
	static double comb[MaxN + 1][MaxN + 1];
	comb[0][0] = 1.0;
	for (int i = 1; i <= MaxN; i++)
	{
		comb[i][0] = 1.0;
		for (int j = 1; j <= i; j++)
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
	}

	int n, m;
	static vector<int> c[MaxM + 1];

	int lenV = 0;
	static int v[MaxLenV];

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int lenC;
		scanf("%d", &lenC);
		c[i].resize(lenC);
		for (int j = 0; j < lenC; j++)
		{
			scanf("%d", &c[i][j]);
			v[lenV++] = c[i][j];
		}
	}

	sort(v, v + lenV, greater<int>());
	int limit = v[n - 1];
	int nLimit = count(v, v + n, limit);
	
	static double f[MaxM + 1][MaxN + 1];
	static double g[MaxM + 1][MaxN + 1];

	f[0][0] = 1.0;
	g[0][0] = 1.0;
	for (int i = 1; i <= m; i++)
	{
		int lenC = c[i].size();
		int nGreater = 0, nEqual = 0;
		for (vector<int>::iterator j = c[i].begin(); j != c[i].end(); j++)
		{
			if (*j > limit)
				nGreater++;
			else if (*j == limit)
				nEqual++;
		}

		g[i][0] = 1.0;
		f[i][0] = f[i - 1][0] / comb[lenC][nGreater];

		for (int j = 1; j <= nLimit; j++)
		{
			g[i][j] = 0.0;
			f[i][j] = 0.0;

			for (int k = 0; k <= nEqual; k++)
				g[i][j] += g[i - 1][j - k];
			for (int k = 0; k <= nEqual; k++)
				f[i][j] += f[i - 1][j - k] / comb[lenC][nGreater + k];
		}
	}

	cout << setprecision(9) << fixed;
	cout << f[m][nLimit] / g[m][nLimit] << endl;

	return 0;
}