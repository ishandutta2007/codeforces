/*input
4 3
1 2 4

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int M[603030];
void add(int i, int w)
{
	while (i < 603030)
	{
		M[i] += w;
		i += (i & (-i));
	}
}
int get(int i)
{
	int s = 0;
	while (i > 0)
	{
		s += M[i];
		i -= (i & (-i));
	}
	return s;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	list<int>A;
	list<int>::iterator itas[n + 1];
	int timer = 1;
	int kur[n + 1];
	for (int i = 1; i <= n; i++)
	{
		A.push_back(i);
		itas[i] = --A.end();
	}
	for (int i = n; i >= 1; i--)
	{
		kur[i] = timer++;
		add(kur[i], 1);
	}
	int lo[n + 1], hi[n + 1];
	iota(lo, lo + n + 1, 0);
	iota(hi, hi + n + 1, 0);
	int a[m];
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		hi[a[i]] = max(hi[a[i]], n - get(kur[a[i]]) + 1);
		add(kur[a[i]], -1);
		A.erase(itas[a[i]]);
		A.push_front(a[i]);
		itas[a[i]] = A.begin();
		lo[a[i]] = 1;
		kur[a[i]] = timer++;
		add(kur[a[i]], 1);
	}
	int t = 0;
	for (int i : A)
	{
		t++;
		hi[i] = max(hi[i], t);
	}
	for (int i = 1; i <= n; i++)
		cout << lo[i] << " " << hi[i] << "\n";
}