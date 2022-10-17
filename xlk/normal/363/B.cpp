#include <bits/stdc++.h>
using namespace std;
int n, k, s, z = 1e9, zi;
int a[150020];
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s += a[i];
		if (i > k)
		{
			s -= a[i - k];
		}
		if (i >= k && z > s)
		{
			z = s;
			zi = i - k + 1;
		}
	}
	cout << zi << endl;
	return 0;
}