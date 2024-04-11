/*input
3
1 2 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool Pdivs[15000009];
int a[15000009];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int cc = n;
	while (cc--)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	int ans = n + 1;
	for (int t = 2; t < 15000009; t++)
	{
		if (Pdivs[t] == false)
		{
			int Y = n;
			map<int, int>X;
			for (int i = t; i < 15000009; i += t)
			{
				Pdivs[i] = true;
				if (a[i] > 0)
				{
					int I = i;
					int alpha = 0;
					while (I % t == 0)
					{
						I /= t;
						alpha++;
					}
					X[alpha] += a[i];
					Y -= a[i];
				}
			}
			if (Y == 0)
			{
				auto it = X.begin();
				if (it != X.end())
				{
					ans = min(ans, it->second);
				}
			}
			else
				ans = min(ans, Y);
		}
	}
	if (ans >= n)
		ans = -1;
	cout << ans << "\n";
}