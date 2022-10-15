/*input
4
4 3 2 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int>p(n);
	for (int &i : p)
	{
		cin >> i;
		i--;
	}
	for (int i = 0; i < n; i++)
	{
		if (p[i] == i)
		{
			cout << "YES\n";
			for (int j = 0; j < n; j++)
				if (j != i)
					cout << j + 1 << " " << i + 1 << "\n";
			return 0;
		}
	}
	vector<bool> uzimta(n, false);
	vector<vector<int>>x;
	for (int i = 0; i < n; i++)
	{
		if (uzimta[i])
			continue;
		if (p[i] == i)
		{
			uzimta[i] = true;
			x.push_back({i});
			continue;
		}
		x.push_back({});
		int j = i;
		do
		{
			uzimta[j] = true;
			x.back().push_back(j);
			j = p[j];
		} while (j != i);
	}
	int a = -1;
	int b = -1;
	for (vector<int> &i : x)
	{
		if (i.size() == 2)
		{
			a = i[0];
			b = i[1];
		}
	}
	if (a == -1)
	{
		cout << "NO\n";
		return 0;
	}
	vector<pair<int, int>>ans;
	ans.push_back({a, b});
	for (vector<int> &i : x)
	{
		if (i[0] != a)
		{
			if (i.size() % 2 == 1)
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				int c = 0;
				for (int t : i)
				{
					if (c % 2 == 0)
						ans.push_back({a, t});
					else
						ans.push_back({b, t});
					c++;
				}
			}
		}
	}
	cout << "YES\n";
	for (auto t : ans)
		cout << t.first + 1 << " " << t.second + 1 << "\n";

}