/*input
4
10 2 3 7
100 51 51 51
1234 1 100 199
1000000000 1 1 1000000000
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		long long L, v, l, r;
		cin >> L >> v >> l >> r;
		cout << L / v - (r / v) + (l - 1) / v << "\n";
	}
}