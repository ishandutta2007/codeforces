/*input
3
3
.O.
OOO
.O.
6
XXXOOO
XXXOOO
XX..OO
OO..XX
OOOXXX
OOOXXX
5
.OOO.
OXXXO
OXXXO
OXXXO
.OOO.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, less<T>, null_type, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int>cnt(3, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] != '.')
				{
					int t1 = (i + j) % 3;
					int t2 = (i + j + 1) % 3;
					cnt[t1]++;
					cnt[t2]++;
				}
			}
		}
		int t = 0;
		for (int j = 1; j < 3; j++)
			if (cnt[j] < cnt[t])
				t = j;
		int kiek = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] != '.')
				{
					int t1 = (i + j) % 3;
					int t2 = (i + j + 1) % 3;
					if (t1 == t)
					{
						if (a[i][j] == 'X')
							kiek++;
						else
							kiek--;
					}
					if (t2 == t)
					{
						if (a[i][j] == 'O')
							kiek++;
						else
							kiek--;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] != '.')
				{
					int t1 = (i + j) % 3;
					int t2 = (i + j + 1) % 3;
					if (t1 == t)
					{
						if (kiek > 0)
							a[i][j] = 'X';
						else
							a[i][j] = 'O';
					}
					if (t2 == t)
					{
						if (kiek > 0)
							a[i][j] = 'O';
						else
							a[i][j] = 'X';
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
			cout << a[i] << "\n";
	}
}