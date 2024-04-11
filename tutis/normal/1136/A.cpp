/*input
1
1 7
4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int l[n], r[n];
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];
	int k;
	cin >> k;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (k <= r[i])
			ans++;
	}
	cout << ans << "\n";
}