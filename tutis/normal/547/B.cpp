/*input
10
1 2 3 4 5 4 3 2 1 6
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
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans[n + 1];
	fill_n(ans, n + 1, -1);
	ans[1] = *max_element(a, a + n);
	vector<int>b(n);
	iota(b.begin(), b.end(), 0);
	sort(b.begin(), b.end(), [&](int x, int y) {return a[x] > a[y];});
	DSU X(n);
	for (int i : b)
	{
		for (int t : { -1, 1})
			if (i + t >= 0 && i + t < n && a[i + t] >= a[i])
				X.merge(i, i + t);
		ans[X.size(i)] = max(ans[X.size(i)], a[i]);
	}
	for (int i = n - 1; i >= 0; i--)
		ans[i] = max(ans[i], ans[i + 1]);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
}