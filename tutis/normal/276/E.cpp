/*input
6 11
1 2
2 5
5 4
1 6
1 3
0 3 1 3
0 3 4 5
0 2 1 4
0 1 5 5
0 4 6 2
1 1
1 2
1 3
1 4
1 5
1 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Fenwick
{
	vector<ll>A;
	int n;
	Fenwick(int n = 1): n(n)
	{
		A = vector<ll>(n + 1, 0);
	}
	inline int lsb(int x)
	{
		return ((x) & (-x));
	}
	void add(int i, ll w)
	{
		for (; i <= n; i += lsb(i))
		{
			A[i] += w;
		}
	}
	ll get(int i)
	{
		i = min(i, n);
		ll ret = 0;
		for (; i > 0; i -= lsb(i))
		{
			ret += A[i];
		}
		return ret;
	}
	ll get(int a, int b)
	{
		return get(b) - get(a - 1);
	}
};
int main()
{
	int n, q;
	cin >> n >> q;
	vector<int>adj[n + 1];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	Fenwick A(n + 5);
	Fenwick B[n + 1];
	vector<vector<int>>X;
	int k[n + 1];
	int D[n + 1];
	for (int i : adj[1])
	{
		int p = 1;
		X.push_back({});
		X.back().push_back(1);
		while (true)
		{
			X.back().push_back(i);
			bool ok = false;
			for (int j : adj[i])
			{
				if (j != p)
				{
					p = i;
					i = j;
					ok = true;
					break;
				}
			}
			if (ok == false)
				break;
		}
	}
	D[1] = 1;
	for (int i = 0; i < X.size(); i++)
	{
		int d = 0;
		for (int j : X[i])
		{
			d++;
			k[j] = i;
			D[j] = d;
		}
		B[i] = Fenwick(X[i].size() + 5);
	}

	while (q--)
	{
		int t;
		cin >> t;
		if (t == 0)
		{
			int v, x, d;
			cin >> v >> x >> d;
			if (v == 1)
			{
				A.add(1, x);
				A.add(d + 2, -x);
			}
			else
			{
				int d_ = d - D[v] + 2;
				if (d_ >= 1)
				{
					A.add(1, x);
					A.add(d_ + 1, -x);
					B[k[v]].add(d_ + 1, x);
					B[k[v]].add(D[v] + d + 1, -x);
				}
				else
				{
					B[k[v]].add(D[v] - d, x);
					B[k[v]].add(D[v] + d + 1, -x);
				}
			}
		}
		else
		{
			int v;
			cin >> v;
			if (v != 1)
				cout << A.get(D[v]) + B[k[v]].get(D[v]) << "\n";
			else
				cout << A.get(D[v]) << "\n";
		}
	}

}