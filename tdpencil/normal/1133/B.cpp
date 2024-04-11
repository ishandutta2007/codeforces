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
	int n, k;
	cin >> n >> k;
	vi a(n);
	read(a);
	// sort(all(a));

	vector<int64_t> freq(k, 0);


	for(int i=0; i < n; i++) {
		freq[a[i]%k]++;
	}

	// greedy sol just join k with k
	// the answer is just the amount of k's plus the amount of things that sum up to k


	ll ans = 2*(freq[0]/2);
	for(int i=1; i <= k/2; i++) {
		if(i == k-i) {
			ans += 2*(freq[i]/2);
		} else {
			ans += 2 * min(freq[i], freq[k-i]);
			// you can just take pairs from the minimum
		}
		
		// cout << i << " " << k - i << "\n";
		// assert(i + k - i == k);
		// [0], [1], [1]
		// [0], [1], [2]
	}
	// print(freq);

	cout << ans << "\n";


}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}