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

bool prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

const int N = 110;
const int MX = (1 << 17) + 10;
int dp[N][MX], from[N][MX], calc[60], val[N];

_ void source() {
    vector<int> arr;
    for (int i = 2; i < 60; i++) {
        if (prime(i)) {
            arr.pb(i);
        }
    }
    int cnt = arr.size();
    for (int i = 1; i < 60; i++) {
        for (int j = 0; j < cnt; j++) {
            if (i % arr[j] == 0) {
                calc[i] |= 1 << j;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    int lim = 1 << cnt;
    for (int i = 0; i <= n; i++) {
        for (int mask = 0; mask < lim; mask++) {
            dp[i][mask] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < lim; mask++) {
            if (dp[i][mask] == INF) {
                continue;
            }
            for (int to = 1; to <= 59; to++) {
                if ((calc[to] & mask) == 0) {
                    if (dp[i][mask] + abs(val[i + 1] - to) < dp[i + 1][calc[to] | mask]) {
                        dp[i + 1][calc[to] | mask] = dp[i][mask] + abs(val[i + 1] - to);
                        from[i + 1][calc[to] | mask] = to;
                    }
                }
            }
        }
    }
    pair<int, int> now = {INF, INF};
    for (int mask = 0; mask < lim; mask++) {
        if (dp[n][mask] < INF) {
        }
        now = min(now, {dp[n][mask], mask});
    }
    int cur_mask = now.sec;
    vector<int> ans;
    for (int i = n; i >= 1; i--) {
        ans.pb(from[i][cur_mask]);
        cur_mask ^= calc[from[i][cur_mask]];
    }
    reverse(all(ans));
    for (auto it : ans) {
        cout << it << ' ';
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