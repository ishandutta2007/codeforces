/*input
4 2
2
2
3
3
2
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
int main()
{
	int n, k;
	cin >> n >> k;
	ull a[n];
	ull b[n];
	for (int i = 0; i < n; i++)
		a[i] = k;
	vector<bool>ok(n, true);
	vector<int>G;
	for (int i = 0; i < n; i++)
		G.push_back(i);
	//0 imposteris
	int id = 0;
	int moves = 0;
	while (G.size() > 1)
	{
		id += moves - 2;
		id %= n;
		ll ind = id;
		ind %= n;
		if (G.size() < 340)
		{
			int del = min(moves, 20);
			vector<int>gal;
			for (int i : G)
			{
				for (int d = -del; d <= del; d++)
				{
					int id = i + d;
					id %= n;
					if (id < 0)
						id += n;
					gal.push_back(id);
				}
			}
			ind = gal[rng() % gal.size()];
		}
		ind %= n;
		if (ind < 0)
			ind += n;
		cout << "? " << ind + 1 << endl;
		ull val;
		cin >> val;
		vector<int>G_;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == val)
			{
				int v = ind - i;
				if (v < 0)
					v += n;
				if (ok[v])
					G_.push_back(v);
			}
		}
		for (int i : G)
			ok[i] = false;
		for (int i : G_)
			ok[i] = true;
		G = G_;
		for (int i = 0; i < n; i++)
			b[i] = 0;
		for (int i = 0; i < n; i++)
		{
			ull l = a[i] / 2;
			ull r = a[i] - l;
			if (i == 0)
			{
				b[i + 1] += l;
				b[i + 1] += r;
			}
			else
			{
				b[i - 1] += l;
				if (i != n - 1)
					b[i + 1] += r;
				else
					b[0] += r;
			}
		}
		for (int i = 0; i < n; i++)
			a[i] = b[i];
		moves++;
	}
	assert(G.size() == 1);
	cout << "! " << G[0] + 1 << endl;
	return 0;
}