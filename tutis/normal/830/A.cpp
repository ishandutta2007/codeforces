/***
1 2 10
11
15 7
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF ll(1e15)
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int n, k, p;
	cin >> n >> k >> p;
	ll a[n];
	ll b[k];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < k; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + k);
	ll ans = INF;
	for (int st = 0; st <= k - n; st++)
	{
		ll rez = 0;
		for (int i = 0; i < n; i++)
			rez = max(rez, abs(a[i] - b[st + i]) + abs(b[st + i] - p));
		ans = min(ans, rez);
	}
	cout << ans;
}