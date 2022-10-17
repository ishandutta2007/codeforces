#include <bits/stdc++.h>
using namespace std;
int t, n, k;
long long s[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &s[i]);
			s[i] += s[i - 1];
		}
		int l = k - 1, r = k;
		long long ls = s[l], rs = s[r];
		while (0 < l && r < n)
		{
			if (s[l - 1] <= rs)
			{
				ls = min(ls, s[--l]);
			}
			else if (ls <= s[r + 1])
			{
				rs = max(rs, s[++r]);
			}
			else
			{
				break;
			}
		}
		puts(0 < l && r < n ? "NO" : "YES");
	}
	return 0;
}