/*input
aabbbbbbc
6
1 2
2 4
2 2
1 9
5 7
3 5

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
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	int cnt[26][n + 1];
	for (int i = 0; i < 26; i++)
	{
		cnt[i][0] = 0;
		for (int j = 0; j < n; j++)
		{
			cnt[i][j + 1] = cnt[i][j];
			if (s[j] == 'a' + i)
				cnt[i][j + 1]++;
		}
	}
	int a[n];
	for (int i = n - 1; i >= 0; i--)
	{
		a[i] = i;
		if (i + 1 < n && s[i + 1] == s[i])
			a[i] = a[i + 1];
	}
	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		if (l == r)
		{
			cout << "Yes\n";
			continue;
		}
		if (a[l] >= r)
		{
			cout << "No\n";
			continue;
		}
		int kiek = 0;
		for (int i = 0; i < 26; i++)
		{
			if (cnt[i][r + 1] - cnt[i][l] > 0)
				kiek++;
		}
		if (kiek == 2 && s[l] == s[r])
		{
			cout << "No\n";
		}
		else
			cout << "Yes\n";
	}
}