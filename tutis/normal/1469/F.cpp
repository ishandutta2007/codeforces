/*input
3 3
4 3 3

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
using ull = unsigned long long;
using ll = long long;
using ld = long double;
const int mxans = 100000000;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int>l(n);
	for (int i = 0; i < n; i++)
		cin >> l[i];
	sort(l.begin(), l.end(), greater<int>());
	cc_hash_table<int, int>P;
	P[0]++;
	P[1]--;
	int d0 = 0;
	int d1 = 0;
	int cnt0 = 1;
	int cnt1 = 1;
	ll sum0 = 1;
	ll sum1 = 1;
	int ans = mxans;
	ll yra = 1;
	auto add = [&](int kur, int kiek)
	{
		P[kur] += kiek;
		if (kur <= d0)
		{
			cnt0 += kiek;
			sum0 += (d0 - kur + 1) * kiek;
		}
		if (kur <= d1)
		{
			cnt1 += kiek;
			sum1 += (d1 - kur + 1) * kiek;
		}
	};
	auto add1 = [&](int x)
	{
		if (x == 1)
		{
			d1++;
			cnt1 += P[d1];
			sum1 += cnt1;
		}
		else
		{
			sum1 -= cnt1;
			cnt1 -= P[d1];
			d1--;
		}
	};
	for (int x : l) {
		while (sum0 == 0)
		{
			d0++;
			cnt0 += P[d0];
			sum0 += cnt0;
		}
		add(d0 + 1, 1);
		add(d0, -1);
		int c1 = x / 2;
		int c2 = x - 1 - c1;
		yra += c1;
		yra += c2;
		yra--;
		add(d0 + 2, 2);
		add(d0 + 2 + c1, -1);
		add(d0 + 2 + c2, -1);
		if (yra >= k)
		{
			while (sum1 < k)
			{
				add1(1);
			}
			while (sum1 >= k)
			{
				add1(-1);
			}
			add1(1);
			ans = min(ans, d1);
		}

	}
	if (ans == mxans)
		ans = -1;
	cout << ans << "\n";
}