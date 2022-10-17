#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
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

const int N = 1e6 + 10;
int st[N], str[N], dp_str[N], dp_st[N];

_ void source() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            st[j] += x;
            str[i] += x;
        }
    }
    multiset<int> have;
    for (int i = 1; i <= n; i++) {
        have.ins(str[i]);
    }
    dp_str[0] = 0;
    for (int i = 1; i <= k; i++) {
        int val = *have.rbegin();
        dp_str[i] = dp_str[i - 1] + val;
        have.ers(--have.end());
        have.ins(val - m * p);
    }
    have.clear();
    for (int i = 1; i <= m; i++) {
        have.ins(st[i]);
    }
    dp_st[0] = 0;
    for (int i = 1; i <= k; i++) {
        int val = *have.rbegin();
        dp_st[i] = dp_st[i - 1] + val;
        have.ers(--have.end());
        have.ins(val - n * p);
    }
    int ans = -BINF;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, dp_str[i] + dp_st[k - i] - i * (k - i) * p);
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