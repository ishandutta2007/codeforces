/*input
4
4
1 -2 3 -4
3
0 0 0
5
1 -1 1 -1 1
6
40 -31 -9 0 13 -40

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n, greater<int>());
		int s = 0;
		for (int i : a)
		{
			s += i;
		}
		if (s < 0)
			reverse(a, a + n);
		s = 0;
		for (int i : a)
		{
			s += i;
			if (s == 0)
			{
				cout << "NO\n";
				goto X;
			}
		}
		cout << "YES\n";
		for (int i : a)
			cout << i << " ";
		cout << "\n";
X:;
	}
}