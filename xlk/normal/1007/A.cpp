#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (a[z] < a[i])
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}