/*input
2 3
4 2
5 7 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int a[n];
	int b[m];
	for (int &i : a)
		cin >> i;
	for (int &i : b)
		cin >> i;
	sort(a, a + n);
	sort(b, b + m);
	for (int i : a)
	{
		for (int j : b)
		{
			if (i == j)
			{
				cout << i << "\n";
				return 0;
			}
		}
	}
	int mini = 100;
	for (int i : a)
	{
		for (int j : b)
		{
			mini = min(mini, 10 * i + j);
			mini = min(mini, 10 * j + i);
		}
	}
	cout << mini << "\n";
}