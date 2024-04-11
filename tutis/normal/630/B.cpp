/*input
1000 1000000
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	ld n;
	cin >> n;
	ll t;
	cin >> t;
	cout << fixed << setprecision(15) << n * powl(1.000000011, t) << "\n";
}