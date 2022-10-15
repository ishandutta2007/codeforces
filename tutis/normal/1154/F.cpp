/*input
7 4 5
2 5 4 2 6 3 1
2 1
6 5
2 1
3 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	ll N, M, k;
	cin >> N >> M >> k;
	vector<ll>aa;
	aa.push_back(0);
	while (N--)
	{
		ll c;
		cin >> c;
		aa.push_back(c);
	}
	sort(aa.begin(), aa.end());
	for (ll i = 1; i < aa.size(); i++)
		aa[i] += aa[i - 1];
	ll K[k + 1];
	fill_n(K, k + 1, 0);
	while (M--)
	{
		ll x, y;
		cin >> x >> y;
		if (x > k)
			continue;
		K[x] = max(K[x], y);
	}
	ll DP[k + 1];
	fill_n(DP, k + 1, 1e9);
	DP[0] = 0;
	for (ll a = 0; a <= k; a++)
	{
		for (ll c = 1; a + c <= k; c++)
		{
			DP[a + c] = min(DP[a + c], DP[a] + (aa[a + c] - aa[a + c - (c - K[c])]));
		}
	}
	cout << DP[k] << "\n";
}