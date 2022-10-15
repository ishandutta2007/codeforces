/*input
1 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll a, m;
	cin >> a >> m;
	for (int t = 0; t < 20; t++)
	{
		a *= 2;
		if (a % m == 0)
		{
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}