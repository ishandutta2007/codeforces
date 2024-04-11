/***
6 10
7 4 7
5 8 8
12 5 8
6 11 6
3 3 7
5 9 6
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct zm
{
	ll s, a, b;
	bool operator<(zm B)const
	{
		return a - b > B.a - B.b;
	}
};
ll N, S;
zm X[100009];
zm Y[100009];
ll price(ll a, ll b)
{
	if (a < 0 || b < 0)
		return 0;
	ll g1 = a * S;
	ll g2 = b * S;
	ll ans = 0;
	for (int i = 0; i < N; i++)
		Y[i] = X[i];
	for (ll i = 0; i < N; i++)
	{
		if (X[i].a >= X[i].b)
		{
			ll k = min(g1, X[i].s);
			g1 -= k;
			X[i].s -= k;
			ans += k * X[i].a;
		}
	}
	for (ll i = N - 1; i >= 0; i--)
	{
		if (X[i].b >= X[i].a)
		{
			ll k = min(g2, X[i].s);
			g2 -= k;
			X[i].s -= k;
			ans += k * X[i].b;
		}
	}
	for (ll i = 0; i < N; i++)
	{
		{
			ll k = min(g1, X[i].s);
			g1 -= k;
			X[i].s -= k;
			ans += k * X[i].a;
		}
	}
	for (ll i = N - 1; i >= 0; i--)
	{
		{
			ll k = min(g2, X[i].s);
			g2 -= k;
			X[i].s -= k;
			ans += k * X[i].b;
		}
	}
	for (int i = 0; i < N; i++)
		X[i] = Y[i];
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> S;
	for (ll i = 0; i < N; i++)
		cin >> X[i].s >> X[i].a >> X[i].b;
	ll picu = 0;
	ll suma = 0;
	for (ll i = 0; i < N; i++)
		suma += X[i].s;
	picu = 1 + (suma - 1) / (S);
	ll a = 0;
	sort(X, X + N);
	while (X[a].a - X[a].b > 0 && a + 1 < N)
		a++;
	ll A = 0;
	ll B = 0;
	for (ll i = 0; i < a; i++)
		A += X[i].s;
	for (ll i = a; i < N; i++)
		B += X[i].s;
	ll k = A / S;
	ll ans = max(price(0ll, picu), price(picu, 0ll));
	for (ll d = -7; d <= 7; d++)
	{
		ans = max(ans, price(k + d, picu - k - d));
	}
	cout << ans << endl;
}