#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n;
string s;
int a[256];
int f[1020];
int g[1020];
int h;
int main()
{
	cin >> n >> s;
	for (int i = 'a'; i <= 'z'; i++)
	{
		cin >> a[i];
	}
	memset(g, 0x3f, sizeof g);
	f[0] = 1;
	g[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = n;
		for (int j = i - 1; j >= 0; j--)
		{
			l = min(l, a[s[j]]);
			if (i - j > l)
			{
				break;
			}
			h = max(h, i - j);
			f[i] = (f[i] + f[j]) % p; 
			g[i] = min(g[i], g[j] + 1);
		}
	}
	cout << f[n] << endl;
	cout << h << endl;
	cout << g[n] << endl;
	return 0;
}