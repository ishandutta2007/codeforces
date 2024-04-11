/*input
1 0
2
3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll N;
	cin >> N;
	ll k;
	cin >> k;
	ll p[N];
	for (ll i = 0; i < N; i++)
		cin >> p[i];
	ll c[N];
	for (ll i = 0; i < N; i++)
		cin >> c[i];
	vector<ll> a(N);
	iota(a.begin(), a.end(), 0);
	sort(a.begin(), a.end(), [&](ll i, ll j) {return p[i] < p[j];});
	multiset<ll>X;
	ll suma = 0;
	map<ll, ll>XX;
	ll ans[N];
	for (ll i : a)
	{
		ans[i] = 0;
		for (auto x : XX)
		{
			if (x.first < p[i])
				ans[i] = max(ans[i], x.second);
		}
		ans[i] += c[i];
		suma += c[i];
		X.insert(c[i]);
		while (XX.size() > 2)
			XX.erase(XX.begin());
		while (X.size() > k)
		{
			auto it = X.begin();
			X.erase(it);
			suma -= (*it);
		}
		XX[p[i]] = suma;
	}
	for (ll i : ans)
		cout << i << " ";
}