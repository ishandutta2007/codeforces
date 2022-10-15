/*input
5
5
1 5 3 4 2
4
1 3 2 1
5
1 3 3 3 2
10
1 2 3 4 5 6 7 8 9 10
3
3 3 2
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
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int p[n];
		iota(p, p + n, 0);
		sort(p, p + n, [&](int x, int y) {
			if (a[x] != a[y])
				return a[x] < a[y];
			else
				return x < y;
		});
		string ans(n, '0');
		set<int>S;
		for (int i : a)
			S.insert(i);
		if (S.size() == n)
			ans[0] = '1';
		vector<int>V, W;
		set<int>X;
		X.insert(-1);
		X.insert(n);
		int bent = 1;
		for (int t = 0; t < n; t++)
		{
			V.push_back(p[t]);
			if (t == n - 1 || a[p[t]] != a[p[t + 1]])
			{
				for (int i : V)
				{
					auto it = X.upper_bound(i);
					int v = *it - 1;
					it--;
					int w = *it + 1;
					if (i != v && i != w)
					{
						bent = max(bent, v - w + 1);
					}
					else
					{
						if (a[v] == a[w])
						{
							bent = max(bent, v - w + 1);
						}
					}
				}
				for (int i : V)
					X.insert(i);
				V.clear();
			}
		}
		set<int>X1;
		for (int i = -1; i <= n; i++)
			X1.insert(i);
		reverse(p, p + n);
		int mx[n + 1];
		for (int i = 0; i < n + 1; i++)
			mx[i] = -1;
		for (int i : p)
		{
			X1.erase(i);
			auto it = X1.upper_bound(i);
			int a2 = *it;
			it--;
			int a1 = *it;
			int l = a2 - a1 - 1;
			mx[l] = max(mx[l], a[i]);
		}
		for (int i = n - 1; i >= 0; i--)
			mx[i] = max(mx[i], mx[i + 1]);
		for (int i = max(bent, 2); i <= n; i++)
			if (mx[i] == n - i + 1)
				ans[i - 1] = '1';
		cout << ans << "\n";
	}

}