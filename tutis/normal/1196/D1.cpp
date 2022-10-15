/*input
3
5 2
BGGGG
5 3
RBRGR
5 5
BBBRR
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int M[256];
int main()
{
	M['R'] = 0;
	M['G'] = 1;
	M['B'] = 2;
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int ans = k;
		for (int t = 0; t < 3; t++)
		{
			int kiek = 0;
			for (int i = 0; i < (int)s.size(); i++)
			{	//i++, (i-k)--
				if (M[s[i]] != ((i + t) % 3))
					kiek++;
				if (i - k >= 0 && M[s[i - k]] != ((i - k + t) % 3))
					kiek--;
				if (i >= k - 1)
					ans = min(ans, kiek);
			}
		}
		cout << ans << "\n";
	}
}