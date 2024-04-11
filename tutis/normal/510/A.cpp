/*input
9 9
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i % 2 == 1)
				cout << "#";
			else if ((i / 2) % 2 == 0 && j == 1)
				cout << "#";
			else if ((i / 2) % 2 == 1 && j == m)
				cout << "#";
			else
				cout << ".";
		}
		cout << "\n";
	}

}