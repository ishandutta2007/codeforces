/*input
10 7
1.0.1.0.1.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	for (int i = 0; i < p; i++)
	{
		int yra = -1;
		for (int a = i; a < n; a += p)
		{
			if (s[a] != '.')
			{
				yra = a;
			}
		}
		if (yra == -1)
		{
			char x = '0';
			for (int a = i; a < n; a += p)
			{
				assert(s[a] == '.');
				s[a] = x;
				x = s[a];
				if (x == '0')
					x = '1';
				else if (x == '1')
					x = '0';
			}
		}
		else
		{
			char x = s[yra];
			for (int a = yra + p; a < n; a += p)
			{
				if (x == '0')
					x = '1';
				else if (x == '1')
					x = '0';
				if (s[a] == '.')
					s[a] = x;
				x = s[a];
			}
			x = s[yra];
			for (int a = yra - p; a >= 0; a -= p)
			{
				if (x == '0')
					x = '1';
				else if (x == '1')
					x = '0';
				if (s[a] == '.')
					s[a] = x;
				x = s[a];
			}
		}
	}
	bool yra = true;
	for (int i = 0; i + p < n; i++)
		if (s[i] != s[i + p])
			yra = false;
	if (yra)
		cout << "No\n";
	else
		cout << s << "\n";


}