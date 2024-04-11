#include <bits/stdc++.h>
using namespace std;
int t, a, b, n;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b >> s;
		n = a + b;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '?')
			{
				s[i] = s[n - 1 - i];
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (s[i] != s[n - 1 - i])
			{
				a = -1;
				b = -1;
			}
			if (s[i] == '0')
			{
				a--;
			}
			else if (s[i] == '1')
			{
				b--;
			}
		}
		for (int i = 0; i <= n / 2; i++)
		{
			if (s[i] == '?')
			{
				if (i < n - i - 1)
				{
					if (a >= 2)
					{
						s[i] = '0';
						s[n - i - 1] = '0';
						a -= 2;
					}
					else if (b >= 2)
					{
						s[i] = '1';
						s[n - i - 1] = '1';
						b -= 2;
					}
				}
				else
				{
					if (a >= 1)
					{
						s[i] = '0';
						a -= 1;
					}
					else if (b >= 1)
					{
						s[i] = '1';
						b -= 1;
					}
				}
			}
		}
		if (a == 0 && b == 0)
		{
			cout << s << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
}