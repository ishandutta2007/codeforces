#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

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
const ld EPS = 1e-9;

int slow_solve(int l, int r) {
    int res = 0;
    for (int a = l; a <= r; a++) {
        for (int b = a; b <= r; b++) {
            res = max(res, a ^ b);
        }
    }
    return res;
}

int fast_solve(int l, int r) {
    int a = 0, b = 0, res = 0;
    for (int i = 61; i >= 0; i--) {
        bool can_a = false, need_a = false, need_b = false;
        int to_a = a + (1ll << i), to_b = b + (1ll << i);
        if (to_a <= l) {
            need_a = true;
        }
        if (to_b <= l) {
            need_b = true;
        }
        if (to_a <= r) {
            can_a = true;
        }
        if (need_a && need_b) {
            a |= 1ll << i;
            b |= 1ll << i;
        }
        else if (need_a) {
            a |= 1ll << i;
            res |= 1ll << i;
        }
        else {
            if (can_a) {
                a |= 1ll << i;
                res |= 1ll << i;
            }
        }
        if (a > b) {
            swap(a, b);
        }
    }
    return res;
}

_ void source() {
    int l, r;
    cin >> l >> r;
    cout << fast_solve(l, r);
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    //freopen("input.txt", "r", stdin);
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