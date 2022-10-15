/*input
5
6
3
*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int b, g, n;
	cin >> b >> g >> n;
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		int j = n - i;
		if (i <= b && j <= g)
			ans++;
	}
	cout << ans << "\n";
}