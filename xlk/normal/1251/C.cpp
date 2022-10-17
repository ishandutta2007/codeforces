#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		string s, a, b;
		cin >> s;
		for (char i: s)
		{
			if (i & 1)
			{
				a += i;
			}
			else
			{
				b += i;
			}
		}
		for (int i = 0, j = 0; i < a.size() || j < b.size();)
		{
			if (j == b.size() || (i < a.size() && a[i] < b[j]))
			{
				cout << a[i++];
			}
			else
			{
				cout << b[j++];
			}
		}
		cout << endl;
	}
}