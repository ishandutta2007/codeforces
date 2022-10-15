/*input
4
2
13
37
100
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
map<int, int>X;
int ans(int n)
{
	if (n == 0)
		return 0;
	if (n < 0)
		return -100000;
	if (X.count(n))
		return X[n];
	int ret = -100000;
	for (int t = 2; t <= 7; t++)
		ret = max(ret, ans(n - t) + 1);
	return X[n] = ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int a;
		cin >> a;
		cout << ans(a) << "\n";
	}
}