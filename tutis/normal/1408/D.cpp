/*input
2 3
1 6
6 1
10 1
1 10
7 7

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
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
	int n, m;
	cin >> n >> m;
	int a[n], b[n], c[m], d[m];
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for (int i = 0; i < m; i++)
		cin >> c[i] >> d[i];
	int lo = 0;
	int hi = 1000001;
	vector<pair<int, pair<int, int>>>K;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			K.push_back({ -d[j] + b[i], {i, j}});
		}
	}
	sort(K.begin(), K.end());
	while (lo < hi)
	{
		int xxx = (lo + hi) / 2;
		//(a+x, b+(m-x))
		vector<pair<int, int>>G;
		int x = 0;
		for (auto asd : K)
		{
			int i = asd.second.first;
			int j = asd.second.second;
			if (a[i] + b[i] + xxx <= c[j] + d[j] && a[i] <= c[j] && b[i] <= d[j])
			{
				int lo = xxx - (d[j] - b[i]);
				int hi = c[j] - a[i];
				if (x >= lo && x <= hi)
				{
					x = hi + 1;
				}
			}
		}
		if (x <= xxx)
			hi = xxx;
		else
			lo = xxx + 1;
	}
	cout << lo << "\n";
	return 0;
}