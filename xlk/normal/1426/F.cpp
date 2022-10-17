#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n;
long long z = 1, a, b, c;
string s;
int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'a')
		{
			a = (a + z) % p;
		}
		else if (s[i] == 'b')
		{
			b = (b + a) % p;
		}
		else if (s[i] == 'c')
		{
			c = (c + b) % p;
		}
		else if (s[i] == '?')
		{
			c = (3 * c + b) % p;
			b = (3 * b + a) % p;
			a = (3 * a + z) % p;
			z = (3 * z) % p;
		}
	}
	cout << c << endl;
	return 0;
}