/*input
100 2
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
	for (int a = 1;; a++)
	{
		if (9 * a >= n)
		{
			for (int i = 0; i < a; i++)
			{
				cout << '9';
			}
			for (int i = 0; i < a - 1; i++)
				cout << '0';
			cout << "1\n";
			for (int i = 0; i < a; i++)
			{
				cout << '9';
			}
			cout << "\n";
			return 0;
		}
	}

}