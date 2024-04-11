#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[320];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0, j = n; i < j;)
		{
			cout << a[i++] << " ";
			if (i < j)
			{
				cout << a[--j] << " ";				
			}
		}
		cout << endl;
	}
	return 0;
}