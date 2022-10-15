/***
4 4 2 2 3 1 4 1 4 0 1
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int>adj[n + 1];
	set<int>out[n + 1];
	set<int>in[n + 1];
	for (int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;
		while (c--)
		{
			int j;
			cin >> j;
			adj[i].push_back(j);
			out[i].insert(j);
			in[j].insert(i);
		}
	}
	int s;
	cin >> s;
	bool DP[n + 1][2];
	for (int i = 0; i <= n; i++)
		DP[i][0] = DP[i][1] = false;
	DP[s][0] = true;
	int kaip[n + 1][2];
	queue<int>X;
	X.push(s);
	while (!X.empty())
	{
		int a = X.front();
		X.pop();
		for (int b : adj[a])
		{
			if (DP[a][0] && !DP[b][1])
			{
				DP[b][1] = true;
				kaip[b][1] = a;
				X.push(b);
			}
			if (DP[a][1] && !DP[b][0])
			{
				DP[b][0] = true;
				kaip[b][0] = a;
				X.push(b);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (DP[i][1])
			if (adj[i].empty())
			{
				cout << "Win\n";
				int a = i;
				bool x = 1;
				deque<int>kelias;
				while (make_pair(a, x) != make_pair(s, false))
				{
					kelias.push_front(a);
					a = kaip[a][x];
					x = !x;
				}
				kelias.push_front(s);
				for (int i : kelias)
					cout << i << " ";
				cout << "\n";
				return 0;
			}
	}
	bool lose = true;
	vector<int>lapai;
	for (int i = 1; i <= n; i++)
		if (adj[i].size() == 0)
			lapai.push_back(i);
	while (!lapai.empty())
	{
		int a = lapai.back();
		lapai.pop_back();
		for (int b : in[a])
		{
			out[b].erase(a);
			if (out[b].empty())
				lapai.push_back(b);
		}
		in[a].clear();
		out[a].clear();
	}
	if (out[s].empty())
		cout << "Lose\n";
	else
		cout << "Draw\n";
}