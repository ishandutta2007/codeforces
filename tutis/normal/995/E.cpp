/*input
1 3 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll u, v, p;
ll mod(ll x)
{
	x %= p;
	x += p;
	x %= p;
	return x;
}
ll inv(ll x)
{
	x = mod(x);
	ll a = p - 2;
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
ll f(ll x, ll c)
{
	if (c == 1)
		return mod(x + 1);
	if (c == 2)
		return mod(x - 1);
	return inv(x);
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> u >> v >> p;
	ll kiek = 50000;
	map<ll, vector<int>>X;
	while (kiek--)
	{
		vector<int>C;
		ll V = u;
		while (C.size() < 100)
		{
			C.push_back(rand() % 3 + 1);
			V = f(V, C.back());
			X[V] = C;
		}
	}
	while (true)
	{
		vector<int>C;
		ll V = v;
		while (C.size() < 100)
		{
			C.push_back(rand() % 3 + 1);
			V = f(V, C.back());
			if (X.count(V))
			{
				int kiek = X[V].size() + C.size();
				cout << kiek << "\n";
				for (int i : X[V])
					cout << i << " ";
				reverse(C.begin(), C.end());
				for (int i : C)
				{
					if (i <= 2)
						cout << 3 - i << " ";
					else
						cout << i << " ";
				}
				return 0;
			}
		}
	}


}