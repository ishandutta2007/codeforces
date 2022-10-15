/*input
5
1 2 3 7 8
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 2000;
	for (int r = 1; r < n - 1; r++)
	{
		vector<int>x;
		for (int i = 0; i < n; i++)
			if (i != r)
				x.push_back(a[i]);
		int gal = 0;
		for (int i = 1; i < x.size(); i++)
			gal = max(gal, x[i] - x[i - 1]);
		ans = min(ans, gal);
	}
	cout << ans << "\n";

}