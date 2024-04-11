#include <bits/stdc++.h>
using namespace std;
int n, z;
int f[256];
string s;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x != y)
	{
		f[x] = y;
		z--;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (f[s[j]] == 0)
			{
				f[s[j]] = s[j];
				z++;
			}
		}
		for (int j = 1; j < s.size(); j++)
		{
			U(s[j - 1], s[j]);
		}
	}
	cout << z << endl;
	return 0;
}