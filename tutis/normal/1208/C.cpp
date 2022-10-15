/*input
4
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int id = i / 4 + (j / 4) * (n / 4);
			cout << id * 16 + i % 4 + (j % 4) * 4 << " ";
		}
		cout << "\n";
	}
}