/*input
1 2 31
1
1 2

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(456456);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 1000000007;
ll egcd(ll n, ll m, ll &x, ll &y)
{
	if (n > m)
		return egcd(m, n, y, x);
	//xn+ym=g
	if (n == 0)
	{
		x = 0;
		y = 1;
		return m;
	}
	ll k = m / n;
	ll l = m % n;
	//xn+y(kn+l)=g
	//(x+yk)n+yl=g
	ll g = egcd(n, l, x, y);
	x -= y * k;
	return g;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	cc_hash_table<ll, ll>A;
	for (ll i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		A[a] = i;
	}
	ll x, y;
	ll g = egcd(n, m, x, y);
	//cout << x*n + y*m << " " << g << endl;
	ll kart = n * m / g;
	vector<ll>ind;
	for (ll j = 0; j < m; j++)
	{
		ll b;
		cin >> b;
		if (A.find(b) != A.end())
		{
			//xn+i=ym+j
			ll i = A[b];
			//xn-ym=j-i
			ll d = j - i;
			if (d % g == 0)
			{
				ll X = x * (j - i) / g;
				ll t = X * n + i;
				t %= kart;
				if (t < 0)
					t += kart;
				assert(t % n == i && t % m == j);
				ind.push_back(t);
			}
		}
	}
	sort(ind.begin(), ind.end());
	ll vien = kart - (ll)ind.size();
	ind.insert(ind.begin(), -1);
	ind.push_back(kart);
	ll c = k / vien;
	k -= c * vien;
	ll ans = c * kart;
	if (k == 0)
	{
		int cnt = 0;
		while (ind.back() == kart)
		{
			ind.pop_back();
			cnt++;
			kart--;
		}
		cout << ans - cnt + 1 << "\n";
		return 0;
	}
	for (int i = 1; i < ind.size(); i++)
	{
		ll i1 = ind[i - 1];
		ll i2 = ind[i];
		ll cnt = i2 - i1 - 1;
		if (k > 0)
		{
			if (cnt >= k)
			{
				ans += k;
				k = 0;
				break;
			}
			else
			{
				ans += cnt;
				k -= cnt;
			}
			ans++;
		}
	}
	assert(k == 0);
	cout << ans << "\n";
}