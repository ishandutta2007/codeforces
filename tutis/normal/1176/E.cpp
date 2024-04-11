/*input
2
4 6
1 2
1 3
1 4
2 3
2 4
3 4
6 8
2 5
5 4
4 3
4 1
1 3
2 3
2 6
5 6
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int>adj[n + 1];
		while (m--)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int>x;
		for (int i = 1; i <= n; i++)
			x.push_back(i);
		set<int>ans;
		sort(x.begin(), x.end(), [&](int a, int b) {return adj[a].size() > adj[b].size();});
		for (int v : x)
		{
			bool ok = false;
			for (int u : adj[v])
				if (ans.count(u))
					ok = true;
			if (ok == false)
				ans.insert(v);
		}
		while ((int)ans.size() > n / 2)
		{
			ans.clear();
			shuffle(x.begin(), x.end(), gen);
			for (int v : x)
			{
				bool ok = false;
				for (int u : adj[v])
					if (ans.count(u))
						ok = true;
				if (ok == false)
					ans.insert(v);
			}
		}
		cout << ans.size() << "\n";
		for (int i : ans)
			cout << i << " ";
		cout << "\n";
	}
}