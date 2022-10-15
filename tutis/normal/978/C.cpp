/*input
2 3
5 10000000000
5 6 9999999999
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll dorm = 0;
	ll sum = 0;
	while (m--)
	{
		ll num;
		cin >> num;
		while (num - sum > a[dorm])
		{
			sum += a[dorm];
			dorm++;
		}
		cout << dorm + 1 << " " << num - sum << "\n";
	}
}