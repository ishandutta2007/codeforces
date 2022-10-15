/*input
3 222
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	k = 240 - k;
	int ans = 0;
	for (int i = 1; i <= n && k >= i * 5; i++)
	{
		k -= i * 5;
		ans++;
	}
	cout << ans << "\n";
}