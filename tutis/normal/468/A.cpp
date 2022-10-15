/*input
5
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	if (n <= 3)
	{
		cout << "NO\n";
		return 0;
	}
	if (n % 2 == 4 % 2)
	{
		cout << "YES\n";
		vector<ll>x = {1, 2, 3, 4};
		for (int i = 5; i <= n; i += 2)
		{
			cout << i + 1 << " - " << i << " = 1\n";
			x.push_back(1);
		}
		while (x.size() > 1)
		{
			cout << x[x.size() - 2] << " * " << x.back() << " = " << x.back()*x[x.size() - 2] << "\n";
			x[x.size() - 2] *= x.back();
			x.pop_back();
		}
	}
	else
	{
		cout << "YES\n";
		cout << "5 + 1 = 6\n";
		cout << "3 - 2 = 1\n";
		cout << "1 * 4 = 4\n";
		cout << "4 * 6 = 24\n";
		vector<ll>x = {24};
		for (int i = 6; i <= n; i += 2)
		{
			cout << i + 1 << " - " << i << " = 1\n";
			x.push_back(1);
		}
		while (x.size() > 1)
		{
			cout << x[x.size() - 2] << " * " << x.back() << " = " << x.back()*x[x.size() - 2] << "\n";
			x[x.size() - 2] *= x.back();
			x.pop_back();
		}
	}
}