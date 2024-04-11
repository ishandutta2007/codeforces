/*input
5 4
2 4 5 3 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int suma[n + 1];
	suma[0] = 0;
	ll ans = 0;
	map<pair<int, int>, int>KIEK;
	KIEK[ {0 % 2, suma[0]}]++;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if (a == m)
			suma[i] = suma[i - 1] + 0;
		if (a < m)
			suma[i] = suma[i - 1] - 1;
		if (a > m)
			suma[i] = suma[i - 1] + 1;
		ans += KIEK[ {(i) % 2, suma[i] - 1}];
		ans += KIEK[ {(i + 1) % 2, suma[i]}];
		KIEK[ {i % 2, suma[i]}]++;
	}
	cout << ans << "\n";
}