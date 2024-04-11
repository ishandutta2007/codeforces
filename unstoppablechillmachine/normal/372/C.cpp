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

const int N = 150010;
ll dp1[N], dp2[N];
pair<int, int> arr[N];

_ void source() {
    int n, m, d;
    cin >> n >> m >> d;
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        cin >> arr[i].f >> arr[i].sec;
        ans += arr[i].sec;
        cin >> arr[i].sec;
    }
    for (int i = 1; i <= n; i++) {
        dp1[i] = abs(i - arr[1].f);
    }
    for (int i = 2; i <= m; i++) {
        ll can = ll(arr[i].sec - arr[i - 1].sec) * d;
        deque<pair<ll, int> > q;
        for (int j = 1; j <= n; j++) {
            while (!q.empty() && q.back().f >= dp1[j]) {
                q.pop_back();
            }
            q.push_back({dp1[j], j});
            while (q.front().sec < j - can) {
                q.pop_front();
            }
            dp2[j] = q.front().f + abs(j - arr[i].f);
        }
        while (!q.empty()) {
            q.pop_front();
        }
        for (int j = n; j >= 1; j--) {
            while (!q.empty() && q.back().f >= dp1[j]) {
                q.pop_back();
            }
            q.push_back({dp1[j], j});
            while (q.front().sec > j + can) {
                q.pop_front();
            }
            dp2[j] = min(dp2[j], q.front().f + abs(j - arr[i].f));
        }
        for (int j = 1; j <= n; j++) {
            dp1[j] = dp2[j];
        }
    }
    ll best = BINF;
    for (int i = 1; i <= n; i++) {
        best = min(best, dp1[i]);
    }
    cout << ans - best;
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