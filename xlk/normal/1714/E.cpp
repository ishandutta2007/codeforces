#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		set<int> s;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			while (x % 10 != 0 && x % 10 != 2)
			{
				x += x % 10;
			}
			if (x % 10 == 2)
			{
				x %= 20;
			}
			s.insert(x);
		}
		cout << (s.size() > 1 ? "No" : "Yes") << endl;
	}
}