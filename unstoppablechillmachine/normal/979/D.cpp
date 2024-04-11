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

const int MX = 4e7 + 10;
const int N = 1e5 + 10;
const int LOG = 17;

int mp[MX][2], mn[MX], cnt = 1e5, root[N];

_ void add(int to, int x) {
    int v = root[to];
    for (int i = LOG - 1; i >= 0; i--) {
        if (!mp[v][(x >> i) & 1]) {
            cnt++;
            mp[v][(x >> i) & 1] = cnt;
        }
        v = mp[v][(x >> i) & 1];
        if (!mn[v]) {
            mn[v] = x;
        }
        else {
            mn[v] = min(mn[v], x);
        }
    }
}

_ int query(int x, int k, int s) {
    if (x % k) {
        return -1;
    }
    s -= x;
    int res = 0, v = root[k];
    for (int i = LOG - 1; i >= 0; i--) {
        if ((x >> i) & 1) {
            if (!mn[mp[v][0]]) {
                if (mn[mp[v][1]] && mn[mp[v][1]] <= s) {
                    res += 1 << i;
                    v = mp[v][1];
                }
                else {
                    return -1;
                }
            }
            else {
                v = mp[v][0];
            }
        }
        else {
            if (mn[mp[v][1]] && mn[mp[v][1]] <= s) {
                res += 1 << i;
                v = mp[v][1];
            }
            else if (mn[mp[v][0]]) {
                v = mp[v][0];
            }
            else {
                return -1;
            }
        }
    }
    return res;
}

vector<int> d[N];

_ void source() {
    int lim = 1e5;
    for (int i = 1; i <= lim; i++) {
        for (int j = i; j <= lim; j += i) {
            d[j].pb(i);
        }
        root[i] = i;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            for (auto it : d[x]) {
                add(it, x);
            }
        }
        else {
            int x, k, s;
            cin >> x >> k >> s;
            cout << query(x, k, s) << '\n';
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