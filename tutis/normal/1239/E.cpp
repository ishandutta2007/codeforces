/*input
2
1 4
2 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bitset<1200001>visi[925];
int id[50][50];
int timer = 0;
int main()
{
	for (int k = 0; k <= 48; k++)
	{
		for (int a = 0; a <= k && a <= 24; a++)
		{
			id[k][a] = timer;
			timer++;
		}
	}
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll a[2 * n];
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];
	sort(a, a + 2 * n);
	ll a0 = a[0];
	ll b0 = a[1];
	vector<ll>c;
	for (int i = 2; i < 2 * n; i++)
		c.push_back(a[i]);
	ll sum = 0;
	for (ll i : c)
		sum += i;
	ll mina = (sum + 1) / 2;
	for (int k = 0; k < c.size(); k++)
	{
		visi[id[k][0]][0] = 1;
		for (int a = 0; a <= k && a < n; a++)
		{
			if (a + 1 < n)
				visi[id[k + 1][a + 1]] = visi[id[k][a]] << c[k];
			visi[id[k + 1][a]] |= visi[id[k][a]];
		}
	}
	vector<ll>A, B;
	while (visi[id[c.size()][n - 1]][mina] == 0)
		mina++;
	int k = c.size();
	int a_ = n - 1;
	while (k > 0)
	{
		if (a_ > 0 && mina - c[k - 1] >= 0 && visi[id[k - 1][a_ - 1]][mina - c[k - 1]])
		{
			A.push_back(c[k - 1]);
			mina -= c[k - 1];
			k--;
			a_--;
		}
		else
		{
			B.push_back(c[k - 1]);
			k--;
		}
	}
	A.push_back(a0);
	B.push_back(b0);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<ll>());
	for (int i : A)
		cout << i << " ";
	cout << "\n";
	for (int i : B)
		cout << i << " ";
}