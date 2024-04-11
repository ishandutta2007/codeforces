/*input
3 7
4 5 14
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, h;
	cin >> n >> h;
	int ans = 0;
	while (n--)
	{
		int a;
		cin >> a;
		if (a <= h)
			ans++;
		else
			ans += 2;
	}
	cout << ans << "\n";
}