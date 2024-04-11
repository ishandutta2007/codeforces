/*input
4 4
1 2 1
2 3 2
1 3 2
3 4 1

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
	int N, M;
	cin >> N >> M;
	int a[N], b[N];
	vector<bool> info(N, false);
	vector<pair<int, int>>adj[N];
	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	ld w[N];
	for (int i = 0; i < N; i++)
	{
		if (info[i])
			continue;
		queue<int>Q;
		Q.push(i);
		a[i] = 0;
		b[i] = 1;
		info[i] = true;
		bool zinom = false;
		ld xx = 0;
		vector<int>A;
		vector<int>B;
		while (!Q.empty())
		{
			int x = Q.front();
			Q.pop();
			A.push_back(-a[x] * b[x]);
			B.push_back(x);
			for (pair<int, int>y : adj[x])
			{
				if (info[y.first])
				{
					int a_ = y.second - a[x];
					int b_ = -b[x];
					if (b_ == b[y.first])
					{
						if (a_ != a[y.first])
						{
							cout << "NO\n";
							return 0;
						}
					}
					else
					{
						zinom = true;
						xx = ld(a_ - a[y.first]) / ld(b[y.first] - b_);
					}
				}
				else
				{
					info[y.first] = true;
					Q.push(y.first);
					a[y.first] = y.second - a[x];
					b[y.first] = -b[x];
				}
			}
		}
		if (!zinom)
		{
			sort(A.begin(), A.end());
			xx = A[A.size() / 2];
		}
		for (int v : B)
			w[v] = a[v] + b[v] * xx;
		for (int v : B)
		{
			for (pair<int, int>u : adj[v])
			{
				if (abs(w[v] + w[u.first] - u.second) > 0.1)
				{
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < N; i++)
		cout << fixed << setprecision(2) << w[i] << " ";
	return 0;
}