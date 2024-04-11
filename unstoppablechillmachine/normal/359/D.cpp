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

const int N = 3e5 + 10;
const int MX = 1e6 + 10;
const int LOG = 20;

int arr[N], val[N][LOG], have_del[MX], mx_pw[N], used[MX];

_ int check_gcd(int l, int r) {
    int k = mx_pw[r - l + 1];
    return __gcd(val[l][k], val[r - (1 << k) + 1][k]);
}

_ void source() {
    for (int i = 2; i <= 3e5; i++) {
        mx_pw[i] = mx_pw[i / 2] + 1;
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (!used[arr[i]]) {
            used[arr[i]] = true;
            for (int j = 1; arr[i] * j <= 1e6; j++) {
                have_del[arr[i] * j] = true;
            }
        }
        val[i][0] = arr[i];
    }
    for (int i = 1; i < LOG; i++) {
        int prev_step = 1 << (i - 1), lim = n - (1 << i) + 1;
        for (int j = 1; j <= lim; j++) {
            val[j][i] = __gcd(val[j][i - 1], val[j + prev_step][i - 1]);
        }
    }
    int best = -INF;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check_gcd(mid, i) % arr[i] == 0) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        int l2 = i, r2 = n + 1;
        while (r2 - l2 > 1) {
            int mid = (l2 + r2) / 2;
            if (check_gcd(i, mid) % arr[i] == 0) {
                l2 = mid;
            }
            else {
                r2 = mid;
            }
        }
        if (l2 - r > best) {
            best = l2 - r;
            ans = {r};
        }
        else if (l2 - r == best) {
            ans.pb(r);
        }
    }
    sort(all(ans));
    ans.rsz(unique(all(ans)) - ans.begin());
    cout << ans.size() << ' ' << best << endl;
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