/*input
3
5
1 0 0 3 3
2 3 2 1 0
3
1 1 1
0 0 3
8
0 1 2 3 4 5 6 7
7 6 5 4 3 2 1 0

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(0);
ull R[2][1 << 16];
ull H(int x)
{
	return R[0][x % (1 << 16)] ^ R[1][x / (1 << 16)];
}
int main()
{
	for (int t : {0, 1})
		for (int i = 0; i < (1 << 16); i++)
			R[t][i] = rng();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		int r = 0;
		for (int p = 29; p >= 0; p--)
		{
			int gal = r ^ (1 << p);
			ull xx = 0;
			for (int i = 0; i < n; i++)
			{
				int c = a[i] ^ gal;
				c ^= (c & ((1 << p) - 1));
				int d = b[i] ^ (b[i] & ((1 << p) - 1));
				xx += H(c);
				xx -= H(d);
			}
			if (xx != 0)
			{
				for (int i = 0; i < n; i++)
				{
					a[i] |= (1 << p);
					b[i] |= (1 << p);
				}
			}
			else
				r |= (1 << p);
		}
		cout << r << "\n";
	}
	return 0;
}