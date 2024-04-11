/*input
3 4
1 2
2 3
3 2
3 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>adj[505];
stack<int>X;
bool stake[505];
bool buvau[505];
bool radau = false;
vector<pair<int, int>>tikrink;
void dfs(int i)
{
	X.push(i);
	stake[i] = true;
	buvau[i] = true;
	for (int j : adj[i])
	{
		if (buvau[j] == false)
		{
			dfs(j);
			if (radau)
				return;
		}
		else if (stake[j])
		{
			radau = true;
			tikrink.push_back({i, j});
			int a = i;
			X.pop();
			while (!X.empty())
			{
				int b = X.top();
				X.pop();
				tikrink.push_back({b, a});
				a = b;
			}
			return;
		}
	}

	X.pop();
	stake[i] = false;
}
vector<int>kaim[505];
bool ciklas;
void dfs2(int i)
{
	stake[i] = true;
	buvau[i] = true;
	for (int j : kaim[i])
	{
		if (buvau[j] == false)
		{
			dfs2(j);
		}
		else if (stake[j])
		{
			ciklas = true;
		}
	}

	stake[i] = false;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
	{
		if (buvau[i] == false)
		{
			dfs(i);
		}
	}
	if (tikrink.empty())
	{
		cout << "YES\n";
		return 0;
	}
	for (pair<int, int>xx : tikrink)
	{
		for (int i = 1; i <= n; i++)
		{
			stake[i] = false;
			buvau[i] = false;
			kaim[i].clear();
			for (int j : adj[i])
			{
				if (!(xx.first == i && xx.second == j))
				{
					kaim[i].push_back(j);
				}
			}
		}
		ciklas = false;
		for (int i = 1; i <= n; i++)
			if (!buvau[i])
				dfs2(i);
		if (ciklas == false)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";

}