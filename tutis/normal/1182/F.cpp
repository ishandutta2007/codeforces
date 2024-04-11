/*input
2
0 3 1 3
17 86 389 995
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		ll a, b, p, q;
		cin >> a >> b >> p >> q;
		ll t = sqrt(b - a + 1) + 5;
		deque<pair<ll, ll>>A;
		for (ll x = a; x <= a + t && x <= b; x++)
		{
			A.push_back({(p * x) % q, x});
		}
		sort(A.begin(), A.end());
		for (int i = 1; i < (int)A.size();)
		{
			if (A[i].first == A[i - 1].first)
				A.erase(A.begin() + i);
			else
				i++;
		}
		pair<ll, ll>mx = { -1, -1};
		for (ll x = b; x >= a && x >= b - t; x--)
		{
			ll a = (p * x) % q;
			a = min(a, q - a);
			mx = max(mx, {a, -x});
		}
		for (ll i = 0; a + (t - 1) + t * i <= b; i++)
		{
			ll target = (q / 2 - i * t * p) % q;
			if (target < 0)
				target += q;
			auto it = upper_bound(A.begin(), A.end(), make_pair(target, b + 5));
			if (it != A.end())
			{
				ll x = it->second + i * t;
				ll a = (p * x) % q;
				a = min(a, q - a);
				mx = max(mx, {a, -x});
			}
			if (it != A.begin())
			{
				it--;
				ll x = it->second + i * t;
				ll a = (p * x) % q;
				a = min(a, q - a);
				mx = max(mx, {a, -x});
			}
		}
		cout << -mx.second << "\n";
	}
}