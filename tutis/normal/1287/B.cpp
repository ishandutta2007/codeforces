/*input
5 4
SETT
TEST
EEET
ESTE
STES

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll v[1501][2];
bool S[(int)1e7];
ll V[(int)1e7];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int per[k];
	iota(per, per + k, 0);
	shuffle(per, per + k, rng);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < k; j++)
		{
			if (s[j] == 'E')
				v[i][0] += 1 << per[j];
			if (s[j] == 'T')
				v[i][1] += 1 << per[j];
		}
	}
	const int p = 9392431;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ll s = ((~v[i][0]) & (~v[i][1]) & (v[j][1]) |
			        (~v[j][0]) & (~v[j][1]) & (v[i][1]) |
			        v[i][0] & v[j][0])
			       | ((
			              v[i][1] & v[j][1] |
			              (~v[i][0]) & (~v[i][1])&v[j][0] |
			              (~v[j][0]) & (~v[j][1])&v[i][0]
			          ) << 32);
			int a = s % p;
			if (S[a] && V[a] == s)
				ans++;
		}
		ll s = v[i][0] | (v[i][1] << 32);
		S[s % p] = true;
		V[s % p] = s;
	}
	cout << ans << "\n";
}