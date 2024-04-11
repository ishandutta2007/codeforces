/*input
1
2
3
5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, a, b, c;
map<pair<int, char>, int>X;
int dp(int k, char x)
{
	if (k == 1)
		return 0;
	if (X.count({k, x}))
		return X[ {k, x}];
	if (x == 'r')
		return X[ {k, x}] = min(dp(k - 1, 'o') + a, dp(k - 1, 'e') + b);
	if (x == 'o')
		return X[ {k, x}] = min(dp(k - 1, 'r') + a, dp(k - 1, 'e') + c);
	if (x == 'e')
		return X[ {k, x}] = min(dp(k - 1, 'o') + c, dp(k - 1, 'r') + b);
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b >> c;
	cout << dp(n, 'r') << "\n";
}