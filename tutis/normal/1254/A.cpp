/*input
4
3 5 3
..R..
...R.
....R
6 4 6
R..R
R..R
RRRR
RRRR
R..R
R..R
5 5 4
RRR..
R.R..
RRR..
R..R.
R...R
2 31 62
RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using treee = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
	string s;
	for (char a = 'a'; a <= 'z'; a++)
		s.push_back(a);
	for (char a = 'A'; a <= 'Z'; a++)
		s.push_back(a);
	for (char a = '0'; a <= '9'; a++)
		s.push_back(a);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int r, cc, k;
		cin >> r >> cc >> k;
		char A[r][cc];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < cc; j++)
				cin >> A[i][j];
		int kiek = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < cc; j++)
				if (A[i][j] == 'R')
					kiek++;
		int m1 = kiek / k;
		int m2 = m1 + 1;
		vector<int>B;
		for (int k1 = 0; k1 <= k; k1++)
		{
			int k2 = k - k1;
			if (m1 * k1 + m2 * k2 == kiek)
			{
				while (k1--)
					B.push_back(m1);
				while (k2--)
					B.push_back(m2);
				break;
			}
		}
		int x = 0;
		int y = 0;
		for (int i = 0; i < B.size(); i++)
		{
			int re = B[i];
			char c = s[i];
			while (x < r && (re > 0 || i + 1 == (int)B.size()))
			{
				if (A[x][y] == 'R')
					re--;
				A[x][y] = c;
				if (x % 2 == 0)
				{
					if (y == cc - 1)
						x++;
					else
						y++;
				}
				else
				{
					if (y == 0)
						x++;
					else
						y--;
				}
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < cc; j++)
				cout << A[i][j];
			cout << "\n";
		}
	}
}