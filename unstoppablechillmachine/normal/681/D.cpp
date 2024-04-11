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
const ld EPS = 1e-10;
const ld PI = acos(-1);

int used[MAXN], col[MAXN], parent[MAXN], n, m, a, b;
set<int> st;
vi arr;
vvi Vec;
void dfs(int v)
{
    used[v] = 1;
    fore(i, Vec[v].size())
    {
        if (v == Vec[v][i]) continue;
        if (!used[Vec[v][i]]) dfs(Vec[v][i]);
        else if (used[Vec[v][i]] == 1)
        {
            cout << -1;
            exit(0);
        }
    }
    used[v] = 2;
    arr.pb(v);
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
    Vec.rsz(n + 1);
    forn(i, n) parent[i] = i;
    forn(i, m)
    {
        cin >> a >> b;
        parent[b] = a;
    }
    forn(i, n)
    {
        cin >> col[i];
        st.ins(col[i]);
    }
    forn(i, n)
    {
        if (col[i] != i && col[i] != col[parent[i]])
        {
            cout << -1;
            exit(0);
        }
        else if (col[i] == i) Vec[i].pb(col[parent[i]]);
    }

    forn(i, n)
    {
        if (!used[i]) dfs(i);
    }
    reverse(all(arr));
    cout << st.size() << endl;
    fore(i, arr.size())
    {
        if (st.find(arr[i]) != st.end()) cout << arr[i] << endl;
    }
    return 0;
}