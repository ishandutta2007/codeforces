/*input
5 5
1 1 4 2 2

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;
vector<ll>operator*(const vector<ll>&a, const vector<ll>&b)
{
	vector<ll>c(a.size() + b.size() - 1, 0);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			c[i + j] += a[i] * b[j];
			c[i + j] %= mod;
		}
	}
	return c;
}
vector<ll>power(vector<ll>a, ll p)
{
	if (p == 0)
		return {1};
	if (p == 1)
		return a;
	if (p % 2 == 1)
	{
		return a * power(a, p - 1);
	}
	else
	{
		a = power(a, p / 2);
		return a * a;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int h[n];
	for (int i = 0; i < n; i++)
		cin >> h[i];
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		if (h[i] == h[(i + 1) % n])
			b++;
		else
			a++;
	}
	vector<ll>fa = {1, (k - 2), 1};
	vector<ll>fb = {k};
	vector<ll>ans = power(fa, a) * power(fb, b);
	ll suma = 0;
	for (int i = a + 1; i < ans.size(); i++)
	{
		suma += ans[i];
		suma %= mod;
	}
	cout << suma << "\n";
}