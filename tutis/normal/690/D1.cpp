/*input
3 7
.......
.......
.BB.B..
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int r, c;
	cin >> r >> c;
	int ans = 0;
	bool a[c + 2];
	fill_n(a, c + 2, false);
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			char x;
			cin >> x;
			if (x == 'B')
				a[j] = true;
		}
	}
	for (int j = 1; j <= c; j++)
	{
		if (a[j] && (!a[j + 1]))
			ans++;
	}
	cout << ans << "\n";
}