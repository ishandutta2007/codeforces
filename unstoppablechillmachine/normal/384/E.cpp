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

const int N = 2e5 + 10;
int t1[8 * N], t2[8 * N], f1[8 * N], f2[8 * N], h[N], val[N];
vector<int> arr;
vector<vector<int> > g;

void dfs(int v, int p = 0, int cur_h = 0) {
    h[v] = cur_h;
    arr.pb(v);
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v, cur_h + 1);
        }
    }
    arr.pb(v);
}

void build1(int v, int l, int r) {
    if (l == r) {
        t1[v] = val[arr[l - 1]];
        return;
    }
    int mid = (l + r) >> 1;
    build1(2 * v, l, mid);
    build1(2 * v + 1, mid + 1, r);
}

void build2(int v, int l, int r) {
    if (l == r) {
        t2[v] = val[arr[l - 1]];
        return;
    }
    int mid = (l + r) / 2;
    build2(2 * v, l, mid);
    build2(2 * v + 1, mid + 1, r);
}

void push1(int v) {
    t1[2 * v] += f1[v];
    f1[2 * v] += f1[v];
    t1[2 * v + 1] += f1[v];
    f1[2 * v + 1] += f1[v];
    f1[v] = 0;
}

void push2(int v) {
    t2[2 * v] += f2[v];
    f2[2 * v] += f2[v];
    t2[2 * v + 1] += f2[v];
    f2[2 * v + 1] += f2[v];
    f2[v] = 0;
}

void upd1(int v, int l, int r, int a, int b, int delta) {
    if (l > b || r < a) {
        return;
    }
    if (l >= a && r <= b) {
        f1[v] += delta;
        t1[v] += delta;
        return;
    }
    push1(v);
    int mid = (l + r) >> 1;
    upd1(2 * v, l, mid, a, b, delta);
    upd1(2 * v + 1, mid + 1, r, a, b, delta);
}

void upd2(int v, int l, int r, int a, int b, int delta) {
    if (l > b || r < a) {
        return;
    }
    if (l >= a && r <= b) {
        f2[v] += delta;
        t2[v] += delta;
        return;
    }
    push2(v);
    int mid = (l + r) >> 1;
    upd2(2 * v, l, mid, a, b, delta);
    upd2(2 * v + 1, mid + 1, r, a, b, delta);
}

int get1(int v, int l, int r, int need) {
    if (l == r) {
        return t1[v];
    }
    push1(v);
    int mid = (l + r) >> 1;
    if (need <= mid) {
        return get1(2 * v, l, mid, need);
    }
    else {
        return get1(2 * v + 1, mid + 1, r, need);
    }
}

int get2(int v, int l, int r, int need) {
    if (l == r) {
        return t2[v];
    }
    push2(v);
    int mid = (l + r) >> 1;
    if (need <= mid) {
        return get2(2 * v, l, mid, need);
    }
    else {
        return get2(2 * v + 1, mid + 1, r, need);
    }
}

int f[N], en[N];

_ void source() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    g.rsz(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    int sz = arr.size();
    for (int i = 0; i < sz; i++) {
        if (!f[arr[i]]) {
            f[arr[i]] = i + 1;
        }
        en[arr[i]] = i + 1;
    }
    build1(1, 1, sz);
    build2(1, 1, sz);
    for (int i = 1; i <= m; i++) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            int delta;
            cin >> delta;
            if (h[v] & 1) {
                upd1(1, 1, sz, f[v], en[v], delta);
                upd2(1, 1, sz, f[v], en[v], -delta);
            }
            else {
                upd1(1, 1, sz, f[v], en[v], -delta);
                upd2(1, 1, sz, f[v], en[v], delta);
            }
        }
        else {
            cout << (h[v] & 1 ? get1(1, 1, sz, f[v]) : get2(1, 1, sz, f[v])) << '\n';
        }
    }

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