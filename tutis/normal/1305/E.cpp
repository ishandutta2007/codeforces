/*input
5 3

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,aes,avx,avx2")
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename A, typename B>
using Map = tree<A, B, less<A>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1000000000 + 7;
void blogai()
{
	cout << "-1\n";
	exit(0);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	int kiek = 0;
	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			k = max(k, j + 1);
			while (k < n && a[k] < a[i] + a[j])
				k++;
			if (k < n && a[k] == a[i] + a[j])
				kiek++;
		}
	}
	if (m > kiek)
		blogai();
	int lo = 1;
	int hi = n + 10;
	if (m == kiek)
		goto XXX;
	int x;
	while (lo < hi)
	{
		int x = (lo + hi + 1) / 2;
		for (int i = 0; i < n; i++)
			a[i] = x + i;
		kiek = 0;
		for (int i = 0; i + 2 < n; i++)
		{
			int s1 = a[i] + a[i + 1];
			int s2 = a[n - 1];
			kiek += max(s2 - s1 + 1, 0);
		}
		if (kiek < m)
			hi = x - 1;
		else
			lo = x;
	}
	x = (lo + hi) / 2;
	for (int i = 0; i < n; i++)
		a[i] = x + i;
	kiek = 0;
	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			k = max(k, j + 1);
			while (k < n && a[k] < a[i] + a[j])
				k++;
			if (k < n && a[k] == a[i] + a[j])
				kiek++;
		}
	}
	lo = 0;
	hi = n - 1;
	while (lo <= hi)
	{
		int y = (lo + hi) / 2;
		for (int i = 0; i < n; i++)
		{
			a[i] = x + i;
			if (i >= y)
				a[i]++;
		}
		kiek = 0;
		for (int i = 0; i < n; i++)
		{
			int k = i;
			for (int j = i + 1; j < n; j++)
			{
				k = max(k, j + 1);
				while (k < n && a[k] < a[i] + a[j])
					k++;
				if (k < n && a[k] == a[i] + a[j])
					kiek++;
			}
		}
		if (kiek == m)
			goto XXX;
		if (kiek > m)
			hi = y - 1;
		else
			lo = y + 1;
	}
	blogai();
	cout << kiek << " / " << m << endl;
XXX:;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
}