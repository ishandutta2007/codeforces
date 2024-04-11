/*input
4
1 2
1 3
1 2
1 2
1 3
1 2
2 5
1 2
3 1
1 4
5 1
1 6
2 15
1 2
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6
4 5
4 6
5 6
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
mt19937 rng(123);
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<int>adj[3 * n + 1];
		int u[m + 1], v[m + 1];
		for (int i = 1; i <= m; i++)
		{
			cin >> u[i] >> v[i];
			adj[u[i]].push_back(v[i]);
			adj[v[i]].push_back(u[i]);
		}
		uniform_int_distribution<int>ed(1, m);
		uniform_int_distribution<int>ver(1, 3 * n);
		for (int gal = 0; gal < 15; gal++)
		{
			vector<bool>ok(3 * n + 1, true);
			vector<int>mat;
			for (int t = 0; t < m * 2 && (int)mat.size() < n; t++)
			{
				int i = ed(rng);
				if (ok[u[i]] && ok[v[i]])
				{
					ok[u[i]] = false;
					ok[v[i]] = false;
					mat.push_back(i);
				}
			}
			if ((int)mat.size() == n)
			{
				cout << "Matching\n";
				for (int i : mat)
					cout << i << " ";
				cout << "\n";
				goto RADAU;
			}
		}
		for (int gal = 0; gal < 15; gal++)
		{
			vector<bool>ok(3 * n + 1, true);
			vector<int>mat;
			for (int t = 0; t < 6 * n && (int)mat.size() < n; t++)
			{
				int i = ver(rng);
				if (ok[i])
				{
					ok[i] = false;
					for (int j : adj[i])
						ok[j] = false;
					mat.push_back(i);
				}
			}
			if ((int)mat.size() == n)
			{
				cout << "IndSet\n";
				for (int i : mat)
					cout << i << " ";
				cout << "\n";
				goto RADAU;
			}
		}
		cout << "Impossible\n";
RADAU:;
	}
}