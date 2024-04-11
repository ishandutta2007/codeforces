/*input
5
1 3 6 9 12
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	if (n <= 2)
	{
		cout << "0\n";
		return 0;
	}
	map<pair<int, int>, int>X[n];
	for (int a = -1; a <= 1; a++)
	{
		for (int b = -1; b <= 1; b++)
		{
			X[1][ {a, b}] = 0;
			if (a != 0)
				X[1][ {a, b}]++;
			if (b != 0)
				X[1][ {a, b}]++;
		}
	}
	for (int i = 2; i < n; i++)
	{
		for (int a = -1; a <= 1; a++)
			for (int b = -1; b <= 1; b++)
				X[i][ {a, b}] = n + 10;
		for (int a = -1; a <= 1; a++)
		{
			for (int b = -1; b <= 1; b++)
			{
				for (int c = -1; c <= 1; c++)
				{
					if ((A[i - 1] + b) - (A[i - 2] + a) == (A[i] + c) - (A[i - 1] + b))
					{
						X[i][ {b, c}] = min(X[i][ {b, c}], X[i - 1][ {a, b}] + (c != 0));
					}
				}
			}
		}
	}
	int ans = n + 10;
	for (int a = -1; a <= 1; a++)
		for (int b = -1; b <= 1; b++)
			ans = min(ans, X[n - 1][ {a, b}]);
	if (ans > n)
		ans = -1;
	cout << ans << "\n";


}