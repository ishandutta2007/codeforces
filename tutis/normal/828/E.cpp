/***
ATGCATGC
4
2 1 8 ATGC
2 2 6 TTT
1 4 T
2 2 6 TA
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct BIT
{
	vector<ll>seg;
	void init()
	{
		for (ll i = 0; i <= 100007; i++)
			seg.push_back(0);
	}
	void add(ll i, ll k)
	{
		for (; i <= 100001; i += (i) & (-i))
			seg[i] += k;
	}
	ll get(ll i)
	{
		ll s = 0;
		for (; i > 0; i -= (i) & (-i))
			s += seg[i];
		return s;
	}
	ll get(ll l, ll r)
	{
		return get(r) - get(l);
	}
};
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	string s;
	ll q;
	cin >> s >> q;
	map<char, ll>A;
	A['A'] = 0;
	A['T'] = 1;
	A['G'] = 2;
	A['C'] = 3;
	BIT X[11][10][4];
	for (ll i = 1; i <= 10; i++)
		for (ll j = 0; j < i; j++)
			for (ll k = 0; k < 4; k++)
				X[i][j][k].init();
	for (ll i = 0; i < s.size(); i++)
	{
		for (ll a = 1; a <= 10; a++)
		{
			ll b = i % a;
			X[a][b][A[s[i]]].add(i + 1, 1);
		}
	}
	while (q--)
	{
		ll x;
		cin >> x;
		if (x == 1)
		{
			ll i;
			char c;
			cin >> i >> c;
			i--;
			ll aa = A[s[i]];
			ll B = A[c];
			for (ll a = 1; a <= 10; a++)
			{
				ll b = (i) % a;
				X[a][b][aa].add(i + 1, -1);
			}
			for (ll a = 1; a <= 10; a++)
			{
				ll b = (i) % a;
				X[a][b][B].add(i + 1, 1);
			}
			s[i] = c;
		}
		if (x == 2)
		{
			ll l, r;
			string e;
			cin >> l >> r >> e;
			ll a = e.length();
			ll ans = 0;
			l--;
			r--;
			for (int i = 0; i < a; i++)
			{
				int b = (l + i + a) % a;
				ans += X[a][b][A[e[i]]].get(l, r + 1);
			}
			cout << ans << "\n";
		}
	}
}