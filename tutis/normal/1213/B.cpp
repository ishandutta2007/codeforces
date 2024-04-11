/*input
5
6
3 9 4 6 7 5
1
1000000
2
2 1
10
31 41 59 26 53 58 97 93 23 84
7
3 2 1 2 3 4 5
*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int loo = a[n - 1] + 1;
		int ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] > loo)
				ans++;
			loo = min(loo, a[i]);
		}
		cout << ans << "\n";
	}


}