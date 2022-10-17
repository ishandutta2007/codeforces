#include <bits/stdc++.h>
using namespace std;
int t, n, x;
vector<pair<int, int> > b[500020];
int z[500020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			b[i / (x + 1) + 1].push_back({x ? i / x : n, i});
		}
		set<pair<int, int> > s;
		for (int i = 1; i <= n; i++)
		{
			for (auto j : b[i])
			{
				s.insert(j);
			}
			b[i].clear();
			assert(s.size() > 0);
			z[s.begin()->second] = i;
			s.erase(s.begin());
		}
		for (int i = 1; i <= n; i++)
		{
			cout << z[i] << " ";
		}
		cout << endl;
	}
	return 0;
}