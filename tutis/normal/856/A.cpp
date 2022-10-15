/***
3
3
1 10 100
1
1
2
2 4
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool negal[2000007];
bool negalima[2000007];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		for (int i = 0; i < 2000007; i++)
			negal[i] = false;
		for (int i = 0; i < 2000007; i++)
			negalima[i] = false;
		ll A[n];
		for (ll i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		set<ll>B;
		for (ll i = 1; i <= 1000000 && B.size() < n; i++)
		{
			if (negalima[i])
				continue;
			bool negerai = false;
			for (ll j = 0; j < n; j++)
			{
				if (negal[i + A[j]])
					negerai = true;
			}
			if (!negerai && B.size() < n)
			{
				B.insert(i);
				for (ll j = 0; j < n; j++)
				{
					negal[i + A[j]] = true;
					for (int k = 0; k < n; k++)
					{
						int c = i + A[j] - A[k];
						if (c >= 0)
						{
							negalima[c] = true;
						}
					}
				}
			}
		}
		if (B.size() < n)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
			for (ll i : B)
				cout << i << " ";
			cout << "\n";
		}
	}
}