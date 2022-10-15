/*input
5
7500 South
10000 East
3500 North
4444 West
4000 North
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int x = 0;
	while (n--)
	{
		int km;
		cin >> km;
		string k;
		cin >> k;
		if (x == 0 && k != "South")
		{
			cout << "NO\n";
			return 0;
		}
		if (x == 20000 && k != "North")
		{
			cout << "NO\n";
			return 0;
		}
		if (k == "South")
			x += km;
		if (k == "North")
			x -= km;
		if (x < 0 || x > 20000)
		{
			cout << "NO\n";
			return 0;
		}
	}
	if (x == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
}