/*input
4 4
zzzz
zzz.
.z..
zzzz
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1000000007;
string s[3000];
ll L[3000][3000], R[3000][3000];
ll f(vector<ll>&a, vector<ll>&b)
{
	ll ans = 0;
	vector<pair<ll, ll>>off[(int)a.size() + 1];
	for (ll i = 0; i < (ll)a.size(); i++)
	{
		off[i + 1].push_back({ -i, 1});
		off[max(0ll, i + 1 - b[i])].push_back({ -i, -1});
	}
	oset<pair<ll, ll>> A;
	for (ll i = 0; i < (ll)a.size(); i++)
	{
		A.insert({ -a[i] - i + 1, i});
		for (pair<ll, ll>j : off[i + 1])
		{
			ans += j.second * A.order_of_key({j.first, 50000});
		}
	}
	a.clear();
	b.clear();
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < n; i++)
	{
		cin >> s[i];
		for (ll j = 0; j < m; j++)
		{
			if (s[i][j] == 'z')
			{
				if (j != 0)
					L[i][j] = 1 + L[i][j - 1];
				else
					L[i][j] = 1;
			}
		}
		for (ll j = m - 1; j >= 0; j--)
		{
			if (s[i][j] == 'z')
			{
				if (j != m - 1)
					R[i][j] = 1 + R[i][j + 1];
				else
					R[i][j] = 1;
			}
		}
	}
	ll ans = 0;
	for (ll ij = 0; ij <= (n - 1) + (m - 1); ij++)
	{
		vector<ll>a;
		vector<ll>b;
		for (ll i = 0; i < n; i++)
		{
			ll j = ij - i;
			if (j >= 0 && j < m)
			{
				if (s[i][j] == 'z')
				{
					a.push_back(L[i][j]);
					b.push_back(R[i][j]);
				}
				else
				{
					ans += f(a, b);
				}
			}
		}
		ans += f(a, b);
	}
	cout << ans << "\n";
}