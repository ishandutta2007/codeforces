#include <bits/stdc++.h>
using namespace std;

pair<int, string> dat[55];

int main()
{
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> dat[i].first >> dat[i].second;
		if (dat[i].second == "South")
		{
			if (pos + dat[i].first > 20000)
			{
				cout << "NO";
				return 0;
			}
			pos += dat[i].first;
		}
		else if (dat[i].second == "North")
		{
			if (pos - dat[i].first < 0)
			{
				cout << "NO";
				return 0;
			}
			pos -= dat[i].first;
		}
		else
		{
			if (pos == 0 || pos == 20000)
			{
				cout << "NO";
				return 0;
			}
		}
	}

	cout << (pos == 0 ? "YES" : "NO");
}