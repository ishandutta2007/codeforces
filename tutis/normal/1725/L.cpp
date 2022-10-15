/*input
7
2 -1 -1 5 2 -2 9

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(0);
const ll mod = 1e9 + 7;
ll p(ll x, ll y)
{
	ll r = 1;
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		y /= 2;
		x = (x * x) % mod;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	ll A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 1; i < N; i++)
		A[i] += A[i - 1];
	bool ok = true;
	for (int i = 0; i < N; i++)
		ok &= A[i] >= 0;
	for (int i = 0; i < N; i++)
		ok &= A[N - 1] >= A[i];
	if (!ok)
	{
		cout << "-1\n";
		return 0;
	}
	vector<pair<ll, int>>X;
	for (int i = 0; i < N; i++)
		X.push_back({A[i], i});
	sort(X.begin(), X.end());
	int p[N];
	int q[N];
	for (int i = 0; i < N; i++)
	{
		p[i] = X[i].second;
	}
	ll ret = 0;
	oset<int>S;
	for (int i = 0; i < N; i++)
	{
		int c = S.order_of_key(p[i]);
		ret += (int)S.size() - c;
		S.insert(p[i]);
	}
	cout << ret << "\n";
	return 0;
}