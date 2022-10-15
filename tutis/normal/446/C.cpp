/*input
4 4
1 2 3 4
1 1 4
2 1 4
1 2 4
2 1 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modulo = 1000000000 + 9;
ll F[300300];
struct ST
{
	int l, r;
	ll a = 0, b = 0;
	ll suma;
	ST *left = NULL;
	ST *right = NULL;
	ST(int l, int r, int a[]): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, a);
			right = new ST((l + r) / 2 + 1, r, a);
			suma = left->suma + right->suma;
			if (suma >= modulo)
				suma -= modulo;
		}
		else
		{
			suma = a[l];
		}
	}
	void fix()
	{
		if (l < r)
		{
			left->a += a;
			if (left->a >= modulo)
				left->a -= modulo;
			left->b += b;
			if (left->b >= modulo)
				left->b -= modulo;
			int n = (l + r) / 2 + 1 - l;
			right->a += F[n] * a + F[n + 1] * b;
			right->b += F[n + 1] * a + F[n + 2] * b;
			n = r - l + 1;
			suma += a * F[n + 1];
			suma += b * (F[n + 2] - 1);
			suma %= modulo;
			right->a %= modulo;
			right->b %= modulo;
		}
		else
		{
			suma += a;
			if (suma >= modulo)
				suma -= modulo;
		}
		a = 0;
		b = 0;
	}
	void update(ll x, ll y)
	{
		fix();
		if (y < l || r < x)
			return;
		if (x <= l && r <= y)
		{
			ll n = l - x;
			a = F[n + 2];
			b = F[n + 3];
			return fix();
		}
		left->update(x, y);
		right->update(x, y);
		suma = left->suma + right->suma;
		if (suma >= modulo)
			suma -= modulo;
	}
	ll sum(int x, int y)
	{
		fix();
		if (y < l || r < x)
			return 0;
		if (x <= l && r <= y)
			return suma;
		ll ret = left->sum(x, y) + right->sum(x, y);
		if (ret >= modulo)
			ret -= modulo;
		return ret;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	F[0] = 1;
	F[1] = 0;
	for (ll i = 2; i < 300300; i++)
		F[i] = (F[i - 1] + F[i - 2]) % modulo;
	ll n, m;
	cin >> n >> m;
	int a[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	ST medis(1, n, a);
	while (m--)
	{
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1)
		{
			medis.update(l, r);
		}
		else
		{
			cout << medis.sum(l, r) << "\n";
		}
	}
}