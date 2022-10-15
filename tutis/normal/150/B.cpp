/*input
5 2 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modulo = 1000000007;
struct DSU
{
	vector<int>pa;
	DSU(int n = 1)
	{
		pa = vector<int>(n + 3, -1);
	}
	int root(int i)
	{
		if (pa[i] < 0)
			return i;
		return pa[i] = root(pa[i]);
	}
	int size(int i)
	{
		return -pa[root(i)];
	}
	int merge(int a, int b)
	{
		a = root(a);
		b = root(b);
		if (a == b)
			return a;
		if (pa[a] < pa[b])
			swap(a, b);
		pa[b] += pa[a];
		pa[a] = b;
		return b;
	}
};
int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
	DSU X(n);
	for (int i = 0; i + k - 1 < n; i++)
	{
		for (int a = 0; a < k; a++)
		{
			X.merge(i + a, i + k - 1 - a);
		}
	}
	ll ans = 1;
	for (int i = 0; i < n; i++)
		if (X.root(i) == i)
			ans = (ans * m) % modulo;
	cout << ans << "\n";
}