/*input
6
aaa bb aaa aaa bb aaa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll modulo = 1000000007;
ll mod(ll x, ll m = modulo)
{
	return (x % m);
}
ll power(ll x, ll a)
{
	x = mod(x);
	ll ret = 1;
	ll k = 1;
	while (a)
	{
		if ((k & a) > 0)
		{
			a ^= k;
			ret = mod(ret * x);
		}
		k <<= 1;
		x = mod(x * x);
	}
	return ret;
}
ll inv(ll x)
{
	return power(x, modulo - 2);
}
int main()
{
	srand(time(NULL));
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	string w[n];
	for (ll i = 0; i < n; i++)
		cin >> w[i];
	ll ilgis[n];
	for (ll i = 0; i < n; i++)
		ilgis[i] = w[i].size();
	ll sumos[n + 1];
	sumos[0] = 0;
	for (ll i = 0; i < n; i++)
		sumos[i + 1] = sumos[i] + ilgis[i];
	ll skaicius[n];
	map<string, ll>M;
	for (ll i = 0; i < n; i++)
	{
		if (M.count(w[i]) == 0)
			M[w[i]] = mod(ll(rand()) + ll(rand()) * RAND_MAX);
		skaicius[i] = M[w[i]];
	}
	ll S[n + 1];
	ll X = rand() % 1351 + 973;
	S[0] = 0;
	ll X_ = 1;
	for (ll i = 1; i <= n; i++)
	{
		S[i] = skaicius[i - 1] * X_;
		S[i] += S[i - 1];
		S[i] %= modulo;
		X_ *= X;
		X_ %= modulo;
	}
	ll ans = n - 1;
	for (ll i = 0; i < n; i++)
		ans += ilgis[i];
	ll suma = ans;
	ll PWR[n + 2];
	PWR[0] = 1;
	PWR[1] = inv(X);
	for (ll i = 2; i < n + 2; i++)
		PWR[i] = mod(PWR[i - 1] * PWR[1]);
	auto HASH = [&](ll l, ll r)->ll
	{
		return mod(mod(S[r + 1] - S[l] + modulo) * PWR[l]);
	};
	for (int k = 0; k < n; k++)
	{
		map<int, pair<int, int>>G;
		for (int r = k; r < n; r++)
		{
			int H = HASH(r - k, r);
			if (G.count(H))
			{
				pair<int, int> &a = G[H];
				if (a.second < r - k)
				{
					ll ansx = suma;
					ansx -= (sumos[r + 1] - sumos[r - k] - 1) * (a.first + 1);
					ans = min(ans, ansx);
					a = {a.first + 1, r};
				}
			}
			else
				G[H] = {1, r};
		}
	}
	cout << ans << "\n";
}