/*input
201920181
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int ans[s.size()];
	map<int, int>X;
	int suma = 0;
	for (int t = 0; t < s.size(); t++)
	{
		ans[t] = 0;
		suma += (s[t] - '0');
		suma %= 3;
		if (suma == 0)
			ans[t] = 1;
		if (X.count(suma) && X[suma] >= 0)
			ans[t] = max(ans[t], ans[X[suma]] + 1);
		if (t > 0)
			ans[t] = max(ans[t], ans[t - 1]);
		X[suma] = t;
	}
	cout << ans[s.size() - 1] << "\n";
}