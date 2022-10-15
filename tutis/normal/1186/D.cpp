/*input
4
4.58413
1.22491
-2.10517
-3.70387
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll suma = 0;
	vector<pair<int, int>>aa;
	while (n--)
	{
		ld a;
		cin >> a;
		int x = round(floor(a));
		int x_ = round(ceil(a));
		suma += x;
		aa.push_back({x, x_});
	}
	for (pair<int, int>i : aa)
	{
		int x = i.first;
		if (suma < 0)
		{
			suma += i.second - i.first;
			x = i.second;
		}
		cout << x << "\n";
	}
}