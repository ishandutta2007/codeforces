/*input
5 4 5
1 2
2 3
3 4
4 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m, s;
	cin >> n >> m >> s;
	vector<int>adj[n + 1];
	vector<int>in[n + 1];
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		in[b].push_back(a);
	}
	set<int>pasiekiami;
	queue<int>Q;
	Q.push(s);
	pasiekiami.insert(s);
	int ans = 0;
	while (!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		for (int b : adj[a])
		{
			if (pasiekiami.count(b) == 0)
			{
				pasiekiami.insert(b);
				Q.push(b);
			}
		}
	}
	int kiek[n + 1];
	fill_n(kiek, n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		bool A[n + 1];
		fill_n(A, n + 1, false);
		A[i] = true;
		kiek[i]++;
		queue<int>Q;
		Q.push(i);
		while (!Q.empty())
		{
			int a = Q.front();
			Q.pop();
			for (int b : adj[a])
			{
				if (!A[b])
				{
					A[b] = true;
					kiek[i]++;
					Q.push(b);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (in[i].size() == 0 && pasiekiami.count(i) == 0)
		{
			ans++;
			queue<int>Q;
			Q.push(i);
			pasiekiami.insert(i);
			while (!Q.empty())
			{
				int a = Q.front();
				Q.pop();
				for (int b : adj[a])
				{
					if (pasiekiami.count(b) == 0)
					{
						pasiekiami.insert(b);
						Q.push(b);
					}
				}
			}
		}
	}
	while (pasiekiami.size() < n)
	{
		pair<int, int>mx = { -1, -1};
		for (int i = 1; i <= n; i++)
		{
			if (pasiekiami.count(i) == 0)
			{
				mx = max(mx, {kiek[i], i});
			}
		}
		int i = mx.second;
		ans++;
		queue<int>Q;
		Q.push(i);
		pasiekiami.insert(i);
		while (!Q.empty())
		{
			int a = Q.front();
			Q.pop();
			for (int b : adj[a])
			{
				if (pasiekiami.count(b) == 0)
				{
					pasiekiami.insert(b);
					Q.push(b);
				}
			}
		}
	}
	cout << ans << "\n";



}