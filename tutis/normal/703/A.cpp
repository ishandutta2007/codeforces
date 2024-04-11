/*input
3
1 5
3 3
2 2

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
	ll suma = 0;
	for (int i = 0; i < n; i++)
	{
		ll a, b;
		cin >> a >> b;
		if (a > b)
			suma++;
		else if (a < b)
			suma--;
	}
	if (suma > 0)
	{
		cout << "Mishka\n";
	}
	else if (suma < 0)
	{
		cout << "Chris\n";
	}
	else
	{
		cout << "Friendship is magic!^^\n";
	}
}