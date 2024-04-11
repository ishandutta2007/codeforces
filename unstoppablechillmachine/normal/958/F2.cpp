#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
//using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

mt19937 Random(int(time(0)));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-9;

const int N = 2e5 + 10;
vector<int> arr[N];
int c[N], need[N], cur_cnt[N];
_ void source() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int color;
        cin >> color;
        arr[color].pb(i);
        c[i] = color;
    }
    int len = 0, mn = INF, r = 0;
    for (int i = 1; i <= m; i++) {
        int cnt;
        cin >> cnt;
        need[i] = cnt;
        len += cnt;
        if (arr[i].size() < cnt) {
            cout << -1;
            exit(0);
        }
    }
    for (int i = 1; i <= m; i++) {
        while (r < n && cur_cnt[i] < need[i]) {
            r++;
            cur_cnt[c[r]]++;
        }
        if (cur_cnt[i] < need[i]) {
            cout << -1;
            exit(0);
        }
    }
    mn = r;
    for (int i = 2; i <= n; i++) {
        cur_cnt[c[i - 1]]--;
        while (r < n && cur_cnt[c[i - 1]] < need[c[i - 1]]) {
            r++;
            cur_cnt[c[r]]++;
        }
        if (cur_cnt[c[i - 1]] >= need[c[i - 1]]) {
            mn = min(mn, r - i + 1);
        }
        else {
            break;
        }
    }
    cout << mn - len;
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