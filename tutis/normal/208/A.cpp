/*input
WUBWUBABCWUB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string a;
	cin >> a;
	vector<string>ans;
	int r = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (i + 2 < a.size() && a[i] == 'W' && a[i + 1] == 'U' && a[i + 2] == 'B')
		{
			if (r < i)
			{
				string c = "";
				for (int j = r; j < i; j++)
					c.push_back(a[j]);
				ans.push_back(c);
			}
			r = i + 3;
			continue;
		}
	}
	int n = a.size();
	if (r < n)
	{
		string c = "";
		for (int j = r; j < n; j++)
			c.push_back(a[j]);
		ans.push_back(c);
	}
	for (auto i : ans)
		cout << i << " ";
}