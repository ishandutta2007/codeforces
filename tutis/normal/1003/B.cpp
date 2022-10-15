/*input
5 3 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int a, b, x;
	cin >> a >> b >> x;
	string X = "";
	if (a >= b)
	{
		X = "0";
		a--;
	}
	else
	{
		X = "1";
		b--;
	}
	while (X.size() <= x)
	{
		if (X.back() == '0')
		{
			X.push_back('1');
			b--;
		}
		else
		{
			X.push_back('0');
			a--;
		}
	}
	for (char x : X)
	{
		if (x == '0')
		{
			while (a > 0)
			{
				cout << '0';
				a--;
			}
		}
		if (x == '1')
		{
			while (b > 0)
			{
				cout << '1';
				b--;
			}
		}
		cout << x;
	}

}