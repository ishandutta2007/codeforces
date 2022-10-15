/*input
4 1
1 2
1 3
2 4

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace {
template<typename A, typename B>
istream &operator>>( istream  &input, pair<A, B> &X ) {
	input >> X.first >> X.second;
	return input;
}
template<typename A, typename B>
ostream &operator<<( ostream &output, const pair<A, B> &X ) {
	output << X.first << " " << X.second;
	return output;
}
template<typename T>
istream &operator>>( istream  &input, vector<T> &X ) {
	for (T&i : X)
		input >> i;
	return input;
}
template<typename T>
ostream &operator<<( ostream &output, const vector<T> &X ) {
	for (ll t = 0; t < (ll)X.size(); t++)
	{
		if (t + 1 != (ll)X.size())
			cout << X[t] << " ";
		else
			cout << X[t];
	}
	return output;
}
}
namespace {
const ll mod = 1000000007;
ll power(ll x, ll y)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
const ll maxsz = 10;
ll I[maxsz];
bool calc = false;
ll inv(ll x)
{
	if (x >= 0 && x < maxsz)
	{
		if (!calc)
		{
			calc = true;
			I[1] = 1;
			I[0] = 0;
			for (ll i = 2; i < maxsz; ++i)
				I[i] = (mod - (mod / i) * I[mod % i] % mod) % mod;
		}
		return I[x];
	}
	return power(x, mod - 2);
}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int>adj[n + 1];
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int d[n + 1];
	int kie[n + 1];
	int K[n + 1];
	int pa[n + 1];
	int sz[n + 1];
	function<void(int, int)>dfs = [&](int i, int p)
	{
		pa[i] = p;
		kie[i] = 0;
		K[i] = 0;
		sz[i] = 1;
		for (int j : adj[i])
		{
			if (j == p)
				continue;
			kie[i]++;
			K[i]++;
			d[j] = d[i] + 1;
			dfs(j, i);
			sz[i] += sz[j];
		}
	};
	d[1] = 0;
	dfs(1, 0);
	bool mark[n + 1];
	fill_n(mark, n + 1, false);
	set<pair<int, int>, greater<pair<int, int>>>C;
	for (int i = 1; i <= n; i++)
		if (K[i] == 0)
			C.insert({d[i] - sz[i], i});
	K[0] = 10;
	while (k > 0)
	{
		auto it = C.begin();
		int i = it->second;
		mark[i] = true;
		k--;
		C.erase(it);
		K[pa[i]]--;
		if (K[pa[i]] == 0)
			C.insert({d[pa[i]] - sz[pa[i]], pa[i]});
	}
	ll ans = 0;
	function<void(int, int, ll)>dfs1 = [&](int i, int p, ll sum)
	{
		if (mark[i])
			ans += sum;
		else
			sum++;
		for (int j : adj[i])
		{
			if (j == p)
				continue;
			dfs1(j, i, sum);
		}
	};
	dfs1(1, 1, 0);
	cout << ans << "\n";
	return 0;
}