/***
4
1 1 1
1 0 0 1
9
get 1
get 2
get 3
get 4
pow 1
get 1
get 2
get 3
get 4
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll>adj[200009];
ll beg[200009];
ll endd[200009];
ll calc(ll i, ll val)
{
	beg[i] = val;
	endd[i] = val;
	for (ll j : adj[i])
	{
		endd[i] = calc(j, endd[i] + 1);
	}
	return endd[i];
}
struct node
{
	ll a, b;
	ll S = 0;
	bool lazy = false;
	node *left = NULL;
	node *right = NULL;
	void fix()
	{
		if (lazy)
		{
			S = b - a + 1 - S;
			if (left)
				left->lazy ^= lazy;
			if (right)
				right->lazy ^= lazy;
			lazy = false;
		}
	}
	node(ll a, ll b): a(a), b(b)
	{
		if (a < b)
		{
			left = new node(a, (a + b) / 2);
			right = new node((a + b) / 2 + 1, b);
		}
	}
	void change(ll i)
	{
		if (a == b)
		{
			if (a == i)
				S = 1;
			return;
		}
		if (a <= i && i <= b)
		{
			left->change(i);
			right->change(i);
			S = left->S + right->S;
		}
	}
	void change(ll l, ll r)
	{
		fix();
		if (l <= a && b <= r)
		{
			lazy ^= true;
			fix();
			return;
		}
		if (r < a || b < l)
			return;
		left->change(l, r);
		right->change(l, r);
		S = left->S + right->S;
	}
	ll get(ll l, ll r)
	{
		fix();
		if (l <= a && b <= r)
			return S;
		if (r < a || b < l)
			return 0;
		return left->get(l, r) + right->get(l, r);
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll p[n + 1];
	p[1] = 1;
	for (ll i = 2; i <= n; i++)
	{
		cin >> p[i];
		adj[p[i]].push_back(i);
	}
	calc(1, 0);
	ll t[n + 1];
	node XX(0, 2 * n + 9);
	for (ll i = 1; i <= n; i++)
	{
		cin >> t[i];
		if (t[i])
		{
			XX.change(beg[i]);
		}
	}
	ll q;
	cin >> q;
	while (q--)
	{
		string x;
		cin >> x;
		ll v;
		cin >> v;
		if (x == "get")
		{
			cout << XX.get(beg[v], endd[v]) << "\n";
		}
		if (x == "pow")
		{
			XX.change(beg[v], endd[v]);
		}
	}
}