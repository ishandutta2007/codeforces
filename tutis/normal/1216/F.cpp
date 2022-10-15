/*input
12 6
000010000100

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	string s;
	cin >> n >> k >> s;
	s = "0" + s;
	ll dp[n + 1];
	fill_n(dp, n + 1, (ll)1e14);
	dp[0] = 0;
	vector<int>r;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1')
			r.push_back(i);
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + i;
		while (t < (int)r.size() && r[t] < i - k)
			t++;
		if (t < (int)r.size())
		{
			int j = r[t];
			if (j <= i + k)
				dp[i] = min(dp[i], dp[max(0, j - k - 1)] + j);
		}
	}
	cout << dp[n] << "\n";
}