#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[22];
int z, zi, zj;
bool ok(int x, int y)
{
	set<string> t;
	for (int i = 0; i < n; i += x)
	{
		for (int j = 0; j < m; j += y)
		{
			string o0, o1, o2, o3;
			for (int k = 0; k < x; k++)
			{
				for (int l = 0; l < y; l++)
				{
					o0 += s[i + k][j + l];
				}
			}
			o2 = o0;
			reverse(o2.begin(), o2.end());
			if (x == y)
			{				
				for (int l = y - 1; l >= 0; l--)
				{
					for (int k = 0; k < x; k++)
					{
						o1 += s[i + k][j + l];
					}
				}
				o3 = o1;
				reverse(o3.begin(), o3.end());
				t.insert(min(min(o0, o2), min(o1, o3)));			
			}
			else
			{
				t.insert(min(o0, o2));			
			}
		}
	}
	return t.size() == n * m / x / y;
}
int main()
{
	cin >> n >> m;
	zi = n;
	zj = m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			for (int j = 1; j <= m; j++)
			{
				if (m % j == 0)
				{
					if (ok(i, j))
					{
						z++;
						if (zi * zj > i * j)
						{
							zi = i;
							zj = j;
						}
					}
				}
			}
		}
	}
	cout << z << endl << zi << " " << zj << endl;
	return 0;
}