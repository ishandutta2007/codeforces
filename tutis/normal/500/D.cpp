/*input
6
1 5 3
5 3 2
6 1 7
1 4 4
5 2 3
5
1 2
2 1
3 5
4 1
5 2

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>adj[101010];
int sz[101010];
void dfs(int i, int p)
{
	sz[i] = 1;
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		dfs(j, i);
		sz[i] += sz[j];
	}
}
ll C(ll x)
{
	return x * (x - 1) * (x - 2) / 6;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n], b[n], l[n];
	for (int i = 1; i < n; i++)
	{
		cin >> a[i] >> b[i] >> l[i];
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	ld ans = 0;
	ld x[n];
	dfs(1, 1);
	for (int i = 1; i < n; i++)
	{
		if (sz[a[i]] < sz[b[i]])
			swap(a[i], b[i]);
		ll yy = C(n);
		ll xx = C(n);
		xx -= C(sz[b[i]]);
		xx -= C(n - sz[b[i]]);
		x[i] = 2.0 * ld(xx) / ld(yy);
		ans += x[i] * l[i];
	}
	int q;
	cin >> q;
	while (q--)
	{
		int i, w;
		cin >> i >> w;
		ans += ld(w - l[i]) * x[i];
		l[i] = w;
		cout << fixed << setprecision(20) << ans << "\n";
	}
}