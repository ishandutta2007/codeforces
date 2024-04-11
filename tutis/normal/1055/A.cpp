/*input
5 2
0 1 1 1 1
1 1 1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int b[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	if (a[1] && a[s])
	{
		cout << "YES\n";
		return 0;
	}
	for (int x = s; x <= n; x++)
	{
		if (a[1] && a[x] && b[x] && b[s])
		{
			cout << "YES\n";
			return 0;

		}
	}
	cout << "NO\n";
}