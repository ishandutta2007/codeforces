/*input
7747774
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	int kiek = 0;
	while (n > 0)
	{
		if (n % 10 == 4 || n % 10 == 7)
		{
			kiek++;
		}
		n /= 10;
	}
	if (kiek == 4 || kiek == 7)
		cout << "YES\n";
	else
		cout << "NO\n";
}