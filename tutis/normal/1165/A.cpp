/*input
11 5 1
11010100101

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	int ans = 0;
	for (int i = 0; i < x; i++)
	{
		char koks = '0';
		if (i == y)
			koks = '1';
		ans += s[i] != koks;
	}
	cout << ans << "\n";
}