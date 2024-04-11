#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		map<string, int> g;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			g[s]++;
		}
		long long z = 0;
		for (pair<string, int> i: g)
		{
			for (pair<string, int> j: g)
			{
				if (i.first[0] == j.first[0] && i.first[1] != j.first[1] || i.first[0] != j.first[0] && i.first[1] == j.first[1])
				{
					z += (long long)i.second * j.second;
				}
			}
		}
		cout << z / 2 << endl;
	}
	return 0;
}