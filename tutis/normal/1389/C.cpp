/*input
3
95831
100120013
252525252525

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
		string s;
		cin >> s;
		int mx = 1;
		for (char c = '0'; c <= '9'; c++)
		{
			int kiek = 0;
			for (char a : s)
				if (a == c)
					kiek++;
			mx = max(mx, kiek);
		}
		for (char a = '0'; a <= '9'; a++)
			for (char b = '0'; b <= '9'; b++)
			{
				int ilg = 0;
				for (char x : s)
				{
					if (ilg % 2 == 0)
					{
						if (a == x)
							ilg++;
					}
					else
					{
						if (b == x)
							ilg++;
					}
				}
				if (ilg % 2 == 1)
					ilg--;
				mx = max(mx, ilg);
			}
		cout << (int)s.size() - mx << "\n";
	}


	return 0;
}