/*input
3
3 4
4 6
3 5
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
	int H = 1000000000;
	while (n--)
	{
		int a[2];
		cin >> a[0] >> a[1];
		sort(a, a + 2);
		if (a[1] <= H)
		{
			H = a[1];
		}
		else if (a[0] <= H)
		{
			H = a[0];
		}
		else
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}