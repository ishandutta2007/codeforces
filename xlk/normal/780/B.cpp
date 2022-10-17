#include <bits/stdc++.h>
using namespace std;
int n;
int x[60020];
int v[60020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	double L = 0, R = 1e9;
	for (int _ = 0; _ < 100; _++)
	{
		double M = (L + R) / 2;
		double lmax = 0, rmin = 1e9;
		for (int i = 0; i < n; i++)
		{
			lmax = max(lmax, x[i] - v[i] * M);
			rmin = min(rmin, x[i] + v[i] * M);
		}
		if (lmax < rmin)
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	cout << fixed << setprecision(13) << R << endl;
	return 0;
}