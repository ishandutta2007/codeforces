/*input
5
1 2
1 3
1 4
1 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
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
	int mxd = 0;
	for (int i = 1; i <= n; i++)
		mxd = max(mxd, (int)adj[i].size());
	if (mxd <= 2)
	{
		cout << "Yes\n1\n";
		bool pirmas = true;
		for (int i = 1; i <= n; i++)
		{
			if (adj[i].size() == 1)
			{
				if (pirmas)
					cout << i << " ";
				else
					cout << i << "\n";
				pirmas = false;
			}
		}
		return 0;
	}
	vector<int>lapai;
	for (int i = 1; i <= n; i++)
		if (adj[i].size() == 1)
			lapai.push_back(i);
	vector<int>sueina[n + 1];
	for (int i : lapai)
	{
		set<int>buvau;
		int a = i;
		while (true)
		{
			buvau.insert(a);
			if (adj[a].size() >= 3)
				break;
			for (int b : adj[a])
			{
				if (buvau.count(b) == 0)
				{
					a = b;
					break;
				}
			}
		}
		sueina[a].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (sueina[i].size() == lapai.size())
		{
			cout << "Yes\n" << lapai.size() << "\n";
			for (int a : lapai)
				cout << i << " " << a << "\n";
			return 0;
		}
	}
	cout << "No\n";


}