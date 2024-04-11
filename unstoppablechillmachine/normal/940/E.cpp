#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("O3")
#pragma GCC optimize ("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

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
int t[8 * N], dp_t[8 * N], dp_add[8 * N], arr[N], dp[N], pref[N];

void relax(int v) {
    t[v] = min(t[2 * v], t[2 * v + 1]);
}

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    relax(v);
}

int get_min(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return BINF;
    }
    if (l >= a && r <= b) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return min(get_min(2 * v, l, mid, a, b), get_min(2 * v + 1, mid + 1, r, a, b));
}

void relax_dp(int v) {
    dp_t[v] = min(dp_t[2 * v], dp_t[2 * v + 1]);
}

void push_dp(int v, int l, int r) {
    if (dp_add[v]) {
        dp_add[2 * v] += dp_add[v];
        dp_add[2 * v + 1] += dp_add[2 * v + 1];
        dp_t[2 * v] += dp_add[v];
        dp_t[2 * v + 1] += dp_add[v];
        dp_add[v] = 0;
    }
}

void upd_dp(int v, int l, int r, int need) {
    if (l == r) {
        dp_t[v] = dp[need];
        return;
    }
    push_dp(v, l, r);
    int mid = (l + r) / 2;
    if (need <= mid) {
        upd_dp(2 * v, l, mid, need);
    }
    else {
        upd_dp(2 * v + 1, mid + 1, r, need);
    }
    relax_dp(v);
}

void add_dp(int v, int l, int r, int a, int b, int need_add) {
    if (l > b || r < a) {
        return;
    }
    push_dp(v, l, r);
    if (l >= a && r <= b) {
        dp_add[v] += need_add;
        dp_t[v] += need_add;
        return;
    }
    int mid = (l + r) / 2;
    add_dp(2 * v, l, mid, a, b, need_add);
    add_dp(2 * v + 1, mid + 1, r, a, b, need_add);
    relax_dp(v);
}

int get_min_dp(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return BINF;
    }
    push_dp(v, l, r);
    if (l >= a && r <= b) {
        return dp_t[v];
    }
    int mid = (l + r) / 2;
    return min(get_min_dp(2 * v, l, mid, a, b), get_min_dp(2 * v + 1, mid + 1, r, a, b));
}

_ void source() {
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i - 1] + arr[i];
    }
    build(1, 1, n);
    for (int i = 1; i < c; i++) {
        cerr << get_min_dp(1, 1, n, 1, i - 1) << endl;
        dp[i] = pref[i];
        upd_dp(1, 1, n, i);
        add_dp(1, 1, n, 1, i, arr[i + 1]);
    }
    for (int i = c; i <= n; i++) {
        int mn = get_min_dp(1, 1, n, 1, i - 1);
        dp[i] = min(mn, dp[i - c] + pref[i] - pref[i - c] - get_min(1, 1, n, i - c + 1, i));
        upd_dp(1, 1, n, i);
        add_dp(1, 1, n, 1, i, arr[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        cerr << dp[i] << ' ';
    }
    cerr << endl;
    cout << dp[n];
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