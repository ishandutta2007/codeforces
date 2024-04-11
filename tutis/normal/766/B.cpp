/**
5
1 5 3 2 4
**/
#include <bits/stdc++.h>

using namespace std;

int main ()
{
	long long n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 2; i < n; i++)
	{
		if (a[i - 1] + a[i - 2] > a[i])
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}