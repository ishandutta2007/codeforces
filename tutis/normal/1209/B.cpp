/*input
6
011100
5 3
5 5
2 4
3 5
4 2
1 5

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[n], b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	int ans = count(s.begin(), s.end(), '1');
	for (int t = 1; t < 1000; t++)
	{
		for (int i = 0; i < n; i++)
		{
			if (t >= b[i])
			{
				if ((t - b[i]) % a[i] == 0)
				{
					s[i] ^= '0';
					s[i] ^= '1';
				}
			}
		}
		ans = max(ans, count(s.begin(), s.end(), '1'));
	}
	cout << ans << "\n";
}