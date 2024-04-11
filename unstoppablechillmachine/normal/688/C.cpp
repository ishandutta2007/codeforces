#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ld> vld;
typedef vector<bool> vb;

#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz size
#define rsz resize
#define fro for
#define itn int
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-9;
const ld PI = acos(-1);

int n, m, a, from, to, parent[MAXN];
vi arr1, arr2;

void make_set(int v)
{
    parent[v] = v;
}

int find_color(int v)
{
    if (parent[v] == v) return v;
    else return (parent[v] = find_color(parent[v]));
}

void union_sets(int a, int b)
{
    //cout << a << " " << b << endl;
    a = find_color(a);
    b = find_color(b);
    if (a == b)
    {
        cout << -1;
        exit(0);
    }
    if(a > b) swap(a, b);
    if (a % 2 == 1)
    {
        parent[b] = a + 1;
        if (b % 2 == 1) parent[b + 1] = a;
        else parent[b - 1] = a;
    }
    else
    {
        parent[b] = a - 1;
        if (b % 2 == 1) parent[b + 1] = a;
        else parent[b - 1] = a;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m;
    fore(i, n)
    {
        make_set(i * 2 + 1);
        make_set(i * 2 + 2);
    }
    forn(i, m)
    {
        cin >> from >> to;
        from = 2 * from - 1;
        to = 2 * to - 1;
        //cout << find_color(from) << " " << find_color(to) << endl;
        union_sets(from, to);
    }
    forn(i, n)
    {
        a = find_color(2 * i - 1);
        if (a % 2 == 1) arr1.pb(i);
        else arr2.pb(i);
    }
    cout << arr1.size() << endl;
    intcpy(arr1);
    cout << endl;
    cout << arr2.size() << endl;
    intcpy(arr2);
    return 0;
}