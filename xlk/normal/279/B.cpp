#include <bits/stdc++.h>
using namespace std;
int n, t, z;
int a[100020];
int main()
{
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0, j = 0; i < n; t += a[i++])
	{
		while (j < n && a[j] <= t)
		{
			t -= a[j++];
		}
		z = max(z, j - i);
	}
	cout << z << endl;
	return 0;
}