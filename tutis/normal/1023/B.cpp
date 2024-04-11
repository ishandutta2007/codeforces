/*input
8 15
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, k;
	cin >> n >> k;
	//a < k / 2 && a <= n && k - n <= a

	cout << max(0ll, min((k - 1) / 2, n) - max(1ll, k - n)+1) << "\n";
}