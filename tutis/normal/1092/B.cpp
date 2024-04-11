/*input
6
5 10 2 3 14 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for (int i = 1; i < n; i += 2)
		ans += abs(a[i] - a[i - 1]);
	cout << ans << "\n";
}