#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
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

_ void source() {
    int n, m;
    cin >> n >> m;
    vector<int> have_e(n + 1), cnt(m + 1), ans(n + 1);
    set<pair<int, int> > st;
    vector<vector<pair<int, int> > > check(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        have_e[b] = i;
        check[a].pb({b, i});
        cnt[i] = c;
    }
    for (int i = 1; i <= n; i++) {
        for (auto it : check[i]) {
            st.ins(it);
        }
        if (have_e[i]) {
            if (cnt[have_e[i]]) {
                cout << -1;
                exit(0);
            }
            ans[i] = m + 1;
            continue;
        }
        if (!st.empty()) {
            int num = st.begin()->sec;
            ans[i] = num;
            cnt[num]--;
            if (!cnt[num]) {
                st.ers(st.begin());
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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