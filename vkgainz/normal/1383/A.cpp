#include <bits/stdc++.h>

using namespace std;

const int Alp = 20;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int test;
	cin >> test;
	while (test--)
	{
	    int n;
		string a, b;
		cin >> n >> a >> b;

		bool bad = false;
		vector<vector<int>> adj(Alp);
		for (int i = 0; i < n; ++i)
			if (a[i] != b[i])
			{
				if (a[i] > b[i])
				{
					bad = true;
					cout << "-1\n";
					break;
				}

				adj[a[i]-'a'].push_back(b[i]-'a');
				adj[b[i]-'a'].push_back(a[i]-'a');
			}

		if (bad) continue;

		vector<bool> mark(Alp);
		function<void(int)> dfs = [&](int u)
		{
			mark[u] = true;
			for (auto v : adj[u])
				if (!mark[v])
					dfs(v);
		};

		int ans = Alp;
		for (int i = 0; i < Alp; ++i)
			if (!mark[i])
				dfs(i), --ans;
		cout << ans << "\n";
	}

	return 0;
}