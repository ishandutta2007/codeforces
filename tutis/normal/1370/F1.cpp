/*input
1
3
1 2
1 3
1 1
3 1
1 1
Correct
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
pair<int, int>ask(vector<int>x)
{
	cout << "? " << x.size();
	for (int i : x)
		cout << " " << i;
	cout << endl;
	int a, b;
	cin >> a >> b;
	if (a == -1 || b == -1)
		exit(0);
	return {a, b};
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>adj[n + 1];
		for (int i = 1; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int d[n + 1];
		function<void(int, int)>dfs = [&](int x, int p)
		{
			for (int y : adj[x])
			{
				if (y == p)
					continue;
				d[y] = d[x] + 1;
				dfs(y, x);
			}
		};
		d[1] = 0;
		dfs(1, 1);
		vector<int>visi;
		for (int i = 1; i <= n; i++)
			visi.push_back(i);
		pair<int, int>vis_ = ask(visi);
		int x = vis_.first;
		int mn = vis_.second;
		for (int del = 512; del >= 1; del /= 2)
		{
			vector<int>kl;
			for (int i = 1; i <= n; i++)
				if (d[i] == d[x] + del)
					kl.push_back(i);
			if (!kl.empty())
			{
				pair<int, int>a = ask(kl);
				if (a.second == mn)
					x = a.first;
			}
		}
		d[x] = 0;
		dfs(x, x);
		vector<int>gal;
		for (int i = 1; i <= n; i++)
			if (d[i] == mn)
				gal.push_back(i);
		int y = ask(gal).first;
		cout << "! " << x << " " << y << endl;
		string s;
		cin >> s;
		if (s == "Incorrect")
			exit(0);
	}
	return 0;
}