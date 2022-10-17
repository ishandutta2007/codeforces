#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = (sizeof(ll) == 8) ? 1e18 : 1e9;

vector <vector <ll>> gr;
vector <bool> used;
vector <ll> comp;

void dfs(ll v)
{
	used[v] = 1;
	for (int i = 0; i < gr[v].size(); i++)
	{
		if (!used[gr[v][i]])
		{
			dfs(gr[v][i]);
		}
	}
	comp.push_back(v);
}

int main()
{
	srand(time(0));
	ios::sync_with_stdio(0);
#ifdef _F1A4X_
	ifstream cin("input.txt");
	//ofstream cout("output.txt");
#endif
	ll n, m;
	cin >> n >> m;
	used.resize(n);
	gr.resize(n);
	for (int i = 0; i < m; i++)
	{
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
		{
			comp.clear();
			dfs(i);
			for (int j = 0; j < comp.size(); j++)
			{
				if (gr[comp[j]].size() != comp.size() - 1)
				{
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES";
	cout << endl;
	return 0;
}