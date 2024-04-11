#include <bits/stdc++.h>
using namespace std;

pair<int, string> dat[3005];
int ans[3005];
set<int, greater<>> z;

int main()
{
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> dat[i].second >> dat[i].first;
	}

	sort(dat, dat + n);

	int now = 1;
	for (int i = 1; i <= n; i++) z.insert(i);

	for (int i = n - 1, j; i >= 0; i = j)
	{
		for (j = i - 1; j >= 0 && dat[j].first == dat[i].first; j--);

		// j + 1 ~ i

		if (j + 1 < dat[i].first)
		{
			cout << "-1\n";
			return 0;
		}

		int p = 0;
		for (auto itr = z.begin(); itr != z.end(); itr++)
		{
			if (p == dat[i].first)
			{
				for (int k = i; k > j; k--)
				{
					if (itr == z.end())
					{
						cout << "-1\n";
						return 0;
					}
					ans[k] = *itr;
					itr = z.erase(itr);
				}
				break;
			}

			++p;
		}

		if (ans[i] == 0)
		{
			cout << "-1\n";
			return 0;
		}
	}

	for (int i = 0; i < n; i++) cout << dat[i].second << " " << ans[i] << '\n';
}