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
	string s, t;
	cin >> s >> t;
	int a = stoi(s.substr(0, 2));
	int b = stoi(s.substr(3));
	int x = stoi(t.substr(0, 2));
	int y = stoi(t.substr(3));

	int lM = a * 60 + b;
	int rM = x * 60 + y;

	int mB = (lM+rM) / 2;
	// cerr << mB << "\n";
	int p = mB/60;
	// 

	if(p < 10) {
		mB%=60;
		if(mB%60<10) {
			cout << 0 << p << ":" << 0 << mB << "\n";
		} else {
			cout << 0 << p << ":" << mB << "\n";
		}
	} else {
		mB%=60;
		if(mB%60<10) {
			cout << p << ":" << 0 << mB << "\n";
		} else {
			cout << p << ":" << mB << "\n";
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}