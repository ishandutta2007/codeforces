/*input
3
123456789
100000000
100123456
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000 * 1000 * 1000 + 7;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	string x[n];
	unordered_map<string, set<int>>Y;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		for (int a = 0; a < x[i].size(); a++)
		{
			string c = "";
			for (int b = a; b < x[i].size(); b++)
			{
				c.push_back(x[i][b]);
				Y[c].insert(i);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		string ans = x[i];
		for (int a = 0; a < x[i].size(); a++)
		{
			string c = "";
			for (int b = a; b < x[i].size(); b++)
			{
				c.push_back(x[i][b]);
				if (Y[c].size() == 1)
				{
					if (c.size() < ans.size())
						ans = c;
				}
			}
		}
		cout << ans << "\n";
	}
}