/***
3
1 1
1 2
1 111111111111
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a = "What are you doing at the end of the world? Are you busy? Will you save us?";
string b = "What are you doing while sending \"";
string c = "\"? Are you busy? Will you send \"";
string d = "\"?";
ll ilgis[110000];
char ans(ll n, ll k)
{
	if (k > ilgis[n])
		return '.';
	if (k <= 0)
	{
		return '-';
	}
	if (n == 0)
	{
		return a[k - 1];
	}
	if (k <= b.size())
		return b[k - 1];
	k -= b.size();
	if (k <= (ilgis[n - 1]))
		return ans(n - 1, k);
	k -= ilgis[n - 1];
	if (k <= (c.size()))
		return c[k - 1];
	k -= c.size();
	if (k <= (ilgis[n - 1]))
		return ans(n - 1, k);
	k -= ilgis[n - 1];
	return d[k - 1];
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll q;
	cin >> q;
	ilgis[0] = a.size();
	for (ll i = 1; i < 110000; i++)
	{
		ilgis[i] = min(1100000000000000000ll, ll(ilgis[i - 1] * 2 + b.size() + c.size() + d.size()));
	}
	while (q--)
	{
		ll n, k;
		cin >> n >> k;
		cout << ans(n, k);
	}
}