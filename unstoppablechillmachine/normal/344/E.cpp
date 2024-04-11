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
typedef unsigned long long ull;
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

const int N = 1e5 + 10;
int a[N], b[N];

_ void source() {
    int n, m;
    cin >> n >> m;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st.ins(a[i]);
    }
    int cnt = 1;
    for (int i = 1; i <= m; i++) {
        cin >> b[cnt];
        if (st.find(b[cnt]) == st.end()) cnt++;
    }
    int l = -1, r = 2e10 + 10;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int last = cnt - 1;
        for (int i = n; i >= 1; i--) {
            int time = mid, cur_pos = a[i], prev_last = last;
            while (last && time) {
                if (abs(cur_pos - b[last]) > time) {
                    break;
                }
                time -= abs(cur_pos - b[last]);
                cur_pos = b[last];
                last--;
            }
            while (last && abs(a[i] - b[last]) + abs(b[last] - b[prev_last]) <= mid) {
                last--;
            }
        }
        if (!last) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r;
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