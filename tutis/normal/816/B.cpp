/**
3 2 4
91 94
92 97
97 99
92 94
93 97
95 96
90 100
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef double d;
typedef long l;
ll D[200007];
ll A[200007];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, k, q;
	cin >> n >> k >> q;
	fill_n(D, 200007, 0);
	fill_n(A, 200007, 0);
	for (ll i = 0; i < n; i++)
	{
		ll l, r;
		cin >> l >> r;
		D[l]++;
		D[r + 1]--;
	}
	for (ll i = 1; i < 200007; i++)
		D[i] = D[i - 1] + D[i];
	if (D[0] >= k)
		A[0] = 1;
	for (ll i = 1; i < 200007; i++)
		if (D[i] >= k)
			A[i] = A[i - 1] + 1;
		else
			A[i] = A[i - 1];
	for (ll i = 0; i < q; i++)
	{
		ll a, b;
		cin >> a >> b;
		cout << A[b] - A[a - 1] << "\n";
	}
}