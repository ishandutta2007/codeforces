/*input
5 6 2
1 2
1 3
2 4
2 5
3 4
3 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m, k;
vector<string>ans;
vector<int>geri[200009];
void rekursija(int t, string &x)
{
	if (ans.size() >= k)
		return;
	if (t == n)
	{
		for (int j : geri[t])
		{
			x[j] = '1';
			ans.push_back(x);
			if (ans.size() >= k)
				return;
			x[j] = '0';
		}
		return;
	}
	for (int j : geri[t])
	{
		x[j] = '1';
		rekursija(t + 1, x);
		x[j] = '0';
	}
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	vector<int>adj[n + 1];
	int a[m], b[m];
	for (int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i];
		adj[a[i]].push_back(i);
		adj[b[i]].push_back(i);
	}
	int d[n + 1];
	fill_n(d, n + 1, n + 2);
	d[1] = 0;
	queue<int>Q;
	Q.push(1);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for (int i : adj[x])
		{
			if (d[a[i]] > d[x] + 1)
			{
				d[a[i]] = d[x] + 1;
				Q.push(a[i]);
			}
			if (d[b[i]] > d[x] + 1)
			{
				d[b[i]] = d[x] + 1;
				Q.push(b[i]);
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j : adj[i])
		{
			if (b[j] == i)
				swap(a[j], b[j]);
			if (d[b[j]] == d[i] - 1)
				geri[i].push_back(j);
		}
	}
	string s(m, '0');
	for (int i = 2; i <= n; i++)
	{
		if (geri[i].size() == 1)
		{
			s[geri[i][0]] = '1';
		}
	}
	rekursija(2, s);
	cout << ans.size() << "\n";
	for (string a : ans)
		cout << a << "\n";
}