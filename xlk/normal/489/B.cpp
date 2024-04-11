#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int a[120], b[120];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);
	for (int i = 0, j = 0; i < n && j < m;)
	{
		if (abs(a[i] - b[j]) < 2)
		{
			z++;
			i++;
			j++;
		}
		else if (a[i] < b[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	cout << z << endl;
	return 0;
}