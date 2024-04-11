#include<bits/stdc++.h>
using namespace std;
char s[200020];
long long f[200020][2];
int t, n;
long long a, b;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		memset(f, 0x3f, sizeof f);
		cin >> n >> a >> b >> s;
		f[0][0] = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0')
			{
				f[i + 1][0] = min(f[i][0], f[i][1] + a + b);
				f[i + 1][1] = min(f[i][0] + a, f[i][1] + b);
			}
			else
			{
				f[i + 1][1] = f[i][1] + b;
			}
		}
		cout << f[n][0] + a * n + b * (n + 1) << endl;
	}
	return 0;
}