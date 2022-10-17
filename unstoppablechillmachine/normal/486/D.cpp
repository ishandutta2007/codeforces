#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

vector<vector<int> > g;
int dp_good[2010][2010], dp_bad[2010][2010], arr[2010], mx, ans, d;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void subtract(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += MOD;
    }
}

int sum(int a, int b) {
    return (a + b) % MOD;
}

void mult(int &a, int b) {
    a = (a * b) % MOD;
}

void dfs(int v, int p) {
    for (int i = 0; i <= mx; i++) {
        if (i == arr[v]) {
            dp_good[v][i] = 1;
        }
        else if (arr[v] >= i - d && arr[v] < i) {
            dp_good[v][i] = 1;
            dp_bad[v][i] = 1;
        }
    }
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
            for (int i = 0; i <= mx; i++) {
                mult(dp_bad[v][i], sum(dp_bad[u][i], 1));
                mult(dp_good[v][i], sum(sum(dp_bad[u][i], dp_good[u][i]), 1));
            }
        }
    }
    for (int i = 0; i <= mx; i++) {
        subtract(dp_good[v][i], dp_bad[v][i]);
        add(ans, dp_good[v][i]);
        //cout << v << ' ' << i << ' ' << dp_good[v][i] << endl;
    }
}

_ void source() {
    int n;
    cin >> d >> n;
    g.rsz(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    cout << ans;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}