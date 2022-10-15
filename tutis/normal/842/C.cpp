/***
1
10
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX_N 300000
vector<int>adj[MAX_N];
int su[MAX_N];
unordered_set<int> be[MAX_N];
int a[MAX_N];
void make(int i, int p)
{
	for (int j : adj[i])
	{
		if (j != p)
		{
			su[j] = __gcd(su[i], a[j]);
			be[j].insert(__gcd(su[i], 0));
			for (int c : be[i])
			{
				be[j].insert(__gcd(c, a[j]));
			}
			make(j, i);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	su[1] = a[1];
	be[1].insert(0);
	make(1, 1);
	for (int i = 1; i <= n; i++)
	{
		int ans = su[i];
		for (int c : be[i])
		{
			ans = max(ans, c);
		}
		cout << ans << " ";
	}
}