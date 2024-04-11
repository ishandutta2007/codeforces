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
#define sumvt(x) accumulate(all(x), 0ll)
#define sumat(v, n) accumulate(v, v + n, 0ll)
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
const int LARGE = (1 << 18);
struct treenode
{
    int depth;
    vi adj;
    
    treenode(int d=0)
    {
        depth=d;
        adj = vi();
    }
    void addEdge(int x)
    {
        adj.pb(x);
    }
};
void solve()
{
    int n, m;cin >> n >> m;
    vt<vi> gr(n);
    
    vt<pair<int, int>> costs(n);
    for(int i = 0; i < n; i++)
    {
        costs[i].first = i;
        cin >> costs[i].second;
    }
    sort(all(costs), [&](const auto a, const auto b)
    {
        return a.second < b.second;
    }); 
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        gr[x].pb(y);
        gr[y].pb(x);
    }

    ll ans = 0;
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int cur)
    {
        if(vis[cur]) return;
        vis[cur]=true;
        for(int &e: gr[cur])
        {
            dfs(e);
        }
    };
    for(int i = 0; i < n; i++)
    {
        if(!vis[costs[i].first])
        {
            ans += costs[i].second;
            dfs(costs[i].first);
        }
    }
    cout << ans << "\n";
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