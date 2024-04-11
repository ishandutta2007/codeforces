/*input
2 7
2 2 2 2 2 2 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int k4 = n;
	int k2 = n * 2;
	int k1 = 0;
	int a3 = 0;
	int a2 = 0;
	int a1 = 0;
	while (k--)
	{
		int a;
		cin >> a;
		while (a >= 4)
		{
			if (k4 > 0)
			{
				k4--;
				a -= 4;
				continue;
			}
			if (k2 > 0)
			{
				k2--;
				a -= 2;
				continue;
			}
			cout << "NO\n";
			return 0;
		}
		if (a == 3)
			a3++;
		if (a == 2)
			a2++;
		if (a == 1)
			a1++;
	}
	while (a3 > 0)
	{
		if (k4 > 0)
		{
			k4--;
			a3--;
			continue;
		}
		if (k2 > 1)
		{
			k2 -= 2;
			a3--;
			continue;
		}
		cout << "NO\n";
		return 0;
	}
	while (a2 > 0)
	{
		if (k4 > 0)
		{
			k4--;
			k1++;
			a2--;
			continue;
		}
		if (k2 > 0)
		{
			k2--;
			a2--;
			continue;
		}
		if (k1 > 1)
		{
			k1 -= 2;
			a2--;
			continue;
		}
		cout << "NO\n";
		return 0;
	}
	while (a1 > 0)
	{
		if (k4 > 0)
		{
			k4--;
			k2++;
			a1--;
			continue;
		}
		if (k2 > 0)
		{
			k2--;
			a1--;
			continue;
		}
		if (k1 > 0)
		{
			k1--;
			a1--;
			continue;
		}
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
}