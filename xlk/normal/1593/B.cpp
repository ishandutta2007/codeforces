#include <bits/stdc++.h>
using namespace std;
int t, z;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> s;
		int n = s.size(), z = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((s[i] * 10 + s[j] - '0' * 11) % 25 == 0)
				{
					z = min(z, n - 2 - i);
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}