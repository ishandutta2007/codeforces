/*input
7
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (ll k = 1;; k++)
	{
		string s = to_string(k);
		if (n <= s.size())
		{
			cout << s[n - 1] << "\n";
			return 0;
		}
		else
			n -= s.size();
	}
}