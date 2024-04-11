/*input
7
1 2 1 3 1 2 1
9
2 1
2 2
3 1
3 2
3 3
1 1
7 1
7 7
7 4

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int p[n];
	iota(p, p + n, 1);
	sort(p, p + n, [&](int i, int j) {if (a[i] != a[j])return a[i] > a[j]; else return i < j;});
	int m;
	cin >> m;
	int ans[m];
	vector<pair<pair<int, int>, int>>A;
	for (int q = 0; q < m; q++)
	{
		int k, i;
		cin >> k >> i;
		A.push_back({{k, i}, q});
	}
	sort(A.begin(), A.end());
	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>b;
	for (auto c : A)
	{
		int k = c.first.first;
		int i = c.first.second;
		i--;
		int q = c.second;
		while (b.size() < k)
		{
			b.insert(p[b.size()]);
		}
		ans[q] = a[*b.find_by_order(i)];
	}
	for (int q = 0; q < m; q++)
		cout << ans[q] << "\n";
}