/*input
6
2 0 3 0 1 1

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<pair<int, int>>ans;
	int j = -1;
	vector<int>A, B;
	for (int i = n; i >= 1; i--)
	{
		int h = i;
		if (a[i] == 2)
		{
			if (A.empty())
			{
				cout << "-1\n";
				return 0;
			}
			ans.push_back({i, A.back()});
			A.pop_back();
			B.push_back(i);
		}
		else if (a[i] == 1)
		{
			A.push_back(i);
			ans.push_back({i, h});
		}
		else if (a[i] == 3)
		{
			int j = -1;
			if (!B.empty())
			{
				j = B.back();
				B.pop_back();
			}
			else if (!A.empty())
			{
				j = A.back();
				A.pop_back();
			}
			else
			{
				cout << "-1\n";
				return 0;
			}
			ans.push_back({i, h});
			ans.push_back({j, h});
			B.push_back(i);
		}
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.second << " " << i.first << "\n";
}