#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		string a, b, z;
		cin >> n >> m >> k >> a >> b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int x = 0, y = 0;
		while (a.size() && b.size())
		{
			if (y == k || x < k && a[0] < b[0])
			{
				x++;
				y = 0;
				z += a[0];
				a.erase(0, 1);
			}
			else
			{
				x = 0;
				y++;
				z += b[0];
				b.erase(0, 1);
			}
		}
		cout << z << endl;
	}
	return 0;
}