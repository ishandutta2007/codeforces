/***
22
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll N;
	cin >> N;
	ll ans = LONG_LONG_MAX;
	for (int a = 1; a <= N; a++)
	{
		ll b = 1 + ((N - 1) / a);
		ans = min(ans, 2 * a + 2 * b);
	}
	cout << ans;
}