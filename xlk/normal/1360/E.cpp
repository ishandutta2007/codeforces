#include <bits/stdc++.h>
using namespace std;
int t, n;
char s[60][60];
bool ok()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (s[i][j] == '1' && s[i][j + 1] == '0' && s[i + 1][j] == '0')
			{
				return false;
			}
		}
	}
	return true;
}
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
		puts(ok() ? "YES" : "NO");
	}
	return 0;
}