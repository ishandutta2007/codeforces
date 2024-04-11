/*input
15
4 8 4 8 15 16 8 16 23 15 16 4 42 23 42

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename A, typename B>
using hash_set = cc_hash_table<A, B>;
typedef long long ll;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>a = {4, 8, 15, 16, 23, 42};
	deque<int>x[50];
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		x[a].push_back(i);
	}
	int kk = 0;
	while (true) {
		int i = -1;
		for (int c : a)
		{
			while (!x[c].empty() && x[c][0] < i)
				x[c].erase(x[c].begin());
			if (!x[c].empty())
			{
				i = x[c][0];
				x[c].pop_front();
			}
			else
			{
				i = -2;
				break;
			}
		}
		if (i != -2)
			kk++;
		else
			break;
	}
	cout << n - kk * 6 << "\n";
}