/*input
3 5 2
aaa
baaab
1 3
1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	string s, t;
	cin >> s >> t;
	int dp[n + 1];
	fill_n(dp, n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		bool same = true;
		if (i + m - 1 >= n)
			same = false;
		else
		{
			for (int j = 0; j < m; j++)
			{
				same &= (t[j] == s[i + j]);
			}
		}
		dp[i + 1] = same;
		dp[i + 1] += dp[i];
	}
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		r -= m - 1;
		if (l > r)
		{
			cout << "0\n";
		}
		else
		{
			cout << dp[r] - dp[l - 1] << "\n";
		}
	}
}