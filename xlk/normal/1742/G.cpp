#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
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
		for (int i = 0, o = 0; i < 30 && i < n; o |= a[i++])
		{
			swap(a[i], *max_element(a + i, a + n, [&](int x, int y){return (x | o) < (y | o);}));
		}
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}