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

const int N = 310;
int p_pow[N], pref[N], hs[N], f[N], dp[N], mod;

_ bool prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

_ void init_mod() {
    vector<int> kek;
    for (int i = 1e9;; i++) {
        if (prime(i)) {
            kek.pb(i);
            if (kek.size() == 20) {
                break;
            }
        }
    }
    int ind = Random() % 20;
    mod = kek[ind];
}

_ int get_len(int l, int r) {
    return (l > r ? 0 : pref[r] - pref[l - 1]);
}

_ int get_hash(int l, int r) {
    return ((((hs[r] - hs[l - 1] + 10 * mod) % mod) * p_pow[300 - r]) % mod);
}

_ void source() {
    init_mod();
    p_pow[0] = 1;
    for (int i = 1; i <= 300; i++) {
        p_pow[i] = (p_pow[i - 1] * P) % mod;
    }
    int n;
    cin >> n;
    int cnt= 0;
    map<string, int> was;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (!was[s]) {
            cnt++;
            was[s] = cnt;
        }
        pref[i] = pref[i - 1] + (int)s.size();
        f[i] = was[s];
    }
    for (int i = 1; i <= n; i++) {
        hs[i] = (hs[i - 1] + f[i] * p_pow[i]) % mod;
    }
    int ans = pref[n] + n - 1;
    for (int l = 1; l < n; l++) {
        for (int r = l; r < n; r++) {
            int len = r - l + 1;
            int chs = get_hash(l, r);
            bool t = false;
            for (int l2 = r + 1; l2 + len - 1 <= n; l2++) {
                int r2 = l2 + len - 1;
                if (get_hash(l2, r2) == chs) {
                    t = true;
                    break;
                }
            }
            if (!t) {
                continue;
            }
            int cur = pref[l - 1]+ l - 1 + len;
            for (int i = r + 1; i <= n; i++) {
                dp[i] = BINF;
            }
            dp[r] = 0;
            for (int i = r; i < n; i++) {
                dp[i + 1] = min(dp[i + 1], dp[i] + pref[i + 1] - pref[i] + 1);
                if (i + len <= n && chs == get_hash(i + 1, i + len)) {
                    dp[i + len] = min(dp[i + len], dp[i] + len + 1);
                }
            }
            ans = min(ans, cur + dp[n]);
        }
    }
    cout << ans;
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