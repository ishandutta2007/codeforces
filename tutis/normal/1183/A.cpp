/*input
432
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int a;
	cin >> a;
	for (int n = a;; n++)
	{
		string s = to_string(n);
		int k = 0;
		for (char c : s)
			k += (c - '0');
		if (k % 4 == 0)
		{
			cout << n << "\n";
			return 0;
		}
	}
}