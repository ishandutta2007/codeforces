/*input
5
13 11
11 1
3 5
17 1
9 27

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
const ll maxinv = 30;
namespace {
template<typename A, typename B>
istream &operator>>( istream  &input, pair<A, B> &X ) {
	input >> X.first >> X.second;
	return input;
}
template<typename A, typename B>
ostream &operator<<( ostream &output, const pair<A, B> &X ) {
	output << X.first << " " << X.second;
	return output;
}
template<typename T>
istream &operator>>( istream  &input, vector<T> &X ) {
	for (T&i : X)
		input >> i;
	return input;
}
template<typename T>
ostream &operator<<( ostream &output, const vector<T> &X ) {
	for (ll t = 0; t < (ll)X.size(); t++)
	{
		if (t + 1 != (ll)X.size())
			cout << X[t] << " ";
		else
			cout << X[t];
	}
	return output;
}
ll power(ll x, ll y)
{
	x %= mod;
	if (x < 0)
		x += mod;
	y %= (mod - 1);
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
ll I___[maxinv];
bool calc___ = false;
ll inv(ll x)
{
	if (x >= 0 && x < maxinv)
	{
		if (!calc___)
		{
			calc___ = true;
			I___[1] = 1;
			I___[0] = 0;
			for (ll i = 2; i < maxinv; ++i)
				I___[i] = (mod - (mod / i) * I___[mod % i] % mod) % mod;
		}
		return I___[x];
	}
	return power(x, mod - 2);
}
}
struct Edge;
typedef list<Edge>::iterator iter;

struct Edge
{
	int next_vertex;
	iter reverse_edge;

	Edge(int next_vertex)
		: next_vertex(next_vertex)
	{ }
};

const int max_vertices = 1 << 20;
list<Edge> adj[max_vertices];		// adjacency list

vector<int> path;

void find_path(int v)
{
	while (adj[v].size() > 0)
	{
		int vn = adj[v].front().next_vertex;
		adj[vn].erase(adj[v].front().reverse_edge);
		adj[v].pop_front();
		find_path(vn);
	}
	path.push_back(v);
}

void add_edge(int a, int b)
{
	adj[a].push_front(Edge(b));
	iter ita = adj[a].begin();
	adj[b].push_front(Edge(a));
	iter itb = adj[b].begin();
	ita->reverse_edge = itb;
	itb->reverse_edge = ita;
}

// ************ End of Undirected Euler Path *************
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[2 * n];
	for (int i = 0; i < n; i++)
		cin >> a[2 * i] >> a[2 * i + 1];
	for (int p = 20; p >= 1; p--)
	{
		for (int i = 0; i < 2 * n; i++)
			a[i] %= 1 << p;
		vector<vector<int>>X(1 << p);
		for (int i = 0; i < 2 * n; i++)
			X[a[i]].push_back(i);
		bool ok = true;
		for (int i = 0; i < (1 << p); i++)
			if (X[i].size() % 2 == 1)
				ok = false;
		if (ok)
		{
			int v = 0;
			for (int i = 0; i < n; i++)
			{
				int x = a[2 * i];
				int y = a[2 * i + 1];
				add_edge(x, y);
				v = x;
			}
			find_path(v);
			if (path.size() == n + 1)
			{
				map<pair<int, int>, vector<int>>M;
				for (int i = 0; i < n; i++)
				{
					int x = a[2 * i];
					int y = a[2 * i + 1];
					if (x > y)
						swap(x, y);
					M[ {x, y}].push_back(i);
				}
				cout << p << "\n";
				for (int i = 1; i <= n; i++)
				{
					int x = path[i - 1];
					int y = path[i];
					int xx = x;
					int yy = y;
					if (xx > yy)
						swap(xx, yy);
					int c = M[ {xx, yy}].back();
					M[ {xx, yy}].pop_back();
					if (a[2 * c] == x)
						cout << 2 * c + 1 << " " << 2 * c + 2 << " ";
					else
						cout << 2 * c + 2 << " " << 2 * c + 1 << " ";
				}
				return 0;
			}
			else
				path.clear();
		}
		for (int i = 0; i < (1 << p); i++)
			adj[i].clear();
	}
	cout << "0\n";
	for (int i = 1; i <= n * 2; i++)
		cout << i << " ";
	cout << "\n";
	return 0;
}