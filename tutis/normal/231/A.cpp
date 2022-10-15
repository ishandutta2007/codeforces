/*input
3
1 1 0
1 1 1
1 0 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0;
	while (n--)
	{
		int t[3];
		for (int &i : t)
			cin >> i;
		if (accumulate(t, t + 3, 0) >= 2)
		{
			ans++;
		}
	}
	cout << ans << "\n";
}