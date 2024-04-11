/*input
3
10 3 2
0101010101
2 2
5 4 1
00000
2 10
11 2 3
10110011000
4 3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, less<T>, null_type, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, p, k;
		cin >> n >> p >> k;
		string s;
		cin >> s;
		int x, y;
		cin >> x >> y;
		int cnt[n];
		for (int i = n - 1; i >= 0; i--)
		{
			cnt[i] = 1 - (s[i] - '0');
			if (i + k < n)
				cnt[i] += cnt[i + k];
		}
		int ret = cnt[p - 1] * x;
		for (int i = p; i < n; i++)
		{
			ret = min(ret, (i - p + 1) * y + cnt[i] * x);
		}
		cout << ret << "\n";
	}

}