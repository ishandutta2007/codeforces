/*input
12 2 4
100000000000
100000000000
100000000000
100000000000 0
100000000000 100
100000000000 0
100000000000 100
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int kiek[1 << 12];
int ans[1 << 12][101];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	int W[n];
	for (int i = 0; i < n; i++)
		cin >> W[i];
	while (m--)
	{
		string s;
		cin >> s;
		int w = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				w += (1 << i);
		kiek[w]++;
	}
	for (int w = 0; w < (1 << n); w++)
	{
		for (int w1 = 0; w1 < (1 << n); w1++)
		{
			int suma = 0;
			for (int i = 0; i < n; i++)
				if ((w & (1 << i)) == (w1 & (1 << i)))
					suma += W[i];
			if (suma <= 100)
				ans[w1][suma] += kiek[w];
		}
	}
	for (int w1 = 0; w1 < (1 << n); w1++)
		for (int k = 1; k <= 100; k++)
			ans[w1][k] += ans[w1][k - 1];
	while (q--)
	{
		string s;
		int k;
		cin >> s >> k;
		int w = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				w += (1 << i);
		cout << ans[w][k] << "\n";
	}
}