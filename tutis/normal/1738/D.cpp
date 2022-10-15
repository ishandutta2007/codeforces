/*input
3
4
5 3 1 2
6
7 7 7 3 3 3
6
4 4 4 0 0 0

*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(0);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int b[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		vector<int>V[n + 2];
		for (int i = 1; i <= n; i++)
			V[b[i]].push_back(i);
		vector<int>x;
		bool pl = V[0].empty();
		if (V[n + 1].empty())
			x = V[0];
		else
			x = V[n + 1];
		vector<int>a;
		int c = 0;
		while (true)
		{
			if (pl)
				c += x.size();
			pl = !pl;
			int lst = -1;
			for (int i : x)
			{
				if (V[i].size() > 0)
					lst = i;
			}
			for (int i : x)
				if (i != lst)
					a.push_back(i);
			if (lst != -1)
				a.push_back(lst);
			if (lst == -1)
				break;
			else
				x = V[lst];
		}
		cout << c << "\n";
		for (int i : a)
			cout << i << " ";
		cout << "\n";
	}
}