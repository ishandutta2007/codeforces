/*input
9 6
1 1 1 3 5 3 5 7
3 1
1 5
3 4
7 3
1 8
1 9
*/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct node
{
	int w, v;
	int sz;
	node *l = nullptr, *r = nullptr;
	inline node(int val): v(val), w(rand()), sz(1)
	{

	}
};
using pnode = node*;
inline int size(pnode &x)
{
	if (x)
		return x->sz;
	return 0;
}
inline pnode merge(pnode a, pnode b)
{
	if (a == nullptr)
		return b;
	if (b == nullptr)
		return a;
	if (a->w < b->w)
	{
		a->sz += b->sz;
		a->r = merge(a->r, b);
		return a;
	}
	b->sz += a->sz;
	b->l = merge(a, b->l);
	return b;
}
inline int kth(pnode &X, int k)
{
	int szl = size(X->l);
	if (szl == k - 1)
		return X->v;
	if (szl >= k)
		return kth(X->l, k);
	return kth(X->r, k - szl - 1);
}
int answer[200005];
vector<int>adj[200005];
vector<pair<int, int>>quer[200005];
inline pnode dfs(int i)
{
	pnode X = new node(i);
	stable_sort(adj[i].begin(), adj[i].end());
	for (int &j : adj[i])
		X = merge(X, dfs(j));
	for (pair<int, int>&x : quer[i])
	{
		if (size(X) >= x.first)
		{
			answer[x.second] = kth(X, x.first);
		}
	}
	return X;
}
int main()
{
	srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; i++)
	{
		int p;
		cin >> p;
		adj[p].emplace_back(i);
	}
	for (int i = 0; i < q; i++)
	{
		int u, k;
		cin >> u >> k;
		quer[u].emplace_back(k, i);
		answer[i] = -1;
	}
	dfs(1);
	for (int i = 0; i < q; i++)
		cout << answer[i] << "\n";
}