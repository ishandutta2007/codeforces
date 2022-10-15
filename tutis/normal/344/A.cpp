/*input
6
10
10
10
01
10
10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int ans = 1;
	int n;
	cin >> n;
	string a[n];
	for (auto &i : a)
		cin >> i;
	for (int i = 1; i < n; i++)
	{
		ans += (a[i - 1][1] == a[i][0]);
	}
	cout << ans << "\n";
}