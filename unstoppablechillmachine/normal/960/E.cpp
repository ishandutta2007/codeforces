#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
//using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
//#define endl "\n"

#define right rightt
#define left leftt
#define next nextt
#define prev prevv

mt19937 Random(int(time(0)));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-6;

const int N = 2e5 + 10;

vector<vector<int> > g;
int up1[N], up0[N], down1[N], down0[N], up1_cnt[N], up0_cnt[N], down1_cnt[N], down0_cnt[N], arr[N], ans;

_ void add(int &a, int b) {
    if (b < 0) {
        b += MOD;
    }
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

_ void mult(int &a, int b) {
    if (b < 0) {
        b += MOD;
    }
    a = (a * b) % MOD;
}

_ int sum(int a, int b) {
    if (b < 0) {
        b += MOD;
    }
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

_ int get_mult(int a, int b) {
    if (b < 0) {
        b += MOD;
    }
    return (a * b) % MOD;
}

void dfs(int v, int p = 0) {
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
            add(up1[v], sum(up0[u], get_mult(up0_cnt[u], arr[v])));
            add(up1_cnt[v], up0_cnt[u]);
            add(up0[v], sum(up1[u], get_mult(up1_cnt[u], -arr[v])));
            add(up0_cnt[v], up1_cnt[u]);

            add(down1[v], sum(down0[u], get_mult(down0_cnt[u], arr[v])));
            add(down1_cnt[v], down0_cnt[u]);
            add(down0[v], sum(down1[u], get_mult(down1_cnt[u], -arr[v])));
            add(down0_cnt[v], down1_cnt[u]);
        }
    }
    for (auto u : g[v]) {
        if (u != p) {
            int cnt_down = down0_cnt[u], sum_down = down0[u], cnt_up = sum(up1_cnt[v], -up0_cnt[u]), sum_up = sum(up1[v], -sum(up0[u], get_mult(up0_cnt[u], arr[v])));
            int cur = sum(get_mult(sum_up, cnt_down), get_mult(sum_down, cnt_up));
            add(ans, cur);
            cnt_down = down1_cnt[u], sum_down = down1[u], cnt_up = sum(up0_cnt[v], -up1_cnt[u]), sum_up = sum(up0[v], -sum(up1[u], get_mult(up1_cnt[u], -arr[v])));
            cur = sum(get_mult(sum_up, cnt_down), get_mult(sum_down, cnt_up));
            add(ans, cur);
        }
    }
    add(up1[v], arr[v]);
    add(up1_cnt[v], 1);
    add(down1[v], arr[v]);
    add(down1_cnt[v], 1);
    add(ans, down1[v]);
    add(ans, up1[v]);
    add(ans, -arr[v]);
}

_ void source() {
    int n;
    cin >> n;
    g.rsz(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            arr[i] += MOD;
        }
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
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