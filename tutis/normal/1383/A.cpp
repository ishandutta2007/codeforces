/*input
5
3
aab
bcc
4
cabc
abcb
3
abc
tsr
4
aabd
cccd
5
abcbd
bcdda
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		bool ok = true;
		for (int i = 0; i < n; i++)
			ok &= a[i] <= b[i];
		if (!ok)
		{
			cout << "-1\n";
			continue;
		}
		int ans = 0;
		for (char c = 'a'; c <= 't'; c++)
		{
			char mn = 'z';
			for (int i = 0; i < n; i++)
				if (a[i] != b[i] && a[i] == c)
					mn = min(mn, b[i]);
			bool ok = true;
			while (ok)
			{
				ok = false;
				for (int i = 0; i < n; i++)
					if (b[i] == mn)
					{
						if (a[i] < mn && a[i] > c)
						{
							ok = true;
							mn = a[i];
						}
					}
			}
			if (mn != 'z')
			{
				ans++;
				for (int i = 0; i < n; i++)
					if (a[i] != b[i] && a[i] == c)
						a[i] = mn;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}