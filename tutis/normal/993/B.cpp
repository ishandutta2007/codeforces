/*input
2 2
1 2 3 4
1 5 3 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	pair<int, int>a[n];
	pair<int, int>b[m];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
		if (a[i].first > a[i].second)
			swap(a[i].first, a[i].second);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i].first >> b[i].second;
		if (b[i].first > b[i].second)
			swap(b[i].first, b[i].second);
	}
	set<int>G;
	bool zino = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
				continue;
			int sk = -1;
			if (a[i].first == b[j].first)
				sk = a[i].first;
			if (a[i].first == b[j].second)
				sk = a[i].first;
			if (a[i].second == b[j].second)
				sk = a[i].second;
			if (a[i].second == b[j].first)
				sk = a[i].second;
			if (sk == -1)
				continue;
			G.insert(sk);
			for (int k = 0; k < m; k++)
			{
				if (a[i] == b[k])
					continue;
				if (a[i].first == b[k].first || a[i].second == b[k].second || a[i].first == b[k].second || a[i].second == b[k].first)
				{
					if (a[i].first == b[k].first && b[k].first != sk)
						zino = false;
					if (a[i].second == b[k].second && b[k].second != sk)
						zino = false;
					if (a[i].first == b[k].second && b[k].second != sk)
						zino = false;
					if (a[i].second == b[k].first && b[k].first != sk)
						zino = false;
				}
			}
			for (int k = 0; k < n; k++)
			{
				if (b[j] == a[k])
					continue;
				if (b[j].first == a[k].first || b[j].second == a[k].second ||
				        b[j].first == a[k].second || b[j].second == a[k].first
				   )
				{
					if (b[j].first == a[k].first && a[k].first != sk)
						zino = false;
					if (b[j].second == a[k].second && a[k].second != sk)
						zino = false;
					if (b[j].first == a[k].second && a[k].second != sk)
						zino = false;
					if (b[j].second == a[k].first && a[k].first != sk)
						zino = false;
				}
			}
		}
	}
	if (G.size() == 1)
	{
		cout << *G.begin() << "\n";
		return 0;
	}
	if (zino)
	{
		cout << "0\n";
	}
	else
		cout << "-1\n";

}