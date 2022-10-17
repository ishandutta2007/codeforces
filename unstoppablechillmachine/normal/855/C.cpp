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

const int N = 1e5 + 10;
const int X = 11;
vector<vector<int> > g;
int dp[N][X][3], ndp[N][X][3], k, x, m;

_ void add(int &a, int b) {
    a = (a + b + 10 * MOD) % MOD;
}

_ int sum(int a, int b) {
    return (a + b + 10 * MOD) % MOD;
}

_ int mult(int a, int b) {
    return (a * b) % MOD;
}

void dfs(int v, int p = 0) {
    dp[v][0][0] = k - 1;
    dp[v][1][1] = 1;
    dp[v][0][2] = m - k;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
            for (int was = 0; was <= x; was++) {
                for (int cur = 0; cur + was <= x; cur++) {
                    add(ndp[v][cur + was][0], mult(dp[v][cur][0], sum(sum(dp[u][was][0], dp[u][was][1]), dp[u][was][2])));
                    add(ndp[v][cur + was][1], mult(dp[v][cur][1], dp[u][was][0]));
                    add(ndp[v][cur + was][2], mult(dp[v][cur][2], sum(dp[u][was][0], dp[u][was][2])));
                }
            }
            for (int i = 0; i <= x; i++) {
                for (int j = 0; j < 3; j++) {
                    dp[v][i][j] = ndp[v][i][j];
                    ndp[v][i][j] = 0;
                }
            }
        }
    }
}

_ void source() {
    int n;
    cin >> n >> m;
    g.rsz(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> k >> x;
    dfs(1);
    int ans = 0;
    for (int i = 0; i <= x; i++) {
        add(ans, dp[1][i][0]);
        add(ans, dp[1][i][1]);
        add(ans, dp[1][i][2]);
    }
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