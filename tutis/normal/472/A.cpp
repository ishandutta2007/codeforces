/*input
1000000
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool composite(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int a = 4; a < n; a++)
	{
		if (composite(a) && composite(n - a))
		{
			cout << a << " " << n - a << "\n";
			return 0;
		}
	}
}