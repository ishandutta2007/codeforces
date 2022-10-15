/*input
3
6
101101
10
1001101101
4
1100
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
//using ull = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt1 = 0;
		for (char c : s)
			if (c == '1')
				cnt1++;
		int k = 0;
		string a(n, '-'), b(n, '-');
		bool a1 = false;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				if (k < cnt1 / 2)
				{
					a[i] = b[i] = '(';
				}
				else
					a[i] = b[i] = ')';
				k++;
			}
			else
			{
				if (a1)
				{
					a[i] = '(';
					b[i] = ')';
				}
				else
				{
					b[i] = '(';
					a[i] = ')';
				}
				a1 = !a1;
			}
		}
		bool ok = true;
		for (string cc : {a, b})
		{
			int cnt = 0;
			for (char c : cc)
			{
				if (c == '(')
					cnt++;
				else
					cnt--;
				if (cnt < 0)
					ok = false;
			}
			if (cnt != 0)
				ok = false;
		}
		if (ok)
		{
			cout << "YES\n";
			cout << a << "\n" << b << "\n";
		}
		else
			cout << "NO\n";
	}
}