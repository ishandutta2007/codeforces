#include <bits/stdc++.h>
using namespace std;
int t, n, k, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		set<int> s;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			s.insert(x);
		}
		int f = 0;
		for (int i: s)
		{
			if (s.find(i + k) != s.end())
			{
				f = 1;
			}
		}
		cout << (f ? "YES" : "NO") << endl;
	}
	return 0;
}