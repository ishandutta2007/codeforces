/*input
10
1 10 2 9 3 8 4 7 5 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 500 * 500 + 1000;
int main()
{
	clock_t pradz = clock();
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int &i : a)
		cin >> i;
	int c = *min_element(a, a + n);
	for (int &i : a)
		i = i - c;
	ld lo = 0;
	ld hi = 1e7;
	while (true)
	{
		if (double(clock() - pradz) / CLOCKS_PER_SEC >= 1.7)
			break;
		ld x = (lo + hi) / 2;
		ld b[n];
		for (int i = 0; i < n; i++)
			b[i] = a[i] - x;
		ld mn[n];
		ld mx[n];
		mn[0] = mx[0] = b[0];
		for (int i = 1; i < n; i++)
		{
			mx[i] = max(mx[i - 1] + b[i], b[i]);
			mn[i] = min(mn[i - 1] + b[i], b[i]);
		}
		ld MXS = *max_element(mx, mx + n);
		ld MNS = *min_element(mn, mn + n);
		if (MXS <= 0)
		{
			hi = x;
			continue;
		}
		if (abs(MXS) >= abs(MNS))
		{
			lo = x;
		}
		else
		{
			hi = x;
		}
	}
	ld x = (lo + hi) / 2;
	ld b[n];
	for (int i = 0; i < n; i++)
		b[i] = a[i] - x;
	ld mn[n];
	ld mx[n];
	mn[0] = mx[0] = b[0];
	for (int i = 1; i < n; i++)
	{
		mx[i] = max(mx[i - 1] + b[i], b[i]);
		mn[i] = min(mn[i - 1] + b[i], b[i]);
	}
	ld MXS = *max_element(mx, mx + n);
	ld MNS = *min_element(mn, mn + n);
	cout << fixed << setprecision(25) << max(abs(MXS), abs(MNS)) << "\n";
}/**/