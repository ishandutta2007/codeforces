#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,unroll-loops,fast-math")
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

_ void source() {
    int n, m, q;
    cin >> n >> m >> q;
    multiset<int> have_v, have_g;
    set<int> l_g, l_h;
    have_v.ins(n);
    have_g.ins(m);
    l_g.ins(0);
    l_g.ins(m);
    l_h.ins(0);
    l_h.ins(n);
    for (int i = 1; i <= q; i++) {
        char type;
        int x;
        cin >> type >> x;
        if (type == 'H') {
            auto it = --l_g.upper_bound(x), it2 = it;
            it2++;
            have_g.ers(have_g.find(*it2 - *it));
            have_g.ins(x - *it);
            have_g.ins(*it2 - x);
            l_g.ins(x);
        }
        else {
            auto it = --l_h.upper_bound(x), it2 = it;
            it2++;
            have_v.ers(have_v.find(*it2 - *it));
            have_v.ins(x - *it);
            have_v.ins(*it2 - x);
            l_h.ins(x);
        }
        cout << *have_v.rbegin() * (*have_g.rbegin()) << '\n';
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