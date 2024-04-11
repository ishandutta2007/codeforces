/*input
4 3 6
1 2
1 3
2 2
2 3
3 1
3 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	int ans = 0;
	vector<pair<int, int>>Q;
	map<int, vector<int>>R;
	map<int, vector<int>>C;
	DSU X(q + 1);
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		Q.push_back({x, y});
		R[x].push_back(i);
		C[y].push_back(i);
	}
	ans += n - R.size();
	ans += m - C.size();
	for (pair<int, vector<int>>i : R)
	{
		for (int a = 1; a < i.second.size(); a++)
		{
			X.merge(i.second[a - 1], i.second[a]);
		}
	}
	for (pair<int, vector<int>>i : C)
	{
		for (int a = 1; a < i.second.size(); a++)
		{
			X.merge(i.second[a - 1], i.second[a]);
		}
	}
	ans--;
	for (int i = 0; i < q; i++)
		if (X.root(i) == i)
			ans++;
	cout << ans << "\n";


}