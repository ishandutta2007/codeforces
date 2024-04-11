#include <bits/stdc++.h>
using namespace std;
int t, n;
string s[200020];
int a[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		int z = 0;
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[j] = 0;
				for (int k = 0; k < s[j].size(); k++)
				{
					if (s[j][k] == 'a' + i)
					{
						a[j]++;
					}
					else
					{
						a[j]--;
					}
				}
			}
			sort(a, a + n, greater<int>());
			int s = 0;
			for (int j = 0; j < n; j++)
			{
				s += a[j];
				if (s > 0)
				{
					z = max(z, j + 1);
				}
				else
				{
					break;
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}