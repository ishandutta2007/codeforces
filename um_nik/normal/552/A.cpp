#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	while(n--)
	{
		int x, xx, y, yy;
		cin >> x >> y >> xx >> yy;
		ans += (abs(xx - x) + 1) * (abs(yy - y) + 1);
	}
	cout << ans << endl;

	return 0;
}