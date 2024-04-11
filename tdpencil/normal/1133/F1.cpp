#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define sum accumulate
#define vt vector

using ll = long long;
#define vl vt<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpl map<ll, ll>
#define vi vt<int>
#define vpl vt<pll>
#define vpi vt<pii>
#define pb push_back
#define eb emplace_back
    template <class t>
void read(t &a)
{
	cin >> a;
}
    template <class t>
void read(vt<t> &a)
{
	for (auto &b : a)
		cin >> b;
}
    template <class t>
void read(vt<pair<t, t>> &a)
{
	for (auto &b : a)
		cin >> b.first >> b.second;
}
    template <class t>
void read(vt<array<t, 2>> &a)
{
	for (auto &b : a)
		cin >> b[0] >> b[1];
}
    template <class t>
void read(vt<array<t, 3>> &a)
{
	for (auto &b : a)
		cin >> b[0] >> b[1] >> b[2];
}
    template <class t>
void read(vt<array<t, 4>> &a)
{
	for (auto &b : a)
		cin >> b[0] >> b[1] >> b[2] >> b[3];
}
    template <class t>
void read(vt<vt<t>> &a)
{
	for (auto &b : a)
	{
		for (auto &c : b)
			cin >> c;
	}
}

    template <class t>
void print(t &a)
{
	cout << a << "\n";
}
    template <class T>
void print(vt<T> &a)
{
	for (auto &e : a)
		cout << e << " ";
	cout << "\n";
}
    template <class T, class V>
void print(vt<pair<T, V>> &a)
{
	for (auto &e : a)
		cout << e.first << " " << e.second << "\n";
}
    template <class T, int SZ_>
void print(vt<array<T, SZ_>> &a)
{
	for (auto &e : a)
	{
		for (auto &b : e)
			cout << b << " ";
		cout << "\n";
	}
}
    template <class T>
void print(set<T> &a)
{
	for (auto &e : a)
		cout << e << " ";
	cout << "\n";
}
    template <class T>
void print(queue<T> &p)
{
	while (p.size())
	{
		cout << p.front() << " ";
		p.pop();
	}
	cout << "\n";
}
    template <class T>
void print(stack<T> &s)
{
	while (s.size())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}
    template <class T, int _SZ>
void print(array<T, _SZ> &a)
{
	for (auto p : a)
		cout << p << " ";
	cout << "\n";
}
    template <class T>
void readar(T a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
inline void solve()
{
	// ifstream cin("triangles.in");
	// ofstream cout("triangles.out");
	// find the greaterst pars of students so that the dont vary by 5
	// just sort

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n+1);
	vector<int> deg(n+1);
	for(int i=0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
		deg[x]++;
		deg[y]++;
	}

	vector<pii> a;

	int mx = 0;
	int p = 0;

	for(int i=0; i <= n; i++) {
		if(deg[i] > mx) {
			mx = deg[i];
			p = i;
		}
	}
	vector<bool> vis(n+1);
	auto do_bfs = [&](int cur) {
		queue<int> nodes;
		nodes.push(cur);
		vis[cur]=true;

		while(nodes.size()) {
			int t = nodes.front();
			nodes.pop();
			// if(vis[t]) continue;
			// vis[t]=true;

			for(auto &edge: graph[t]) {
				if(!vis[edge]) {
					nodes.push(edge);
					a.pb({t, edge});
					vis[edge]=true;
				}
			}
		}
	};
	do_bfs(p);
	// cout << p << "\n";
	// print(a);
	print(a);

}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}