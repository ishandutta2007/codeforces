/*input
5
zcabd
dbacz
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	a = " " + a;
	b = " " + b;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i < n - i + 1)
		{
			string x;
			x.push_back(a[i]);
			x.push_back(a[n - i + 1]);
			x.push_back(b[i]);
			x.push_back(b[n - i + 1]);
			sort(x.begin(), x.end());
			int gal = 2;
			if (x[0] == x[1] && x[2] == x[3])
				gal = 0;
			for (char t = 'a'; t <= 'z'; t++)
			{
				string x;
				x.push_back(t);
				x.push_back(a[n - i + 1]);
				x.push_back(b[i]);
				x.push_back(b[n - i + 1]);
				sort(x.begin(), x.end());
				if (x[0] == x[1] && x[2] == x[3])
					gal = min(gal, 1);
			}
			for (char t = 'a'; t <= 'z'; t++)
			{
				string x;
				x.push_back(a[i]);
				x.push_back(t);
				x.push_back(b[i]);
				x.push_back(b[n - i + 1]);
				sort(x.begin(), x.end());
				if (x[0] == x[1] && x[2] == x[3])
					gal = min(gal, 1);
			}
			ans += gal;
		}
		if (i == n - i + 1)
		{
			if (a[i] != b[i])
				ans++;
		}
	}
	cout << ans << "\n";
}