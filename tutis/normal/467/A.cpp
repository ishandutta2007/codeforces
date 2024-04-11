/*input
3
1 10
0 10
10 10
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
	int ans = 0;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		ans += b - a >= 2;
	}
	cout << ans << "\n";
}