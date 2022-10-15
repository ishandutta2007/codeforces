/*input
6 60
0 0
1 20
3 21
5 0
19 30
23 40

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int n, s;
	cin >> n >> s;
	int h[n], m[n];
	for (int i = 0; i < n; i++)
		cin >> h[i] >> m[i];
	for (int hh = 0;; hh++)
	{
		for (int mm = 0; mm < 60; mm++)
		{
			int tim = hh * 60 + mm;
			bool ok = true;
			for (int i = 0; i < n; i++)
				ok &= abs(h[i] * 60 + m[i] - tim) > s;
			if (ok)
			{
				cout << hh << " " << mm << "\n";
				return 0;
			}
		}
	}
}