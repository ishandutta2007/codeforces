/*input
6 3
5 20 12 7 14 101

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<pair<int, int>, int>M;
int dp(int k0, int k1, int k, int kas = 0)
{
	if (M.count({k0, k1}))
		return M[ {k0, k1}];
	if (min(k0, k1) > 50 && k0 + k1 - 4 >= k + 10)
	{
		return dp(k0 - 2, k1 - 2, k, kas);
	}
	if (k0 + k1 == k)
	{
		if (k1 % 2 == 1)
			return 0;
		else
			return 1;
	}
	if (k0 == 0)
		return dp(k0, k1 - 1, k, 1 - kas);
	if (k1 == 0)
		return dp(k0 - 1, k1, k, 1 - kas);
	if (rand() % 2 == 0)
	{
		if (dp(k0 - 1, k1, k, 1 - kas) == kas)
			return M[ {k0, k1}] = kas;
		if (dp(k0, k1 - 1, k, 1 - kas) == kas)
			return M[ {k0, k1}] = kas;
	}
	else
	{
		if (dp(k0, k1 - 1, k, 1 - kas) == kas)
			return M[ {k0, k1}] = kas;
		if (dp(k0 - 1, k1, k, 1 - kas) == kas)
			return M[ {k0, k1}] = kas;
	}
	return M[ {k0, k1}] = 1 - kas;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int k0 = 0, k1 = 0;
	while (n--)
	{
		int a;
		cin >> a;
		if (a % 2 == 1)
			k1++;
		else
			k0++;
	}
	int x = dp(k0, k1, k);
	if (x == 0)
		cout << "Stannis\n";
	else
		cout << "Daenerys\n";
}