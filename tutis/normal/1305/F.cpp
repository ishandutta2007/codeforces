/*input
5
9 8 7 3 1
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,aes,avx,avx2")
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename A, typename B>
using Map = tree<A, B, less<A>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1000000000 + 7;
bitset<1001000>pr;
ll pr1[4004000];
int main()
{
	pr.flip();
	pr[0] = pr[1] = false;
	vector<ll>P;
	for (int i = 2; i < 1001000; i++)
	{
		if (pr[i])
		{
			for (int j = i; j < 1001000; j += i)
				pr[j] = false;
			P.push_back(i);
		}
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll a[n];
	for (ll &i : a)
		cin >> i;
	shuffle(a, a + n, rng);
	ll ans = n;
	ll lo = max(2ll, a[0] - 3);
	ll hi = a[0] + 3;
	for (ll x = lo; x <= hi; x++)
		pr1[x - lo] = x;
	vector<ll>Q = {2};
	for (ll i : P)
	{
		bool yra = false;
		ll y = i;
		while (y <= 1e12)
		{
			for (ll x = y * ((lo - 1) / y + 1); x <= hi; x += y)
			{
				yra = true;
				pr1[x - lo] /= i;
			}
			y *= i;
		}
		if (yra)
			Q.push_back(i);
	}
	for (ll x = lo; x <= hi; x++)
	{
		if (pr1[x - lo] != 1)
			Q.push_back(pr1[x - lo]);
	}
	shuffle(Q.begin(), Q.end(), rng);
	for (ll p : Q)
	{
		ll kiek = 0;
		for (ll i : a)
		{
			if (i <= p)
				kiek += p - i;
			else
			{
				i %= p;
				kiek += min(i, p - i);
			}
			if (kiek > ans)
				break;
		}
		ans = min(ans, kiek);
	};
	cout << ans << "\n";
}