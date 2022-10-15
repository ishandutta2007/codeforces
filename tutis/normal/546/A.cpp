/*input
3 17 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[2][500 + 1][500 + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	ll k, n, w;
	cin >> k >> n >> w;
	cout << max(0ll, k * w * (w + 1) / 2 - n) << "\n";
}