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

bool arr[110][110];
int val[110], cnt[110];

_ void source() {
    int n, m, k, ans = INF;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    /*if (m <= 20) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j]) {
                    val[i] |= 1 << (j - 1);
                }
            }
        }
        for (int i = 0; i < (1 << m); i++) {
            if (__builtin_popcount(i) > k) {
                continue;
            }
            int kek = 0;
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    kek += (val[1] ^ ((1 << m) - 1)) & (1 << j);
                }
                else {
                    kek += val[1] & (1 << j);
                }
            }
            int sum = 0;
            for (int j = 2; j <= n; j++) {
                int x = __builtin_popcount(kek ^ val[j]);
                sum += min(x, m - x);
            }
            ans = min(ans, sum + __builtin_popcount(i));
        }
    }
    else {*/
        ans = 0;
        for (int i = 2; i <= n; i++) {
            int sum = 0;
            for (int j = 1; j <= m; j++) {
                sum += arr[i][j] != arr[1][j];
            }

            ans += min(sum, m - sum);
            if (min(sum, m - sum) > k) {
                cout << -1;
                exit(0);
            }
            for (int j = 1; j <= m; j++) {
                if (sum < m - sum) {
                    cnt[j] += arr[i][j] != arr[1][j];
                }
                else {
                    cnt[j] += arr[i][j] == arr[1][j];
                }
            }
        }
        vector<pair<int, int> > sw;
        for (int i = 1; i <= m; i++) {
            sw.pb({cnt[i], i});
        }
        sort(rall(sw));
        for (int cnt = 0; cnt < min(m, k); cnt++) {
            arr[1][sw[cnt].sec] ^= 1;
            int cur = 0;
            for (int i = 2; i <= n; i++) {
                int sum = 0;
                for (int j = 1; j <= m; j++) {
                    sum += arr[i][j] != arr[1][j];
                }
                cur += min(sum, m - sum);
            }
            //cout << cur << endl;
            ans = min(ans, cur + cnt + 1);
        }
    //}
    cout << (ans > k ? -1 : ans);
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