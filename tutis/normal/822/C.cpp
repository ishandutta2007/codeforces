/**
4 5
1 3 4
1 2 5
4 5 1
1 2 4
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct kelion
{
	ll KKaire = 1000000007;
	ll KDesine = 1000000007;
	ll c;
	int i;
	kelion() {}
	kelion(ll c, int i): c(c), i(i) {}
};
vector<kelion>X[200005];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		ll l, r, c;
		cin >> l >> r >> c;
		X[r - l + 1].push_back(kelion(c, l));
	}
	for (int l = 0; l < 200005; l++)
	{
		sort(X[l].begin(), X[l].end(), [](kelion a, kelion b) {
			if (a.i != b.i)
				return a.i < b.i;
			return a.c < b.c;
		});
		ll kainK = 1000000007;
		for (int i = 0; i < X[l].size(); i++)
		{
			kainK = min(kainK, X[l][i].c);
			X[l][i].KKaire = kainK;
		}
		sort(X[l].begin(), X[l].end(), [](kelion a, kelion b) {
			if (a.i != b.i)
				return a.i < b.i;
			return a.c > b.c;
		});
		ll kainD = 1000000007;
		for (int i = X[l].size() - 1; i >= 0; i--)
		{
			kainD = min(kainD, X[l][i].c);
			X[l][i].KDesine = kainD;
		}
	}
	ll ans = 3000000007;
	for (int l = 0; l < 200005; l++)
	{
		if (x - l < 0)
			break;
		for (kelion a : X[l])
		{
			int dau = a.i + l;
			int lo = 0;
			int hi = X[x - l].size() - 1;
			if (hi < 0)
				break;
			while (lo < hi)
			{
				int k = (lo + hi) / 2;
				if (X[x - l][k].i < dau)
				{
					lo = k + 1;
				}
				if (X[x - l][k].i >= dau)
				{
					hi = k;
				}
			}
			int k = (lo + hi) / 2;
			if (X[x - l][k].i >= dau)
			{
				ans = min(ans, a.c + X[x - l][k].KDesine);
			}
			int maz = a.i - 1;
			lo = 0;
			hi = X[x - l].size() - 1;
			while (lo < hi)
			{
				int k = (lo + hi + 1) / 2;
				if (X[x - l][k].i <= maz)
				{
					lo = k;
				}
				else if (X[x - l][k].i > maz)
				{
					hi = k - 1;
				}
			}
			k = (lo + hi + 1) / 2;
			if (X[x - l][k].i + x - l - 1 <= maz)
			{
				ans = min(ans, a.c + X[x - l][k].KKaire);
			}
		}
	}
	if (ans != 3000000007)
		cout << ans;
	else
		cout << -1;
}