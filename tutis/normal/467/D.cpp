/*input
1
fffff
1
fffff r

*/
#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
using namespace std;
pair<int, int>r[300000];
vector<int>adj[300000];
bool vis[300000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> m;
	map<string, int>M;
	int e[m];
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		for (char&c : s)
			c = tolower(c);
		if (M.count(s) == 0)
			M[s] = M.size();
		e[i] = M[s];
	}
	int n;
	cin >> n;
	while (n--)
	{
		string x, y;
		cin >> x >> y;
		for (char&c : x)
			c = tolower(c);
		for (char&c : y)
			c = tolower(c);
		if (M.count(x) == 0)
			M[x] = M.size();
		if (M.count(y) == 0)
			M[y] = M.size();
		adj[M[y]].push_back(M[x]);
	}
	vector<pair<pair<int, int>, int>>A;
	for (auto i : M)
	{
		r[i.second].second = i.first.size();
		r[i.second].first = 0;
		for (char c : i.first)
			if (c == 'r')
				r[i.second].first++;
		A.push_back({r[i.second], i.second});
	}
	sort(A.begin(), A.end());
	for (auto i : A)
	{
		pair<int, int>v = i.first;
		vector<int>Q = {i.second};
		vis[i.second] = true;
		while (!Q.empty())
		{
			int a = Q.back();
			Q.pop_back();
			for (int b : adj[a])
			{
				if (!vis[b])
				{
					vis[b] = true;
					r[b] = r[a];
					Q.push_back(b);
				}
			}
		}
	}
	ll rr = 0;
	ll ll = 0;
	for (int i : e)
	{
		rr += r[i].first;
		ll += r[i].second;
	}
	cout << rr << " " << ll << "\n";
}