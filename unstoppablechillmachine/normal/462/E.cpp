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
//#define int ll
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
int t[N], arr[N], n;

_ void upd(int v, int delta) {
    for (; v <= n; v += v & (-v)) {
        t[v] += delta;
    }
}

_ int sum(int v) {
    int res = 0;
    for (; v > 0; v -= v & (-v)) {
        res += t[v];
    }
    return res;
}

_ int get_sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

_ int next(int cur) {
    return (cur == n ? 1 : cur + 1);
}

_ int prev(int cur) {
    return (cur == 1 ? n : cur - 1);
}

_ int upd_on_pref(int l, int len) {
    int cur = l;
    vector<int> kek;
    for (int j = 1; j <= len; j++) {
        kek.pb(get_sum(cur, cur));
        upd(cur, -kek.back());
        cur = next(cur);
    }
    l = cur;
    for (int j = 1; j <= len; j++) {
        upd(cur, kek[len - j]);
        cur = next(cur);
    }
    return l;
}

_ void upd_on_suf(int r, int len) {
    int cur = r;
    vector<int> kek;
    for (int j = 1; j <= len; j++) {
        kek.pb(get_sum(cur, cur));
        upd(cur, -kek.back());
        cur = prev(cur);
    }
    for (int j = 1; j <= len; j++) {
        upd(cur, kek[len - j]);
        cur = prev(cur);
    }
}

_ void source() {
    int q;
    cin >> n >> q;
    int l = 1, sz = n;
    for (int i = 1; i <= n; i++) {
        upd(i, 1);
    }
    bool rev = false;
    for (int i = 1; i <= q; i++) {
        int r = l + sz - 1;
        if (r > n) {
            r -= n;
        }
        int type;
        cin >> type;
        if (type == 1) {
            int len;
            cin >> len;
            if (len < sz - len) {
                if (!rev) {
                    l = upd_on_pref(l, len);
                }
                else {
                    upd_on_suf(r, len);
                }
            }
            else {
                if (!rev) {
                    upd_on_suf(r, sz - len);
                }
                else {
                    l = upd_on_pref(l, sz - len);
                }
                rev ^= true;
            }
            sz = max(sz - len, len);
        }
        else {
            int cur_l, cur_r;
            cin >> cur_l >> cur_r;
            cur_l++;
            if (rev) {
                cur_l = sz - cur_l + 1, cur_r = sz - cur_r + 1;
                swap(cur_l, cur_r);
            }
            int tl = l + cur_l - 1, tr = l + cur_r - 1;
            if (tl <= n && tr <= n) {
                cout << get_sum(tl, tr) << '\n';
            }
            else if (tl <= n && tr > n) {
                cout << get_sum(tl, n) + get_sum(1, tr - n) << '\n';
            }
            else {
                cout << get_sum(tl - n, tr - n) << '\n';
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