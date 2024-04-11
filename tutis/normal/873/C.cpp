/***
3 2 1
1 0
0 1
0 0
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m, k;
	cin >> n >> m >> k;
	ll A[n + 1][m + 1];
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= m; j++)
			cin >> A[i][j];
	ll score = 0;
	ll moves = 0;
	for (ll q = 1; q <= m; q++)
	{
		ll s[n + 1];
		for (ll i = 1; i <= n; i++)
			s[i] = A[i][q];
		int sco = 0;
		int mov = n;
		ll mv = 0;
		bool kitas = true;
		for (ll i = 1; i <= n; i++)
		{
			if (s[i] == 1)
			{
				kitas = false;
				int sc = 0;
				for (int j = i; j <= n && j - i < k; j++)
				{
					sc += s[j];
				}
				if (sc > sco)
				{
					sco = sc;
					mov = mv;
				}
				mv++;
			}
		}
		if (!kitas)
		{
			score += sco;
			moves += mov;
		}
	}
	cout << score << " " << moves;
}