/*input
3
4
5 6 15 30
4
10 6 30 15
3
3 4 6

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int pp[202020];
int main()
{
	for (int i = 2; i < 202020; i++)
	{
		if (pp[i] == 0)
			for (int j = i; j < 202020; j += i)
				pp[j] = i;
	}
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		deque<ll>a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		while (a.size() > 100)
			a.pop_front();
		ll ans = a.back();
		for (int i = (int)a.size() - 1; i >= 0; i--)
		{
			for (int j = (int)a.size() - 1; j > i; j--)
			{
				if (a[j] % a[i] != 0)
				{
					ans = max(ans, a[i] + a[j]);
					for (int k = (int)a.size() - 1; k > j; k--)
					{
						if (a[k] % a[j] != 0 && a[k] % a[i] != 0)
							ans = max(ans, a[i] + a[j] + a[k]);
					}
				}
			}
		}
		cout << ans << "\n";
	}
}