/*input
125
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
	int ans = 0;
	for (int a : {100, 20, 10, 5, 1})
	{
		ans += n / a;
		n %= a;
	}
	cout << ans << "\n";
}