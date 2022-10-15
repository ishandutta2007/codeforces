/*input
3
4 1 7
-2 4 -1
1 -5 -3
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
	int a = 0, b = 0, c = 0;
	while (n--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		a += x;
		b += y;
		c += z;
	}
	if (abs(a) + abs(b) + abs(c) == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
}