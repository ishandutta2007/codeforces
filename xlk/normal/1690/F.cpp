#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
char c[202];
int p[202];
int v[202];
ll lcm(ll x, ll y)
{
	return x / __gcd(x, y) * y;
}
int F(string s)
{
	int n = s.size();
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			if (s.substr(i) + s.substr(0, i) == s)
			{
				return i;
			}
		}
	}
	return n;
}

int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		cin >> c + 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i];
			v[i] = 0;
		}
		ll z = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!v[i])
			{
				string s;
				for (int j = i; !v[j]; j = p[j])
				{
					s += c[j];
					v[j] = 1;
				}
				z = lcm(z, F(s));
			}
		}
		cout << z << endl;
	}
	return 0;
}