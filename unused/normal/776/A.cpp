#include <bits/stdc++.h>
using namespace std;

vector<pair<string, string>> vt;

int main()
{
	string c1, c2;
	cin >> c1 >> c2;
	int n;
	cin >> n;
	cout << c1 << ' ' << c2 << endl;

	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		vt.emplace_back(a, b);
	}

	while (vt.empty() == false)
	{
		int i;
		for (i = 0; i < vt.size(); i++)
		{
			auto &&e = vt[i];
			if (e.first == c1)
			{
				cout << c2 << ' ' << e.second << endl;
				c1 = e.second;
				break;
			}
			else if (e.second == c1)
			{
				cout << c2 << ' ' << e.first << endl;
				c1 = e.first;
				break;
			}
			else if (e.first == c2)
			{
				cout << c1 << ' ' << e.second << endl;
				c2 = e.second;
				break;
			}
			else if (e.second == c2)
			{
				cout << c1 << ' ' << e.first << endl;
				c2 = e.first;
				break;
			}
		}
		vt.erase(vt.begin() + i);
	}
}