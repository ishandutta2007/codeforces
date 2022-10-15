/*input
47
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool lucky(ll n)
{
	while (n > 0)
	{
		if (n % 10 != 4 && n % 10 != 7)
			return false;
		n /= 10;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		if (n % i == 0 && lucky(i))
		{
			cout << "YES\n";
			return 0;
		}
	cout << "NO\n";
}