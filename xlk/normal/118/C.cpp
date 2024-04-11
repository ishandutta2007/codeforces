#include <bits/stdc++.h>
using namespace std;
int n, k, zc = 1e9;
string s, zt;
pair<int, int> a[10020];
int main()
{
	cin >> n >> k >> s;
	for (char d = '0'; d <= '9'; d++)
	{
		for (int i = 0; i < n; i++)
		{
			a[i] = make_pair(abs(s[i] - d), (s[i] > d) ? (i - n) : (n - i));
		}
		sort(a, a + n);
		int c = 0;
		string t = s;
		for (int i = 0; i < k; i++)
		{
			c += a[i].first;
			t[n - abs(a[i].second)] = d;
		}
		if (zc > c)
		{
			zc = c;
			zt = t;
		}
		else if (zc == c)
		{
			zt = min(zt, t);
		}
	}
	cout << zc << endl << zt << endl;
	return 0;
}