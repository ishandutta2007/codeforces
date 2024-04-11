#include <bits/stdc++.h>
using namespace std;
int n, m, x, sa, sb;
int a[120], c;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		for (int i = 0; i < m / 2; i++)
		{
			cin >> x;
			sa += x; 
		}
		if (m & 1)
		{
			cin >> x;
			a[c++] = x;
		}
		for (int i = 0; i < m / 2; i++)
		{
			cin >> x;
			sb += x; 
		}
	}
	sort(a, a + c, greater<int>());
	for (int i = 0; i < c; i++)
	{
		if (i & 1)
		{
			sb += a[i];
		}
		else
		{
			sa += a[i];
		}
	}
	cout << sa << " " << sb << endl;
	return 0;
}