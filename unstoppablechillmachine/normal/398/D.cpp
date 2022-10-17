//I_l_M_P
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")

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
const ld PI = acos(-1);

const int SIZE = sqrt(450000);

_ void source() {
    int n, m, q;
    cin >> n >> m >> q;
    int cnt;
    cin >> cnt;
    vector<bool> online(n + 1);
    for (int i = 1; i <= cnt; i++) {
        int x;
        cin >> x;
        online[x] = true;
    }
    vector<unordered_set<int> > fr(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        fr[u].ins(v);
        fr[v].ins(u);
    }
    vector<int> cnt_small(n + 1);
    set<int> cur_big;
    for (int i = 1; i <= n; i++) {
        for (auto it : fr[i]) {
            if (fr[it].size() <= SIZE && online[it]) {
                cnt_small[i]++;
            }
        }
        if (fr[i].size() > SIZE) {
            cur_big.ins(i);
        }
    }
    for (int i = 1; i <= q; i++) {
        char type;
        cin >> type;
        if (type == 'C') {
            int x;
            cin >> x;
            int ans = cnt_small[x];
            for (auto it : cur_big) {
                if (online[it] && fr[x].find(it) != fr[x].end()) {
                    ans++;
                }
            }
            cout << ans << '\n';
        }
        if (type == 'O') {
            int x;
            cin >> x;
            online[x] = true;
            if (fr[x].size() <= SIZE) {
                for (auto it : fr[x]) {
                    cnt_small[it]++;
                }
            }
        }
        if (type == 'F') {
            int x;
            cin >> x;
            online[x] = false;
            if (fr[x].size() <= SIZE) {
                for (auto it : fr[x]) {
                    cnt_small[it]--;
                }
            }
        }
        if (type == 'A') {
            int u, v;
            cin >> u >> v;
            fr[u].ins(v);
            fr[v].ins(u);
            if (fr[u].size() > SIZE) {
                cur_big.ins(u);
            }
            if (fr[v].size() > SIZE) {
                cur_big.ins(v);
            }
            if (online[u] && fr[u].size() <= SIZE) {
                cnt_small[v]++;
            }
            if (online[v] && fr[v].size() <= SIZE) {
                cnt_small[u]++;
            }
            if (fr[u].size() == SIZE + 1 && online[u]) {
                for (auto it : fr[u]) {
                    if (it != v) {
                        cnt_small[it]--;
                    }
                }
            }
            if (fr[v].size() == SIZE + 1 && online[v]) {
                for (auto it : fr[v]) {
                    if (it != u) {
                        cnt_small[it]--;
                    }
                }
            }
        }
        if (type == 'D') {
            int u, v;
            cin >> u >> v;
            fr[u].ers(v);
            fr[v].ers(u);
            if (fr[u].size() <= SIZE) {
                cur_big.ers(u);
            }
            if (fr[v].size() <= SIZE) {
                cur_big.ers(v);
            }
            if (online[u] && fr[u].size() < SIZE) {
                cnt_small[v]--;
            }
            if (online[v] && fr[v].size() < SIZE) {
                cnt_small[u]--;
            }
            if (fr[v].size() == SIZE && online[v]) {
                for (auto it : fr[v]) {
                    cnt_small[it]++;
                }
            }
            if (fr[u].size() == SIZE && online[u]) {
                for (auto it : fr[u]) {
                    cnt_small[it]++;
                }
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