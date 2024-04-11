/*input
1
100
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
	map<int, int>A;
	while (n--)
	{
		int a;
		cin >> a;
		A[a]++;
		ans = max(ans, A[a]);
	}
	cout << ans << "\n";

}