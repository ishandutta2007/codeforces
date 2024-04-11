/***
5
3 2 1 6 5
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct node
{
	ll a[800100], b[800100], orSum[800100];
	init(ll l, ll r, ll aa[], ll i)
	{
		a[i] = l;
		b[i] = r;
		if (l == r)
		{
			orSum[i] = aa[l];
		}
		if (l < r)
		{
			init(l, (l + r) / 2, aa, 2 * i + 1);
			init((l + r) / 2 + 1, r, aa, 2 * i + 2);
			orSum[i] = ((orSum[2 * i + 1]) | (orSum[2 * i + 2]));
		}
	}
	ll get(ll l, ll r, ll i)
	{
		if (l <= a[i] && b[i] <= r)
			return orSum[i];
		if (r < a[i] || b[i] < l)
			return 0;
		return get(l, r, 2 * i + 1) | get(l, r, 2 * i + 2);
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll a[n + 2];
	bool tinka = true;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i != 1)
		{
			if (a[i] != a[i - 1])
				tinka = false;
		}
	}
	if (tinka)
	{
		cout << 0;
		return 0;
	}
	int P[20];
	P[0] = 1;
	for (int i = 1; i < 20; i++)
		P[i] = P[i - 1] * 2;
	int M[n + 2][20]; // [i, i+P[j])
	for (int i = n + 2; i >= 0; i--)
	{
		M[i][0] = a[i];
		for (int j = 1; j < 20; j++)
		{
			if (i + P[j - 1] < n + 2)
				M[i][j] = max(M[i][j - 1], M[i + P[j - 1]][j - 1]);
		}
	}
	int LOG2[n + 1];
	for (int i = 0; i <= n; i++)
		LOG2[i] = log2(i);

	a[0] = 1000000009;
	a[n + 1] = 1000000009;
	node ORtree;
	ORtree.init(0, n + 1, a, 0);
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
	{
		ll PG = 0;
		ll NG = n + 1;
		{
			ll lo = i + 1;
			ll hi = n + 1;
			while (lo < hi)
			{
				ll k = (lo + hi) / 2;
				int aaa = 0;
				{
					int l = i + 1;
					int r = k;
					int dyd = LOG2[r - l];
					if (l == r)
						aaa = a[l];
					else
						aaa = max(M[l][dyd], M[r - P[dyd] + 1][dyd]);
				}
				if (aaa <= a[i])
					lo = k + 1;
				else
					hi = k;
			}
			NG = (lo + hi) / 2;
		}
		{
			ll lo = 0;
			ll hi = i - 1;
			while (lo < hi)
			{
				ll k = (lo + hi + 1) / 2;
				ll aaa;
				{
					int l = k;
					int r = i - 1;
					int dyd = LOG2[r - l];
					if (l == r)
						aaa = a[l];
					else
						aaa = max(M[l][dyd], M[r - P[dyd] + 1][dyd]);
				}
				if (aaa < a[i])
					hi = k - 1;
				else
					lo = k;
			}
			PG = (lo + hi) / 2;
		}
		ll left = PG;
		ll right = NG;
		{
			ll lo = PG + 1;
			ll hi = i - 1;
			while (lo < hi)
			{
				ll k = (lo + hi + 1) / 2;
				if (ORtree.get(k, i, 0) > a[i])
				{
					lo = k;
				}
				else
					hi = k - 1;
			}
			if (ORtree.get((lo + hi) / 2, i, 0) > a[i])
			{
				left = (lo + hi) / 2;
			}
		}
		{
			ll lo = i + 1;
			ll hi = NG - 1;
			while (lo < hi)
			{
				ll k = (lo + hi) / 2;
				if (ORtree.get(i, k, 0) > a[i])
				{
					hi = k;
				}
				else
					lo = k + 1;
			}
			if (ORtree.get(i, (lo + hi) / 2, 0) > a[i])
			{
				right = (lo + hi) / 2;
			}
		}
		ans += (left - PG) * (NG - i);
		ans += (NG - right) * (i - PG);
		ans -= (left - PG) * (NG - right);
	}
	cout << ans;
}