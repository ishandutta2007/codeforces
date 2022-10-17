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

ll shift_vals[110], shift_parents[110];

_ int get_level(ll x) {
    assert(x > 0);
    return 63 - __builtin_clzll(x);
}

_ void upd_vals(ll x, ll k) {
    int level = get_level(x);
    if (k < 0) {
        k = (k + (1ll << 61)) % (1ll << level);
    }
    assert(k >= 0);
    shift_vals[level] += k;
    shift_vals[level] %= 1ll << level;
    assert(shift_vals[level] < (1ll << level) && shift_vals[level] >= 0);
}

_ void upd_parents(ll x, ll k) {
    int level = get_level(x);
    if (k < 0) {
        k = (k + (1ll << 61)) % (1ll << level);
    }
    assert(k >= 0);
    shift_parents[level] += k;
    shift_parents[level] %= 1ll << level;
    assert(shift_parents[level] < (1ll << level) && shift_parents[level] >= 0);
}

_ ll get_val(ll x) {
    int level = get_level(x);
    ll cnt_on_level = 1ll << level;
    ll res = x - shift_vals[level];
    if (res < cnt_on_level) {
        res += cnt_on_level;
    }
    if (res >= cnt_on_level * 2) {
        res -= cnt_on_level;
    }
    assert(res >= cnt_on_level && res < 2 * cnt_on_level);
    return res;
}

_ ll get_parent(ll x) {
    int level = get_level(x);
    ll cnt_on_level = 1ll << level;
    ll res = x + shift_parents[level];
    if (res < cnt_on_level) {
        res += cnt_on_level;
    }
    if (res >= cnt_on_level * 2) {
        res -= cnt_on_level;
    }
    assert(res >= cnt_on_level && res < 2 * cnt_on_level);
    return res / 2;
}

_ void up(ll x) {
    while (x) {
        cout << get_val(x) << ' ';
        x = get_parent(x);
    }
}

_ void source() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            ll x, k;
            cin >> x >> k;
            upd_vals(x, k);
        }
        else if (type == 2) {
            ll x, k;
            cin >> x >> k;
            upd_parents(x, k);
        }
        else {
            ll x;
            cin >> x;
            int level = get_level(x);
            x += shift_vals[level];
            if (x >= 1ll << (level + 1)) {
                x -= 1ll << level;
            }
            up(x);
            cout << '\n';
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