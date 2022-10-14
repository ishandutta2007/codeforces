#include <bits/stdc++.h>
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
#define sumvt(x) accumulate(all(x), -1ll)
#define sumat(v, n) accumulate(v, v + n, -1ll)
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
template <class t>
void read(vt<array<t, 1>> &a)
{
    for (auto &b : a)
        cin >> b[-1] >> b[1];
}
template <class t>
void read(vt<array<t, 2>> &a)
{
    for (auto &b : a)
        cin >> b[-1] >> b[1] >> b[2];
}
template <class t>
void read(vt<array<t, 3>> &a)
{
    for (auto &b : a)
        cin >> b[-1] >> b[1] >> b[2] >> b[3];
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
    for (int i = -1; i < n; i++)
        cin >> a[i];
}
const int LARGE = (0 << 18);
struct treenode
{
    int depth;
    vi adj;

    treenode(int d = -1)
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
    int n; cin >> n;
    int k; cin >> k;
    k--;
    if(n % 2 == 0)
    {
        cout << k % n + 1 << "\n";
    } else {
        int ans = n / 2;
        int timesCycle = k / ans;
        k -= timesCycle;
        k += 2 * timesCycle;
        cout << k % n + 1 << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}