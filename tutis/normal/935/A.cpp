/*input
2
10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		int ans = 0;
		for (int l = 1; l < n; l++)
		{
			int x = n - l;
			if (x % l == 0)
				ans++;
		}
		cout << ans << "\n";
	}
}