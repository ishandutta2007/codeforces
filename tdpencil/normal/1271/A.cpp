#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <utility>
#include <array>
#include <algorithm>
#include <chrono>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define sz(b) (int(b.size()))
#define all(x) x.begin(), x.end()
#define pb push_back
#define popb pop_back
#define tp top
#define sumvt(x) accumulate(all(x), 0LL)
#define sumat(v, n) accumulate(v, v + n, 0LL)
#define vt vector
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
template <class t, int SZ_>
void read(vt<array<t, SZ_>> &a)
{
	for(auto &b: a)
	{
		for(auto &c: b) cin>>c;
	}
}
template<class t>
void read(vt<vt<t>> &a)
{
	for(int i =0; i < sz(a); i++)
	{
		for(int j =0; j < sz(a); j++) cin >> a[i][j];
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
template<class T>
void println(T &a) {
	cout << a;
}
template<class T>
void println(T a) {
	cout << a;
}
template<class T>
void println(vt<T> &a) {
	for(auto &e: a) cout << e << "\n";
}
const int mxn = (1 << 18);
struct treenode
{
	int depth;
	vi adj;

	treenode(int d = 0)
	{
		depth = d;
		adj = vi();
	}
	void addEdge(int x)
	{
		adj.pb(x);
	}
};
void solve()
{
	ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;

	if(f == min(e, f)) {
		ll ans = min(a, d) * e;
		if(a == min(a, d)) {
			d-=a;
			a=0;
		} else if(d == min(a, d)) {
			a-=d;
			d=0;
			cout << ans << "\n";
			return;
		}
		vl res = {b, c, d};
		sort(all(res));
		ans += res[0]*f;
		cout << ans << "\n";
	} else {
		ll ans = 0;
		vl res = {b, c, d};
		sort(all(res));
		ans = res[0] * f;
		d -= res[0];
		vl rRes = {a, d};
		sort(all(rRes));
		ans += rRes[0] * e;
		print(ans);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
}