/*input
3
10 5 7
10 10 10
2 1 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int n, s, t;
		cin >> n >> s >> t;
		int ans = n;
		int pert = s + t - n;
		{
			s -= pert;
			t -= pert;
			ans = max(s, t) + 1;
		}
		cout << ans << "\n";
	}


}