/*input
3
8
1 0
4 1
2 0
4 1
5 1
6 1
3 0
2 0
4
1 1
1 1
2 1
2 1
9
2 0
2 0
4 1
4 1
4 1
7 0
7 1
7 0
7 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		pair<ll, ll> kiek[n];
		for (int i = 0; i < n; i++)
			kiek[i] = {0ll, 0ll};
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			kiek[a - 1].first++;
			kiek[a - 1].second += b;
		}
		sort(kiek, kiek + n, greater<pair<ll, ll>>());
		ll ans = 0;
		ll xx = n + 10;
		vector<ll>K;
		for (int i = 0; i < n; i++)
		{
			ll x = max(0ll, min(xx, kiek[i].first));
			ans += x;
			if (x != 0)
				K.push_back(x);
			xx = x - 1;
		}
		priority_queue<ll>Q;
		int id = 0;
		ll f1 = 0;
		for (ll k : K)
		{
			while (id < n && kiek[id].first >= k)
			{
				Q.push(kiek[id].second);
				id++;
			}
			f1 += min(k, Q.top());
			Q.pop();
		}
		cout << ans << " " << f1 << "\n";
	}
}