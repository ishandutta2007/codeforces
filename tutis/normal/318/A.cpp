/*input
10 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool NonDistinct(int x)
{
	set<int>Y;
	while (x > 0)
	{
		Y.insert(x % 10);
		x /= 10;
	}
	return Y.size() != 4;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	if (k <= (n + 1) / 2)
	{
		cout << 2 * k - 1 << "\n";
		return 0;
	}
	k -= (n + 1) / 2;
	cout << 2 * k << "\n";
}