#include <bits/stdc++.h>
using namespace std;
int t, n;
string a, b;
int c[100020];
void change(int x, int y)
{
	for (x++; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (x++; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> a >> b;
		if (a < b)
		{
			cout << 0 << endl;
			continue;
		}
		{
			string d = a;
			sort(d.begin(), d.end());
			if (d >= b)
			{
				cout << -1 << endl;
				continue;
			}
		}
		for (int i = 0; i <= n; i++)
		{
			c[i] = 0;
		}
		deque<int> q[26];
		for (int i = 0; i < n; i++)
		{
			q[a[i] - 'a'].push_back(i);
			change(i, 1);
		}
		long long z = 1e18, s = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < b[i] - 'a'; j++)
			{
				if (q[j].size() > 0)
				{
					z = min(z, s + query(q[j][0]) - 1);
				}
			}
			if (q[b[i] - 'a'].size() == 0)
			{
				break;
			}
			s += query(q[b[i] - 'a'][0]) - 1;
			change(q[b[i] - 'a'][0], -1);
			q[b[i] - 'a'].pop_front();
		}
		cout << z << endl;
	}
	return 0;
}