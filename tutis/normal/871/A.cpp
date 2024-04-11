/***
3
1
2
3
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int q;
	cin >> q;
	while (q--)
	{
		ll n;
		cin >> n;
		if (n % 4 == 0)
		{
			cout << n / 4 << "\n";
		}
		if (n % 4 == 1)
		{
			if (n >= 9)
				cout << (n - 9) / 4 + 1 << "\n";
			else
				cout << -1 << "\n";
		}
		if (n % 4 == 2)
		{
			if (n >= 6)
				cout << (n - 6) / 4 + 1 << "\n";
			else
				cout << -1 << "\n";
		}
		if (n % 4 == 3)
		{
			if (n >= 15)
				cout << (n - 15) / 4 + 2 << "\n";
			else
				cout << -1 << "\n";
		}
	}
}