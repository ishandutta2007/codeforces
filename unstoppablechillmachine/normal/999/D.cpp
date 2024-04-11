//I_l_M_P
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

_ int get(int from, int to, int mod) {
    int res = to - from;
    if (res < 0) {
        res += mod;
    }
    return res;
}

_ void source() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    vector<vector<int> > have(m);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        have[arr[i] % m].pb(i);
    }
    int pos = 1;
    bool was = false, t = false;
    for (int i = 0; i < m; i++) {
        if (!was) pos = max(pos, i + 1);
        if (pos == m) {
            pos = 0;
        }
        while ((int)have[i].size() > n / m) {
            while ((int)have[pos].size() >= n / m) {
                pos++;
                if (pos >= m) {
                    pos = 0;
                    was = true;
                }
                if (pos == i) {
                    break;
                }
            }
            if (pos == i) {
                t = true;
                break;
            }
            int k = min((int)have[i].size() - n / m, n / m - (int)have[pos].size());
            for (int j = 0; j < k; j++) {
                have[pos].pb(have[i].back());
                have[i].pop_back();
            }
        }
        if (t) {
            break;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (auto it : have[i]) {
            ans += get(arr[it] % m, i, m);
            arr[it] += get(arr[it] % m, i, m);
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
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