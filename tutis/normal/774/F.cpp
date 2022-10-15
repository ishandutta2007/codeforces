/*input
3
3 3 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int b[n];
	fill_n(b, n, 0);
	for (int i = 0; i < n * 7; i++)
	{
		if (i % 7 != 6)
			b[i % n]++;
	}
	int bent = 1e9;
	for (int i = 0; i < n; i++)
		if (b[i] != 0)
			bent = min(bent, a[i] / b[i] - 1);
	bent = max(bent, 0);
	for (int i = 0; i < n; i++)
		a[i] -= bent * b[i];
	while (true)
	{
		for (int i = 0; i < n * 7; i++)
		{
			if (i % 7 != 6)
			{
				a[i % n]--;
				if (a[i % n] == 0)
				{
					cout << i % n + 1 << "\n";
					return 0;
				}
			}
		}
	}
}