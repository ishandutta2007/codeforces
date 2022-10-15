/*input
2 2
0 0 0 1
1 0 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n * m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > 0 || b > 0)
			ans++;
	}
	cout << ans << "\n";
}