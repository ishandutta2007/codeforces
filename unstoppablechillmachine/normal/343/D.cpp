#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("O3")
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
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define endl "\n"

#define right rightt
#define left leftt
#define next nextt
#define prev prevv

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 2e6 + 10;
int down[4 * N], up[4 * N], fi[N], en[N], f[4 * N];
bool used[N];
vector<int> arr;
vector<vector<int> > g;

void dfs(int v) {
    used[v] = true;
    arr.pb(v);
    for (auto u : g[v]) {
        if (!used[u]) dfs(u);
    }
    arr.pb(v);
}

void relax_up(int v) {
    up[v] = max(up[2 * v], up[2 * v + 1]);
}

void upd_up(int v, int l, int r, int need, int val) {
    if (l == r) {
        up[v] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (need <= mid) {
        upd_up(2 * v, l, mid, need, val);
    }
    else {
        upd_up(2 * v + 1, mid + 1, r, need, val);
    }
    relax_up(v);
}

int get_up(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return -INF;
    }
    if (l >= a && r <= b) {
        return up[v];
    }
    int mid = (l + r) / 2;
    return max(get_up(2 * v, l, mid, a, b), get_up(2 * v + 1, mid + 1, r, a, b));
}

void push(int v) {
    if (f[v]) {
        f[2 * v] = f[v];
        f[2 * v + 1] = f[v];
        down[2 * v] = f[v];
        down[2 * v + 1] = f[v];
        f[v] = 0;
    }
}

void upd_down(int v, int l, int r, int a, int b, int val) {
    if (l > b || r < a) {
        return;
    }
    push(v);
    if (l >= a && r <= b) {
        down[v] = val;
        f[v] = val;
        return;
    }
    int mid = (l + r) / 2;
    upd_down(2 * v, l, mid, a, b, val);
    upd_down(2 * v + 1, mid + 1, r, a, b, val);
}

int get_down(int v, int l, int r, int need) {
    if (l == r) {
        return down[v];
    }
    push(v);
    int mid = (l + r) / 2;
    if (need <= mid) {
        return get_down(2 * v, l, mid, need);
    }
    return get_down(2 * v + 1, mid + 1, r, need);
}

_ void source() {
    int n;
    cin >> n;
    g.rsz(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    int sz = arr.size();
    arr.ins(arr.begin(), ' ');
    for (int i = 1; i <= sz; i++) {
        int v = arr[i];
        if (!fi[v]) {
            fi[v] = i;
        }
        en[v] = i;
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int v;
            cin >> v;
            upd_down(1, 1, sz, fi[v], en[v], i);
        }
        if (type == 2) {
            int v;
            cin >> v;
            upd_up(1, 1, sz, fi[v], i);
        }
        if (type == 3) {
            int v;
            cin >> v;
            if (get_up(1, 1, sz, fi[v], en[v]) < get_down(1, 1, sz, fi[v])) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
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