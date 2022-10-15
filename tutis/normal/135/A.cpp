/*input
5
1 2 3 4 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int &i : a)
		cin >> i;
	if (n == 1)
	{
		if (a[0] == 1)
			cout << "2\n";
		else
			cout << "1\n";
		return 0;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			if (a[i] != 1)
				cout << a[i - 1] << "\n";
			else
				cout << "2\n";
		}
		else if (i == 0)
			cout << "1 ";
		else
			cout << a[i - 1] << " ";
	}
	return 0;
}