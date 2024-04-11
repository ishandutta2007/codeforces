#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
int n;
pair<int, int> a[500020];
ll z;
ll c[500020];
ll d[500020];
void R(ll c[], int x, int y)
{
	for (; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
ll G(ll c[], int x)
{
	ll re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re % mod;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		int p = a[i].second;
		R(c, p, p);
		R(d, n + 1 - p, n + 1 - p);
		z = (z + (G(c, p) * (n + 1 - p) + G(d, n - p) * p) % mod * a[i].first) % mod;
	}
	cout << z << endl;
	return 0;
}