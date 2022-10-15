/***
18
1 1 1 4 4 3 2 2 2 10 8 9 9 9 10 10 4
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>adj[100009];
int d[100009];
int a[100009];
void dfs(int i)
{
	a[d[i]]++;
	for (int j : adj[i])
	{
		d[j] = d[i] + 1;
		dfs(j);
	}
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	d[1] = 0;
	dfs(1);
	int ans = 0;
	for (int i = 0; i <= n + 1; i++)
		ans += (a[i] % 2);
	cout << ans << "\n";
}