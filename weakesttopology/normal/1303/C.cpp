#include "bits/stdc++.h"

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];
#define SZ(X) (int)X.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void dfs(int root, const vector<set<int>>& E, vi& vis, vi& order)
{
    vis[root] = 1;
    order.pb(root);

    for (auto x : E[root])
    {
        if (not vis[x])
            dfs(x, E, vis, order);
    }
}

int main()
{ _
    int T; cin >> T;

    while (T--)
    {
        string s; cin >> s;

        if (s.size() == 1)
        {
            cout << "YES\n";
            for (int i = 0; i < 26; ++i)
                cout << char('a' + i);
            cout << endl;
            continue;
        }

        vector<set<int>> E(26);
        for (int i = 1; i < SZ(s); ++i)
        {
            int u = s[i - 1] - 'a', v = s[i] - 'a';

            E[u].insert(v);
            E[v].insert(u);
        }

        int z = -1;

        bool f = false;
        for (int i = 0; i < 26; ++i)
        {
            if (E[i].size() > 2)
                f = true;
            if (E[i].size() == 1)
                z = i;
        }

        if (f || z == -1)
        {
            cout << "NO\n";
            continue;
        }

        vi vis(26, 0), order;
        dfs(z, E, vis, order);

        set<int> S;
        for (auto x : order)
            S.insert(x);

        for (int i = 0; i < 26; ++i)
            if (S.count(i) == 0)
                order.pb(i);

        cout << "YES\n";
        for (auto x : order)
            cout << char('a' + x);
        cout << endl;
    }

    exit(0);
}

/*
 * INT_MAX ~ 2 * 1e9 ~ 2^31 - 1
 * LLONG_MAX ~ 9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF ~ 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
*/