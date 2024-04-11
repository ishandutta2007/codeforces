/*input
3 5 2

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	ll a, b, c;
	cin >> a >> b >> c;
	if (b > a + 1)
		b = a + 1;
	if (a > b + 1)
		a = b + 1;
	cout << a + b + 2 * c << "\n";
}