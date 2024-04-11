#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

const int MaxN = 1000;

int main()
{
	int n, m;
	static int a[MaxN + 1];
	static double p[MaxN + 1][MaxN + 1];
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			p[i][j] = a[i] > a[j];
	
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		
		for (int i = 1; i <= n; i++)
			if (i != a && i != b)
			{
				p[i][a] = p[i][b] = (p[i][a] + p[i][b]) / 2.0;
				p[a][i] = p[b][i] = (p[a][i] + p[b][i]) / 2.0;
			}
		p[a][b] = p[b][a] = 0.5;
	}
	
	double res = 0.0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			res += p[i][j];
	cout << fixed << setprecision(8) << res << endl;
	
	return 0;
}