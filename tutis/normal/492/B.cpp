/*input
7 15
15 5 3 7 9 14 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool lucky(ll x)
{
	while (x > 0)
	{
		if ((x % 10) == 8)
			return true;
		x /= 10;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, l;
	cin >> n >> l;
	vector<int>a;
	while (n--)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	ld ans = 0;
	ans = max(ans, ld(a.front()));
	ans = max(ans, ld(l - a.back()));
	for (int i = 1; i < a.size(); i++)
		ans = max(ans, ld(a[i] - a[i - 1]) / 2.0);
	cout << fixed << setprecision(30) << ans << "\n";

}