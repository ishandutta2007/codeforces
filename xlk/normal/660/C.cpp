#include <bits/stdc++.h>
using namespace std;
int n, m, zi, zj;
int a[300030];
int main()
{
	cin >> n >> m;
	for (int i = 0, j = 0, s = 0; i < n;)
	{
		cin >> a[i];
		s += !a[i++];
		if (s > m)
		{
			s -= !a[j++];
		}
		if (i - j > zi - zj)
		{
			zi = i;
			zj = j;
		}
	}
	cout << zi - zj << endl;
	for (int i = 0; i < n; i++)
	{
		cout << (a[i] || (zj <= i && i < zi)) << ' ';
	}
	cout << endl;
	return 0;
}