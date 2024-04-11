/*input
4
3
1 3 5
4
1 3 5 7
4
1 2 3 4
4
10 20 30 40

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
		int a[n];
		int k0 = 0;
		int k1 = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] % 2 == 0)
				k0++;
			else
				k1++;
		}
		bool A[2][k0 + 1][k1 + 1];
		bool B[2][k0 + 1][k1 + 1];
		for (int x = 0; x <= k0; x++)
		{
			for (int y = 0; y <= k1; y++)
			{
				for (int t : {0, 1})
				{
					A[t][x][y] = false;
					B[t][x][y] = false;
					if (x + y == 0)
					{
						if (t == 0)
							A[t][x][y] = true;
						else
							B[t][x][y] = true;
					}
					else
					{
						if (x > 0)
						{
							if (B[t][x - 1][y] == false)
								A[t][x][y] = true;
							if (A[t][x - 1][y] == false)
								B[t][x][y] = true;
						}
						if (y > 0)
						{
							if (B[t ^ 1][x][y - 1] == false)
								A[t][x][y] = true;
							if (A[t][x][y - 1] == false)
								B[t][x][y] = true;
						}
					}
				}
			}
		}
		if (A[0][k0][k1])
			cout << "Alice\n";
		else
			cout << "Bob\n";
	}
}