/***
5
1 2
1 3
3 4
2 5
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX_N 100009
vector<int>adj[MAX_N];
int par[MAX_N];
void pre(int i)
{
	for (int j : adj[i])
	{
		if (j != par[i])
		{
			par[j] = i;
			pre(j);
		}
	}
}
ld pro(int i)
{
	ld k = 0;
	for (int j : adj[i])
	{
		if (j != par[i])
			k++;
	}
	ld ans = 0;
	for (int j : adj[i])
	{
		if (j != par[i])
		{
			ans += pro(j) / k;
		}
	}
	return 1 + ans;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	par[1] = 1;
	pre(1);
	cout << fixed << setprecision(30) << (pro(1) - 1.0);
}