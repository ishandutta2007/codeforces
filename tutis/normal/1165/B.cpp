/*input
4
3 1 4 1

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
	multiset<int>a;
	while (n--)
	{
		int x;
		cin >> x;
		a.insert(x);
	}
	int ans = 0;
	for (int k = 1;; k++)
	{
		auto it = a.lower_bound(k);
		if (it != a.end())
		{
			a.erase(it);
			ans = k;
		}
		else
			break;
	}
	cout << ans << "\n";
}