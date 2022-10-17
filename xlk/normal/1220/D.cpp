#include <bits/stdc++.h>
using namespace std;
int n, z;
int c[64];
long long a[200020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		c[__builtin_ctzll(a[i])]++;
	}
	for (int i = 0; i < 64; i++)
	{
		if (c[z] < c[i])
		{
			z = i;
		}
	}
	cout << n - c[z] << endl;
	for (int i = 0; i < n; i++)
	{
		if (__builtin_ctzll(a[i]) != z)
		{
			cout << a[i] << ' ';
		}
	}
	cout << endl;
	return 0;
}