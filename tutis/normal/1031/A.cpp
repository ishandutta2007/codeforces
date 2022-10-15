/*input
3 3 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int ceiling(int a, int b)
{
	if (a % b == 0)
		return a / b;
	return a / b + 1;
}
int main()
{
	int ans = 0;
	ios_base::sync_with_stdio(false);
	int w, h, k;
	cin >> w >> h >> k;
	for (int i = 1; i <= k; i++)
	{
		int a = w - 4 * (i - 1);
		int b = h - 4 * (i - 1);
		if (a == 1 || b == 1)
			ans += max(a, b);
		else
			ans += 2 * a + 2 * b - 4;
	}
	cout << ans << "\n";
}