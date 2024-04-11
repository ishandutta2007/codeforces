#include <bits/stdc++.h>
using namespace std;
int n, m, k, z;
int f[2520];
int c[2520];
int v[2520];
string s[60];
vector<pair<int, int> > a;
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
		c[y] += c[x];
	}
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.')
			{
				f[i * m + j] = i * m + j;
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
				{
					c[i * m + j] = -2500;				
				}
				else
				{
					c[i * m + j] = 1;				
				}
				if (i > 0 && s[i - 1][j] == '.')
				{
					U(i * m + j, i * m + j - m);
				}
				if (j > 0 && s[i][j - 1] == '.')
				{
					U(i * m + j, i * m + j - 1);
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++)
	{
		if (f[i] == i && c[i] > 0)
		{
			a.push_back(make_pair(c[i], i));
		}
	}
	sort(a.begin(), a.end());
	for (int i = 0; i + k < a.size(); i++)
	{
		v[a[i].second] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.' && v[F(i * m + j)])
			{
				s[i][j] = '*';
				z++;
			}
		}
	}
	cout << z << endl;
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << endl;
	}
	return 0;
}