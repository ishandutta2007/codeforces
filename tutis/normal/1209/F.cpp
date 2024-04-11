/*input
11 10
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000000007;
ll power(ll x)
{
	if (x <= 0)
		return 1;
	if (x % 2 == 1)
		return (10 * power(x - 1)) % modulo;
	x = power(x / 2);
	return (x * x) % modulo;
}
struct node
{
	node *a[10];
	node *pa[20];
	ll id = 0;
	ll d = 0;
	ll sk = 0;
	node()
	{
	}
	node(node *p, ll sk): sk(sk)
	{
		id = (p->id * 10 + sk) % modulo;
		pa[0] = p;
		fix();
		d = p->d + 1;
	}
	void fix()
	{
		for (ll i = 1; i < 20; i++)
			pa[i] = pa[i - 1]->pa[i - 1];
	}
};
bool operator<(node a, node b)
{
	if (a.d != b.d)
	{
		return a.d > b.d;
	}
	if (a.id == b.id)
		return false;
	node *x = &a;
	node *y = &b;
	for (ll t = 19; t >= 0; t--)
	{
		if (x->pa[t]->id != y->pa[t]->id)
		{
			x = x->pa[t];
			y = y->pa[t];
		}
	}
	return x->sk > y->sk;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>>adj[n + 1];
	for (ll i = 1; i <= m; i++)
	{
		ll x, y;
		cin >> x >> y;
		adj[x].push_back({y, i});
		adj[y].push_back({x, i});
	}
	node*NULIS = new node();
	NULIS->pa[0] = NULIS;
	NULIS->fix();
	node *INF = new node();
	INF->d = 1e9;
	node* D[n + 1];
	fill_n(D, n + 1, INF);
	D[1] = NULIS;
	priority_queue<pair<node, ll>>Q;
	Q.push({*D[1], 1});
	vector<bool>buvau(n + 1, false);
	while (!Q.empty())
	{
		ll a = Q.top().second;
		Q.pop();
		if (buvau[a])
			continue;
		buvau[a] = true;
		for (auto bb : adj[a])
		{
			ll x = bb.second;
			ll b = bb.first;
			node *dabar = D[a];
			deque<ll>d;
			ll l = 1;
			while (x > 0)
			{
				d.push_front(x % 10);
				x /= 10;
				l *= 10;
			}
			for (ll c : d)
			{
				dabar = new node(dabar, c);
			}
			if (*D[b] < *dabar)
			{
				D[b] = dabar;
				Q.push({*D[b], b});
			}
		}
	}
	for (ll i = 2; i <= n; i++)
		cout << D[i]->id << "\n";
}