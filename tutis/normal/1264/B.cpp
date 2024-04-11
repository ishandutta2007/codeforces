/*input
1 0 0 1
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a > 0 && b > 0 && c > 0 && d > 0)
	{
		b -= a;
		c -= d;
		int k = min(c, b);
		c -= k;
		b -= k;
		if (c > 1 || b > 1 || a < 0 || b < 0 || c < 0 || d < 0 || k < 0)
		{
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n";
		if (b > 0)
			cout << "1 ";
		while (a--)
			cout << "0 1 ";
		while (k--)
			cout << "2 1 ";
		while (d--)
			cout << "2 3 ";
		if (c > 0)
			cout << "2 ";
		return 0;
	}
	int k[4] = {a, b, c, d};
	int mn = 0;
	int mx = 3;
	while (k[mn] == 0)
		mn++;
	while (k[mx] == 0)
		mx--;
	int kiek = mx - mn + 1;
	if (kiek == 1)
	{
		if (a + b + c + d == 1)
		{
			cout << "YES\n";
			cout << mn << "\n";
			return 0;
		}
		else
		{
			cout << "NO\n";
		}
	}
	else if (kiek == 2)
	{
		int ka = k[mn];
		int kb = k[mx];
		if (abs(ka - kb) > 1)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
			int kk = min(ka, kb);
			ka -= kk;
			kb -= kk;
			if (kb > 0)
				cout << mx << " ";
			while (kk--)
				cout << mn << " " << mx << " ";
			if (ka > 0)
				cout << mn << " ";
		}
	}
	else if (kiek == 3)
	{
		int ka = k[mn];
		int kb = k[mn + 1];
		int kc = k[mx];
		ka--;
		kb--;
		kc--;
		int k3 = kc;
		kb -= k3;
		int k1 = ka;
		kb -= k1;
		if (ka < 0 || kb < 0 || kc < 0 || kb > 2)
		{
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n";
		if (kb > 0)
		{
			kb--;
			cout << mn + 1 << " ";
		}
		while (k1--)
			cout << mn << " " << mn + 1 << " ";
		cout << mn << " " << mn + 1 << " " << mx << " ";
		while (k3--)
			cout << mx - 1 << " " << mx << " ";
		if (kb > 0)
		{
			kb--;
			cout << mn + 1 << " ";
		}
	}
	else
		cout << "NO\n";
}