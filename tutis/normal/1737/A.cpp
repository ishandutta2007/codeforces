/*input
5
12 3
cabccadabaac
12 6
cabccadabaac
12 12
cabccadabaac
25 1
abcdefghijklmnopqrstuvwxy
10 5
bcdxedbcfg
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> cnt(26, 0);
		for (char c : s)
			cnt[c - 'a']++;
		string ans(k, 'a');
		for (int c = 0; c < 26; c++)
		{
			for (int i = 0; i < k; i++)
			{
				if (ans[i] == ('a' + c) && cnt[c] >= 1)
				{
					int p = ans[i] - 'a';
					if (p + 1 <= n / k) {
						ans[i]++;
						cnt[c]--;
					}
				}
			}
		}
		cout << ans << "\n";
	}

}