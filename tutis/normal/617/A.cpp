/*input
12
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[2][500 + 1][500 + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	ll x;
	cin >> x;
	cout << (x - 1) / 5 + 1 << "\n";
}