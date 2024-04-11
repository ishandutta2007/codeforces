/***
2 100
2 42
2 58
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct problem
{
	ll a, t;
	ll i;
	problem() {}
	problem(ll a, ll t, ll i): a(a), t(t), i(i) {}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, T;
	cin >> n >> T;
	vector<problem> X;
	for (ll i = 1; i <= n; i++)
	{
		ll a, b;
		cin >> a >> b;
		X.push_back(problem(a, b, i));
	}
	sort(X.begin(), X.end(), [](problem a, problem b) {return a.a < b.a;});
	ll suma = 0;
	set<pair<ll, ll>>el;
	ll time = 0;
	ll K = 0;
	for (ll k = n; k >= 0; k--)
	{
		while (!X.empty() && X.back().a >= k)
		{
			ll a = X.back().t;
			ll i = X.back().i;
			el.insert(make_pair(a, i));
			time += a;
			X.pop_back();
		}
		while (el.size() > k)
		{
			time -= (*(--el.end())).first;
			el.erase(--el.end());
		}
		if (time <= T && el.size() == k)
		{
			cout << k << "\n";
			cout << k << "\n";
			for (pair<ll, ll>a : el)
				cout << a.second << " ";
			return 0;
		}
	}
	cout << "0\n0\n";
}