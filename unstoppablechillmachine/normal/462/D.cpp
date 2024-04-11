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
vector<vector<int> > g;
int dp[N][2];
bool c[N];

_ void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

_ int b_pow(int a, int b) {
    if (!b) {
        return 1;
    }
    if (b & 1) {
        return (b_pow(a, b - 1) * a) % MOD;
    }
    int c = b_pow(a, b >> 1);
    return (c * c) % MOD;
}

_ int inv(int x) {
    x %= MOD;
    return b_pow(x, MOD - 2);
}

void dfs(int v) {
    if (c[v]) {
        dp[v][1] = 1;
        for (auto u : g[v]) {
            dfs(u);
            dp[v][1] = (dp[v][1] * (dp[u][0] + dp[u][1])) % MOD;
        }
    }
    else {
        dp[v][0] = 1;
        for (auto u : g[v]) {
            dfs(u);
            dp[v][0] = (dp[v][0] * (dp[u][0] + dp[u][1])) % MOD;
        }
        for (auto u : g[v]) {
            add(dp[v][1], (((dp[v][0] * inv(dp[u][1] + dp[u][0])) % MOD) * dp[u][1]) % MOD);
        }
    }
}

_ void source() {
    int n;
    cin >> n;
    g.rsz(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        p++;
        g[p].pb(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    dfs(1);
    /*for (int i = 1; i <= n; i++) {
        cout << dp[i][0] << ' ' << dp[i][1] << endl;
    }*/
    cout << dp[1][1];
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