/*input
2
1 2 2 2
1 1 2 2

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = abs(a - c);
		int y = abs(b - d);
		if (x == 0 || y == 0)
			cout << x + y << "\n";
		else
			cout << x + y + 2 << "\n";
	}
}